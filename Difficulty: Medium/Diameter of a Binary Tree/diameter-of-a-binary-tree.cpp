class Solution {
  public:
    
    int maxDia = 0;
    
    int height(Node* root){
        if(!root) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        // update diameter
        maxDia = max(maxDia, left + right);
        
        return 1 + max(left, right);
    }
    
    int diameter(Node* root) {
        maxDia = 0;
        height(root);
        return maxDia;
    }
};