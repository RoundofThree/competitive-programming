#include <vector>
#include <string>

using namespace std; 

// Linear string pattern matching 
// O(n)
// Aho Coransick is a more general method of finding "equivalent nodes"

void fillLps(vector<int>& lps, string const& pattern) {
  int len = 0, i = 1;
  lps[0] = 0; 
  while (i < pattern.size()) {
    // if match 
    if (pattern[i] == pattern[len]) {
      ++len; 
      lps[i] = len; 
      ++i; 
    } else {
      if (len != 0) {
        len = lps[len-1];
      } else {
        lps[i] = 0; 
        ++i;
      }
    }
  }
}

vector<int> kmp(string const& text, string const& pattern) {
  if (pattern.size() == 0) return {};
  // preprocess pattern to store length of longest proper prefix that is also a suffix of pattern[:i+1]
  vector<int> lps(pattern.size(), 0); 
  fillLps(lps, pattern);
  // if match ++i, ++j 
  // if j == pattern.size() j = lps[j-1] 
  // if mismatch and j == 0, ++i 
  // if mismatch otherwise, j = lps[j-1] 
  vector<int> ret;
  int i = 0, j = 0; 
  while (i < text.size()) {
    if (j == pattern.size()) {
      ret.push_back(i-pattern.size());
      j = lps[j-1];
    }
    if (text[i] == pattern[j]) {
      ++i; ++j;
    } else if (text[i] != pattern[j] && j == 0) {
      ++i;
    } else {
      j = lps[j-1];
    }
  }
  return ret;
}