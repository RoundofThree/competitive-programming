#include <iostream>
#include <cstring>
#include <math.h>
using namespace std; 

#define ll long long
// https://atcoder.jp/contests/abc193/tasks/abc193_c
ll solve(ll n) {
    ll limit = sqrt(n);
	bool sieve[limit+1];  // segmentation fault for n=10^10 
  	memset(sieve, false, sizeof(sieve));
  	ll ret = 0;
  	for (ll i=2; i<=limit; ++i) {
      	if (sieve[i]) continue;
      	// find i^2, i^3, i^4... and add them to ret 
      	ll curr = i*i; 
      	while (curr <= n) {
          	if (curr < limit+1) sieve[curr] = true;
          	++ret; 
        	curr *= i;
        }
    }
  	return ret; 
}

int main() {
	ll n;
  	cin >> n; 
  
  	cout << n-solve(n) << "\n"; 
}