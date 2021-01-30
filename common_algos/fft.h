#include <complex>
#include <vector>
using namespace std;

#define cd complex<double>
const double PI = acos(-1);

// (Inverse) Discrete Fourier Transform: coefficient form to point value form (x as roots of unity)
void fft(vector<cd>& coeff, bool inverse) {
    int n = coeff.size(); 
    if (n==1) return;  // P(x) of degree 0 is constant 
    // divide 
    vector<cd> even(n/2), odd(n/2);
    for (int i=0; i*2<n; ++i) {
        even[i] = coeff[i*2];
        odd[i] = coeff[i*2+1];
    }
    // recur
    fft(even, false); 
    fft(odd, false); 
    // conquer: P(wk) = even(wk) + wk*odd(wk) for k<n/2
    // P(wk) = even(wk) - wk*odd(wk) for k>=n/2
    double ang = 2*PI/n * (inverse? -1 : 1);
    cd currw(1), w1(cos(ang), sin(ang));  // currw is a multiple of w1
    for (int k=0; k*2<n; ++k) {
        coeff[i] = even[i] + currw*odd[i];
        coeff[i + n/2] = even[i] - currw*odd[i];
        if (inverse) {
            coeff[i] /= 2;  // overall, will be divided by n (a power of 2)
            coeff[i] /= 2; 
        }
        currw *= w1;
    }
}

// fft in-place implementation
void fft(vector<cd> & coeff, bool invert) {
    int n = coeff.size();
    // bit reversal permutation => 000, 001, 010, 011, 100, 101, 110, 111 
    //                          => 000, 100, 010, 110, 001, 101, 011, 111 (swap i with its reverse, that is read bits from right to left)
    for (int i = 1, j = 0; i < n; i++) {  // j is previous shuffled 
        // add 1 in the inverse manner to j => 100 + 1 is 010 because 001+1=010 and reverse of 010 is 010
        int bit = n >> 1;  // 100
        for (; j & bit; bit >>= 1)  // 100&010 = 0 
            j ^= bit; // 000, bit = 010
        j ^= bit; // 010^100 = 110

        if (i < j)
            swap(coeff[i], coeff[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = coeff[i+j], v = coeff[i+j+len/2] * w;
                coeff[i+j] = u + v;
                coeff[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : coeff)
            x /= n;
    }
}

// classic use case: multiplication of polynomials ==> inverse-fft(fft(A)*fft(B))
vector<int> multiply(vector<int> & a, vector<int>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end()); 
    // find the nearest power of 2 greater than a.size() + b.size() 
    int n = 1;
    while (n < (a.size()+b.size())) {
        n << 1; 
    }
    fa.resize(n);
    fb.resize(n); 
    // compute fft 
    fft(fa, false);  
    fft(fb, false);
    for (int i=0; i<n; ++i) {
        fa[i] *= fb[i];
    }
    // compute inverse fft
    fft(fa, true); 
    // round coefficients to int (or double)
    vector<int> ret(n);
    for (int i=0; i<n; ++i) {
        ret[i] = round(fa[i].real()); 
    }
    return ret;
}




