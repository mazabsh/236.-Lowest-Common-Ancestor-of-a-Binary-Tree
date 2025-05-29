#include<iostream> 
using namespace std; 

struct TreeNode{
       int val; 
       TreeNode* left; 
       TreeNode* right; 
       TreeNode(int x): val(x), left(NULL), right(NULL){}
};
class Solution{
public: 
      TreeNode* lowestCommonAnsector(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL|| root==p || root==q) return root; 
        TreeNode* left = lowestCommonAnsector(root->left,p,q); 
        TreeNode* right =lowestCommonAnsector(root->right, p,q); 
        if(left==NULL) return right; 
        else if(right==NULL) return left; 
        else return root; 
      }
};
int main(){
  TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left; // Node 5
    TreeNode* q = root->left->right->right; // Node 4
    Solution sol; 
    TreeNode* LCA=sol.lowestCommonAnsector(root, p,q); 
    if(LCA) cout<< LCA->val << endl; 
    else cout <<"there is no common ansector" << endl; 
    return 0; 
}
