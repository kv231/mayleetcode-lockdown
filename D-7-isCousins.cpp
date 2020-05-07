/*Cousins in Binary Tree
Solution
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.



Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false


Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int level(TreeNode *root,int x,int lev){
        if(!root){
            return -1;
        }
        if(root->val==x){
            return lev;
        }
        int left=level(root->left,x,lev+1);
        if(left!=-1){
            return left;
        }
        int right=level(root->right,x,lev+1);
        return right;
    }
    bool is_same_parent(TreeNode *root,int x,int y){
        if(!root){
            return false;
        }
        if(root->left&&root->right){
            if((root->left->val==x&&root->right->val==y)||(root->right->val==x&&root->left->val==y))
                return true;
        }
        return is_same_parent(root->left,x,y)||is_same_parent(root->right,x,y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if((level(root,x,0)==level(root,y,0))&&(!is_same_parent(root,x,y))){
            return true;
        }
        return false;
    }
};
