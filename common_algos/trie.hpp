#include <vector> 
#include <string>
#include <array>

using namespace std;


// Aho-Corasick algorithm 
// Uses: pattern matching with different words to match, fgrep
// Remember that KMP is bettern suited if there's only one keyword 

// Build a DFA that has three functions: 
// 1. Go to: (state, character) -> state 
// 2. Failure (suffix link): (state) -> state, called when there are no edges goto 
// 3. Output: state -> bitmap of indexes of keywords that match the text until current state 

const int K = 26;

struct Vertex {
  int next[K];  // transitions
  long long leaf = 0;   // bitmap represent the idx of  
  int p = -1; // parent node index 
  char pch;  // parent char 
  int link = -1; // suffix link 
  int go[K];  // memoization 

  Vertex(int p=-1, char c='$') : p(p), pch(c) {
    fill(begin(next), end(next), -1);
    fill(begin(go), end(go), -1);
  }
};

class Trie {
public:
  vector<Vertex> t;  // the tree 
  vector<long long> out;   // bitmap of matching strings, each bit represents idx of matched string 

  Trie() : t(1), out(1) {}

  void add_string(string const& s, int j) {
    // start from root
    int v = 0; 
    for (char c : s) {
      if (t[v].next[c-'a'] == -1) {
        // add a new node 
        t[v].next[c-'a'] = t.size();  
        t.emplace_back(v, c);
        out.push_back(-1); // to indicate that it has not been computed
      }
      v = t[v].next[c-'a'];
    }
    t[v].leaf |= (1LL << j);
  }

  int go(int v, char c); 

  int get_link(int v) {
    if (t[v].link == -1) {
      if (v == 0|| t[v].p == 0) {
        // if v is root or its parent is root 
        t[v].link = 0; 
      } else {
        t[v].link = go(get_link(t[v].p), t[v].pch);
      }
    }
    return t[v].link;
  }

  int go(int v, char c) {
    if (t[v].go[c-'a'] == -1) {
      if (t[v].next[c-'a'] != -1) {
        t[v].go[c-'a'] = t[v].next[c-'a'];
      } else {
        t[v].go[c-'a'] = v==0? 0 : go(get_link(v), c);
      }
    }
    return t[v].go[c-'a'];
  }

  // Return the bitmap representing the idx of string matches 
  int match(int v) {
    if (v == 0) return 0;
    // lazily compute out[]
    if (out[v] != -1) return out[v]; 
    return out[v] = t[v].leaf | match(get_link(v));
  }

};

// Classical problem 

// O(n + m + z), where z is the number of occurrences 
// 1. Find all strings and found indexes of each given a set of strings
// and a text 

vector<vector<int>> search(vector<string>& words, string& text) {
  vector<vector<int>> ret(words.size());
  // build the Trie 
  Trie t;
  int x = 0;
  for (string& w : words) t.add_string(w, x++); 
  // initialize to root 
  int curr = 0; 
  // traverse through the text 
  for (int i=0; i<text.size(); ++i) {
    curr = t.go(curr, text[i]);
    if (t.match(curr) == 0) continue;  // no matching strings 
    for (int j=0; j<words.size(); ++j) {  // optimize by deleting the last bit until 0 (i = i & (i-1))
      if (t.match(curr) & (1 << j)) {
        ret[j].push_back(i-words[j].size()+1);
      }
    }
  }
  return ret;
}

// 2. Find the lexicographical smallest string of a given length that doesn't match any given strings (DFS)

// 3. Find the shortest string containing all given strings (BFS)

// 4. Find the lexicographical smallest string of length L containing k strings (DFS)

// Additional, implement fgrep 
