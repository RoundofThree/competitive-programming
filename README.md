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
| Dijkstra algorithm | [dijkstra.h](common_algos/dijkstra.h) | Find the shortest path and its distance from a start node to a final node. | 
| Binary exponentiation | [binpow.h](common_algos/binpow.h) | Fast exponentiation of numbers or matrices (transformations). Find the number of paths of length k in an unweighted undirected graph. |
| Linear diophantine equations | [diophantine_equations.h](common_algos/diophantine_equations.h) | Find integer solutions `<x, y>` to `ax+yb=c`. |
| Minimum stack/queue | [minimum_stack_queue.h](common_algos/minimum_stack_queue.h) | Find the minimum in a stack/queue anytime in O(1). Find the minimum for all subarrays of length k. | 
| Gauss-Jordan elimination | [slae.h](common_algos/slae.h) | Find solution(s) to a System of Linear Algebraic Equations. |
| Tree traversal | [tree_traversal.h](common_algos/tree_traversal.h) | Recursive and iterative binary tree traversal: preorder, inorder and postorder. | 
| Reservoir Sampling | [reservoir_sampling.h](common_algos/reservoir_sampling.h) | Choose k random elements from a large stream in one traversal. Each element has probability `k/n` to be in the reservoir. |
| Union Find | [union_find.h](common_algos/union_find.h) | Find connected components in a graph. Detect cycles in a graph. |
| Sorting algorithms | [sort.h](common_algos/sort.h) | Radix sort, counting sort, shell sort, merge sort, quick sort, heap sort, selection sort, insertion sort, bubble sort. | 

<!-- Maybe a gh page -->
<!-- Find the top k elements in unsorted array, all methods and complexities: https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/ -->


