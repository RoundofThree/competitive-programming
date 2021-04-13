#include <vector>
#include <tuple>

// The extended Euclidean algorithm also calculates the Diophantine solution
// the x and y get the coefficients to a and b
// ax + by = gcd(a, b)
// where x and y can be negative (but not both)
// here we assume a >= b 
int gcd(int a, int b, int& x, int& y) {
    if (b==0) {
        x = 1; 
        y = 0;
        return a; 
    }
    int x1, y1;
    int d = gcd(b, a%b, x1, y1);
    x = y1;  // key
    y = x1 - y1 *(a/b); // key 
    return d; 
}

int itgcd(int a, int b, int&x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b; 
    while (b1!=0) {
        int q = a1/b1;  // floor 
        std::tie(x, x1) = std::make_tuple(x1, x-q*x1);
        std::tie(y, y1) = std::make_tuple(y1, y-q*y1);
        std::tie(a1, b1) = std::make_tuple(b1, a1-q*b1); 
    }
    return a1; 
}