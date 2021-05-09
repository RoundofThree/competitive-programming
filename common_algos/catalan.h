#include "nCk.h"

#define ul unsigned long int 
#define uint unsigned int

// O(n) 
ul catalan(uint n) {
    ul c = binomial(2*n, n);
    return c/(n+1);
}

// Applications in combinatorics:

// 1. Number of BST given n nodes 