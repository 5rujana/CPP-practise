// problem statement: https://leetcode.com/problems/diameter-of-binary-tree/description/
/*

What is diametr of tree?
    The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root

*/

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode * left;
    TreeNode * right;
    TreeNode(){
        data = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int data){
        this-> data = data;
        this->left = NULL;
        this-> right = NULL;
    }
};

class Solution{
    public:
        int height(TreeNode * root, int &diameter){
            if(root == NULL) return 0;
            int lh = height(root->left,diameter);
            int rh = height(root-> right,diameter);
            diameter = max(diameter,lh+rh);
            return 1+max(lh,rh);
        }
        int findDiameter(TreeNode * root){
            int diameter = 0;
            height(root,diameter);
            return diameter;
        }
};

int main(){
    Solution sl;
    TreeNode * root = new TreeNode(9);
    root-> left = new TreeNode(10);
    root-> right = new TreeNode(11);
    root-> left->left = new TreeNode(12);
    root-> left->right = new TreeNode(13);
    root-> right->left = new TreeNode(14);
    root-> right-> right = new TreeNode(15);
    root-> left->left->left = new TreeNode(16);
    root-> left->left->right = new TreeNode(17);   
    root-> left->right-> left = new TreeNode(18);
    root-> left->right->right = new TreeNode(19);
    root-> right->left->left = new TreeNode(20);
    root-> right->left->right = new TreeNode(21);   
    root-> right-> right->left = new TreeNode(22);
    root-> right-> right->left = new TreeNode(23);
    int diameter = sl.findDiameter(root);
    cout<< diameter << endl;
    return 0;
}