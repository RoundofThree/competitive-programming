#include <stack>
#include <vector> 

using namespace std;

// Naive tree node implementation 
template<class T>
class TreeNode {
public:
    T val;
    TreeNode* left;
    TreeNode* right; 
    TreeNode(int valIn) : val(valIn), left(nullptr), right(nullptr) {} 
    TreeNode(int valIn, TreeNode* leftIn, TreeNode* rightIn) : val(valIn), left(leftIn), right(rightIn) {} 
};

// preorder recursive
vector<int> preorderRec(TreeNode<int>* root) {
    vector<int> ret;
    preorderRecAux(root, ret);
    return ret;
}
// modify the ret array 
void preorderRecAux(TreeNode<int>* root, vector<int>& ret) {
    if (!root) return; 
    ret.push_back(root->val);
    preorderRecAux(root->left, ret);
    preorderRecAux(root->right, ret);
}

// preorder iterative: 1 stack  
vector<int> preorderIt(TreeNode<int>* root) {
    stack<TreeNode<int>*> st; 
    vector<int> ret;
    st.push(root);
    while (!st.empty()) {
        TreeNode<int>* curr = st.top();
        st.pop();
        ret.push_back(curr->val);
        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
    return ret;
}

// inorder recursive 
vector<int> inorderRec(TreeNode<int>* root) {
    vector<int> ret; 
    inorderRecAux(root, ret);
    return ret;
}

void inorderRecAux(TreeNode<int>* root, vector<int>& ret) {
    if (!root) return; 
    inorderRecAux(root->left, ret);
    ret.push_back(root->val);
    inorderRecAux(root->right, ret);
}

// VERIFY 
// inorder iterative: 1 stack  
vector<int> inorderIt(TreeNode<int>* root) {
    stack<TreeNode<int>*> st; 
    vector<int> ret;
    while (root) {
        st.push(root);
        root = root->left; 
    }
    while (!st.empty()) {
        TreeNode<int>* curr = st.top(); st.pop(); 
        ret.push_back(curr->val); 
        if (curr->right) {
            curr = curr->right;
            while (curr) {
                st.push(curr);
                curr = curr->left; 
            }
        }
    }
    return ret; 
}

// postorder recursive 
vector<int> postorderRec(TreeNode<int>* root) {
    vector<int> ret; 
    postorderRecAux(root, ret);
    return ret;
}

void postorderRecAux(TreeNode<int>* root, vector<int>& ret) {
    if (!root) return; 
    postorderRecAux(root->left, ret); 
    postorderRecAux(root->right, ret);
    ret.push_back(root->val);
}

// postorder iterative: 2 stacks (1 used to reverse)
vector<int> postorderIt(TreeNode<int>* root) {
    stack<TreeNode<int>*> st1, st2;
    vector<int> ret; 
    st1.push(root); 
    while (!st1.empty()) {
        TreeNode<int>* curr = st1.top(); st1.pop(); 
        st2.push(curr);
        if (curr->left) {
            st1.push(curr->left);
        }
        if (curr->right) {
            st1.push(curr->right);
        }
    }
    while (!st2.empty()) {
        ret.push_back(st2.top()->val);
        st2.pop(); 
    }
    return ret;
}
