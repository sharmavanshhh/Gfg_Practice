/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    // Function to count the number of leaf nodes in a binary tree.
    void traverse(Node* root, int& count){
        if(!root){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            count++;
        }
        traverse(root->left, count);
        traverse(root->right, count);
    }
    
    int countLeaves(Node* root) {
        // write code here
        int count = 0;
        traverse(root, count);
        return count;
    }
};