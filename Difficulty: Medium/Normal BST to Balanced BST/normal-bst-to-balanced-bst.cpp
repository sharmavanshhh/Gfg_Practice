/*Structure of the Node of the BST is as
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {

  public:
    void inorder(Node* root, vector<int>& nums){
        if(!root) return;
        
        inorder(root->left, nums);
        nums.push_back(root->data);
        inorder(root->right, nums);
    }
    
    Node* build(int left, int right, vector<int>& nums){
        if(left > right) return NULL;
        
        int mid = left + (right - left) / 2;
        
        Node* root = new Node(nums[mid]);
        
        root->left = build(left, mid - 1, nums);
        root->right = build(mid + 1, right, nums);
        
        return root;
    }
  
    Node* balanceBST(Node* root) {
        // Code here
        
        vector<int> nums;
        
        inorder(root, nums);
        
        return build(0, nums.size() - 1, nums);
    }
};