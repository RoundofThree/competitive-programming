// ax + by = c, find a and y 

#include <tuple>
#include <algorithm>
#include <utility>

using namespace std;

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

// no solution if c is not divisible by gcd(a, b)
// find any solution
bool any_solution(int a, int b, int c, int& x, int& y, int& g) {
    g = itgcd(abs(a), abs(b), x, y);
    if (c % g) return false;  // c not divisible by g
    x *= c / g;   // scale solution ax+by=g to a(x*c/g)+b(y*c/g) = c
    y *= c / g;
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return true;
}



// find all solutions
// x = x0 + k*(b/g)
// y = y0 - k*(a/g)
// in the interval x E [minx, maxx] and y E [miny, maxy] and return the number of solutions 
// note that solutions to ax+by=c is the same as to (a/g)x+(b/g)y=c/g
void shift_solution(int& x, int& y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!any_solution(a, b, c, x, y, g)) {
        return 0;
    }
    // factor to be added or substracted k times
    a /= g; 
    b /= g;
    // signs 
    int sign_a = a>0? 1 : -1;
    int sign_b = b>0? 1 : -1;
    // shift to satisfy minx 
    shift_solution(x, y, a, b, (minx-x)/b);  // the shift is derived from x+b*cnt >= minx
    if (x < minx) shift_solution(x, y, a, b, sign_b);
    if (x > maxx) return 0; // no solutions
    int lx1 = x;  // solutions of x start from lx1 

    shift_solution(x, y, a, b, (maxx-x)/b);
    if (x > maxx) shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny-y)/a);
    if (y < miny) shift_solution(x, y, a, b, -sign_a);
    if (y > maxy) return 0;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy-y)/a);
    if (y > maxy) shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2) swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx) return 0;
    return (rx - lx) / abs(b) + 1;
}