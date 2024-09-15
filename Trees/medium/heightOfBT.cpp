// problem statement: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
#include<bits/stdc++.h>
using namespace std;

/*
intutuion: 
we'll implement level order traversal using queue and increment cntr
*/ 

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
    int height(TreeNode * root){
        if(root == NULL) return 0;
        int lh = height(root->left); // finding max depth of left subtree
        int rh = height(root->right); // finding max depth of right subtree
        return 1+max(lh,rh);
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
    int height = sl.height(root);
    cout<<height << endl;
    return 0;
}