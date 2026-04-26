/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void traverse(Node* root, vector<int>& nodes){
        if(root == nullptr) return;
        
        traverse(root->left, nodes);
        nodes.push_back(root->data);
        traverse(root->right, nodes);
    }
  
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> nodes;
        traverse(root, nodes);
        return nodes;
    }
};