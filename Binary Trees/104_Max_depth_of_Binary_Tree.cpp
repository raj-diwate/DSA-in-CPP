class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0 ;
        }
   int leftht = maxDepth(root->left);
   int rightht = maxDepth(root->right);

   return max(leftht,rightht)+1;

    }
};
