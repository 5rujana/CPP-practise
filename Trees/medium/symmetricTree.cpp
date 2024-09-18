// problem statement: https://leetcode.com/problems/symmetric-tree/description/
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
    bool isSymmerticTree(TreeNode * root){
        return isMirror(root->left,root->right);
    }

    bool isMirror(TreeNode * n1,TreeNode * n2){
        if(n1==NULL && n2 == NULL) return true;
        if(n1==NULL || n2 == NULL) return false;
        return n1->data == n2->data && isMirror(n1->left,n1->right) && isMirror(n2->left,n2->right);
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
    root-> right-> right->right = new TreeNode(23);
    bool isSymetric = sl.isSymmerticTree(root);
    if(isSymetric) cout<<"true"<< endl;
    else cout<< " false "<<endl;

    return 0;
}