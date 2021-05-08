#include <vector> 

using namespace std;

// Restrictions:
// You are only allowed to traverse the stream one time 
// The stream size is so large that you dont know the size of the stream

vector<int> reservoir_sampling(vector<int> stream, int k) {
    vector<int> reservoir(k, 0);
    // 1. 
    for (int i=0; i<k; ++i) {
        reservoir[i] = stream[i];
    }
    // random seeding 
    srand(time(NULL));
    // 2. !!! HERE I AM USING STREAM.SIZE() BUT THIS CAN BE ONLINE SETTING
    for (int i=k; i<stream.size(); ++i) {
        int j = rand() % (i+1);
        if (j < k) reservoir[j] = stream[i];
    }
    return reservoir;
}

// EXERCISE: prove mathematically that the probability is k/stream.size() 
// P = probability of being sampled (k/i) * probability of not being replaced (i/n)