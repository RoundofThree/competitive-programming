#include <utility>

using namespace std;

// recursive
int gcd(int a, int b) {
    return b? gcd(b, a%b) : a;
}

// iterative
int itgcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// lcm 
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

// get optimized gcd in <numeric> std::gcd for C++17 
// or __gcd in <algorithm> 