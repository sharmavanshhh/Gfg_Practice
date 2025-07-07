/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.
class Solution {
  public:
    void traverse(Node* root, int& sum){
        if(!root){
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            sum += root->data;
        }
        traverse(root->left, sum);
        traverse(root->right, sum);
    }
    
    int leafSum(Node* root) {
        // write code here
        int sum = 0;
        traverse(root, sum);
        return sum;
    }
};