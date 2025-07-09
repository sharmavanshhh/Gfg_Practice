/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int data) {
        data = data;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node* root){
        if(!root->left && !root->right){
            return true;
        }
        return false;
    }
    void leftPath(Node* root, vector<int>& ans){
        Node* curr = root->left;
        while(curr){
            if(!isLeaf(curr)){
                ans.push_back(curr->data);
            }
            if(curr->left){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
    }
    void addLeaves(Node* root, vector<int>& ans){
        if(!root){
            return;
        }
        if(isLeaf(root)){
            ans.push_back(root->data);
            return;
        }
        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }
    void rightPath(Node* root, vector<int>& ans){
        vector<int> temp;
        Node* curr = root->right;
        while(curr){
            if(!isLeaf(curr)){
                temp.push_back(curr->data);
            }
            if(curr->right){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        reverse(temp.begin(), temp.end());
        for(int i : temp){
            ans.push_back(i);
        }
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if(!root){
            return ans;
        }
        if(!isLeaf(root)){
            ans.push_back(root->data);
        }
        
        leftPath(root, ans);
        addLeaves(root, ans);
        rightPath(root, ans);
    }
};