#include <stack>
#include <vector>

using namespace std;

#define pii pair<int,int>
#define ptt pair<T, T>

// Find the smallest element present in a stack or queue in O(1)
// T must be comparable aka define operator< 
template<class T>
class MinStack {
private:
    stack<ptt> st;
public:
    void push(T e) {
        T new_min = st.empty() ? e : min(e, st.top().second);
        st.push({e, new_min});
    }

    void pop() {
        st.pop();
    }

    T top() {
        return st.top().first;
    }

    T minimum() {
        return st.top().second;
    }
};

// queue 1: if min queue,
// add: remove all elements greater than x in the tail and then insert x to the tail
// remove: remove head iff the head is the element to be removed

// queue 2: same as queue 1 but no need to know the value of the element to be removed
template<class T>
class MinQueue2 {
private:
    deque<pair<T, int>> dq;
    int addIdx, removeIdx;

public:
    MinQueue2() : addIdx(0), removeIdx(0) {}
    void push(T e) {
        while (!dq.empty() && dq.back().first > e) dq.pop_back();
        dq.push_back({e, addIdx});
        ++addIdx;
    }

    void pop() {
        if (!dq.empty() && dq.front().second == removeIdx) {
            dq.pop_front();
        }
        ++removeIdx;
    }

    T minimum() {
        return dq.front().first;
    }

    // cannot implement top() because elements are erased, need an auxiliary queue 
};

// queue 3: simulate a queue with two stacks 
// because moving elements from one stack to another and back restores the order 
template<class T>
class MinQueue3 {
private:
    // push to s1
    // pop from s2
    stack<ptt> s1, s2;

public:
    MinQueue3() = default;
    void push(T e) {
        T minimum = s1.empty()? e : min(e, s1.top().second);
        s1.push({e, minimum});
    }

    void pop() {
        if (s2.empty()) {
            // move from s1
            while (!s1.empty()) {
                T e = s1.top().first;
                T mini = s2.empty()? e : min(e, s2.top().second);
                s1.pop();
                s2.push({e, mini});
            }
        }
        // pop from s2
        s2.pop();
    }

    T minimum() {
        if (s1.empty() || s2.empty()) {
            return s1.empty()? s2.top().second : s1.top().second;
        } else {
            return min(s1.top().second, s2.top().second);
        }
    }

    T top() {
        if (s2.empty()) {
            // move from s1
            while (!s1.empty()) {
                T e = s1.top().first;
                T mini = s2.empty()? e : min(e, s2.top().second);
                s1.pop();
                s2.push({e, mini});
            }
        }
        return s2.top().first;
    }
};

// Applications:

// Find the minimum for all subarrays of fixed length 
vector<int> minSubarrays(vector<int>& arr, int M) {
    // fill with M 
    MinQueue3<int> dq;
    size_t idx = 0;
    while (idx < M) {
        dq.push(arr[idx]);
        ++idx;
    }
    vector<int> ret;
    ret.push_back(dq.minimum());
    dq.pop();
    while (idx < arr.size()) {
        dq.push(arr[idx]);
        ++idx;
        ret.push_back(dq.minimum());
        dq.pop();
    }
    return ret;
}

