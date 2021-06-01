#include <vector>
#include <algorithm>

using namespace std; 

// radix sort 
// Time O((n+b)*log_b(k)), where b is the base. If b = n, this can be seen as O(n)
// Space O(n)
void radix_count_sort(vector<int>& arr, int exp, int b=10);

void radix_sort(vector<int>& arr) {
  int maxi = *max_element(arr.begin(), arr.end());
  for (int exp=1; maxi/exp>0; exp *= 10) {
    // countsort based on the digit at exp 
    radix_count_sort(arr, exp);
  }
}

void radix_count_sort(vector<int>& arr, int exp, int b=10) {
  vector<int> count(b, 0);
  for (int i : arr) {
    count[(i/exp)%10]++;
  }
  for (int i=1; i<b; ++i) {
    count[i] += count[i-1];
  }
  vector<int> ret(arr.size(), 0); 
  for (int i=arr.size()-1; i>=0; --i) {
    ret[count[(arr[i]/exp)%b]-1] = arr[i];
    count[(arr[i]/exp)%b]--;
  }
  arr = ret;
}


// counting sort:
// Time O(n+k)
// Space O(max(arr))
// stable sort 
void counting_sort(vector<int>& arr) {
  int maxi = *max_element(arr.begin(), arr.end());
  vector<int> count(maxi+1, 0); 
  for (int i : arr) {
    count[i]++; 
  }
  // cumulative frequency 
  for (int i=1; i<count.size(); ++i) {
    count[i] += count[i-1]; 
  }
  // stable sort must start from the end 
  vector<int> ret(arr.size()); 
  for (int i=arr.size()-1; i>=0; --i) {
    ret[count[arr[i]]-1] = arr[i];
    --count[arr[i]]; 
  }
  // copy to arr
  arr = ret; 
  return;
}

// shell sort
// A variation of insertion sort, by making h-sorted sublists 
// Time O(n^2)
// Still not very familiar to this!
void shell_sort(vector<int>& arr) {
  int n = arr.size();
  for (int gap=n/2; gap>0; gap/=2) {
    for (int i=gap; i<n; ++i) {
      int tmp = arr[i];
      int j = i;
      while (j >= gap && arr[j-gap] > tmp) {
        arr[j] = arr[j-gap];
        j -= gap;
      }
      arr[j] = tmp;
    }
  }
}

// merge sort 
// Time O(nlogn)
// Space O(n) 
// Better than quick sort for huge data stored on external storage, when random access is expensive 
void merge(vector<int>& arr, int start, int mid, int end);
void merge_sort(vector<int>& arr, int start=0, int end=-1) {
  if (end == -1) end = arr.size()-1;
  if (start >= end) return;
  int mid = start + (end - start)/2; 
  merge_sort(arr, start, mid);
  merge_sort(arr, mid+1, end);
  merge(arr, start, mid, end);
}

void merge(vector<int>& arr, int start, int mid, int end) {
  vector<int> old(arr.begin()+start, arr.begin() + end+1);
  int curr = start; 
  int i=0, j=mid+1-start;
  while (i<=mid-start && j<=end-start) {
    if (old[i] <= old[j]) {
      arr[curr] = old[i];
      ++i; 
    } else {
      arr[curr] = old[j]; 
      ++j; 
    }
    ++curr;
  }
  while (i<=mid-start) {
    arr[curr++] = old[i++];
  }
  while (j<=end-start) {
    arr[curr++] = old[j++];
  }
}

// quick sort
// Time O(nlogn) best and average, O(n^2) worst, tail recursive 
// Space in place
// Better than merge sort when random access is not expensive, eg. arrays 
// For 3-three way quick-sort, maintain a mid partition of elements equal to the pivot 
int partition(vector<int>& arr, int start, int end);
void quick_sort(vector<int>& arr, int start=0, int end=-1) {
  if (end == -1) end = arr.size()-1; 
  if (start < end) {
    int pivot = partition(arr, start, end);
    quick_sort(arr, start, pivot-1);
    quick_sort(arr, pivot+1, end);
  }
}

#include <ctime>

// Choose a random pivot and partition using Hoare
int partition(vector<int>& arr, int start, int end) {
  srand(time(NULL));
  int random = start + rand() % (end - start);
  swap(arr[random], arr[start]);
  int pivot = arr[start]; 
  int i= start-1, j = end+1; 
  while (true) {
    do {
      ++i; 
    } while (arr[i] < pivot);
    do {
      --j;
    } while (arr[j] > pivot); 
    if (i >= j) return j; 
    swap(arr[i], arr[j]);
  }
}

// bucket sort 
// n is number of buckets. 
void bucket_sort(vector<double>& arr, int n) {
  double maxd = *max_element(arr.begin(), arr.end()); 
  double mind = *min_element(arr.begin(), arr.end()); 
  // range of buckets 
  double range = (maxd - mind) / (double) n; 
  // buckets 
  vector<vector<double>> buckets(n);
  for (int i=0; i<arr.size(); ++i) {
    double diff = (arr[i]-mind)/range - (int)((arr[i]-mind)/range);
    if (diff == 0 && arr[i] != mind) {
      buckets[(int)((arr[i]-mind)/range) - 1].push_back(arr[i]);
    } else {
      buckets[(int)((arr[i]-mind)/range)].push_back(arr[i]);
    }
  }
  // sort each bucket using insertion sort. I'm being lazy here hh
  for (auto& b : buckets) sort(b.begin(), b.end());
  // place them back to arr
  int curr = 0; 
  for (auto& b : buckets) {
    for (double d : b) {
      arr[curr++] = d;
    }
  }
}

// bubble sort 
// O(n^2) 
void bubble_sort(vector<int>& arr) {
  for (int i=0; i<arr.size()-1; ++i) {
    for (int j=0; j<arr.size()-1-i; ++j) {
      if (arr[j] > arr[i]) swap(arr[j], arr[i]);
    }
  }
}

// comb sort
// improved bubble sort with a larger gap 
void comb_sort(vector<int>& arr);


// insertion sort 
void insertion_sort(vector<int>& arr) {
  for (int i=1; i<arr.size(); ++i) {
    int key = arr[i];
    int j = i-1; // find lower_bound(arr[:i-1], key)
    while (j >= 0 && arr[j] > key) {
      arr[j+1] = arr[j];  // move forwards 
      --j;
    }
    arr[j+1] = key;
  }
}

// selection sort
void selection_sort(vector<int>& arr) {
  for (int i=0; i<arr.size()-1; ++i) {
    int min_idx = i; 
    for (int j=i-1; j<arr.size(); ++j) {
      if (arr[j] < arr[min_idx]) min_idx = j;
    }
    swap(arr[min_idx], arr[i]);
  }
}


// heap sort 
// O(nlogn)
// still not very familiar with this! 
void heapify(vector<int>& arr, int root) {
  int largest = root; 
  int left = 2*root + 1; 
  int right = 2*root + 2;
  if (left < arr.size() && arr[left] > arr[largest]) {
    largest = left; 
  }
  if (right < arr.size() && arr[right] > arr[largest]) {
    largest = right;
  }
  if (largest != root) {
    // a change happened 
    swap(arr[root], arr[largest]); 
    heapify(arr, largest);
  } 
}

void heap_sort(vector<int>& arr) {
  for (int i=arr.size()/2-1; i>=0; --i) {
    heapify(arr, i);
  }
  for (int i=arr.size()-1; i>0; --i) {
    swap(arr[0], arr[i]);  // swap the root node with the last node to trigger heapify 
    heapify(arr, 0);
  }
}