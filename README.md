## My CP resources

Common Data Structures and Algorithms (implemented in C++):

| Name | File | Classic use case |
| -- | -- | -- |
| Fast Fourier Transform | [fft.h](common_algos/fft.h) | Calculate multiplication of two polynomials (in coefficient form) | 
| Kadane algorithm | [kadane.h](common_algos/kadane.h) | Max subarray sum |
| Fenwick tree or BIT | [fenwick.h](common_algos/fenwick.h) | Update-fast range sum |
| nCk mod p | [nCk.h](common_algos/nCk.h) | n Choose k mod p where p is prime optimised using Fermat's little theorem and Lucas theorem for divide and conquer. |
| DSU | [dsu.h](common_algos/dsu.h) | Kruskal's algorithm for MST (to evaluate the existence of cycles). Find number of connected components in a matrix (image). |
| String hash | [string_hash.h](common_algos/string_hash.h) | Rabin-Karp pattern matching algorithm for strings. Find the number of different substring in a string |
| Sieve of Eratosthenes | [sieve_eratosthenes.h](common_algos/sieve_eratosthenes.h) | Find all prime numbers in a range. The concept of sieving can be applied to lot of DP problems though. | 
| Euclidean algorithm | [extended_euclidean.h](common_algos/extended_euclidean.h) | Find `gcd(a, b)` while also solving the diophantine equation `ax + by = gcd(a, b)`. To find GCD, you may as well use the built-in `__gcd(a, b)` where a and b are integers. |
| Dijkstra algorithm | TBD | TBD | 


