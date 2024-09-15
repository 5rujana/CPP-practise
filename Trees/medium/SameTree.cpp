// problem statement: https://leetcode.com/problems/same-tree/description/

/*

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

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
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution{
    public:
    bool isSameTree(TreeNode * root1, TreeNode * root2){
        if(root1==NULL && root2 == NULL) return true;

        if(root1!= NULL && root2!= NULL && root1-> data == root2-> data){
            return isSameTree(root1->left,root2->left) && isSameTree(root1->right,root2->right);
        }

        return false;
    }
};

int main(){
    Solution sl;
    TreeNode * root1 = new TreeNode(9);
    root1-> left = new TreeNode(10);
    root1-> right = new TreeNode(11);
    root1-> left->left = new TreeNode(12);
    root1-> left->right = new TreeNode(13);
    root1-> right->left = new TreeNode(14);
    root1-> right-> right = new TreeNode(15);
    root1-> left->left->left = new TreeNode(16);
    root1-> left->left->right = new TreeNode(17);   
    root1-> left->right-> left = new TreeNode(18);
    root1-> left->right->right = new TreeNode(19);
    root1-> right->left->left = new TreeNode(20);
    root1-> right->left->right = new TreeNode(21);   
    root1-> right-> right->left = new TreeNode(22);
    root1-> right-> right->left = new TreeNode(23);

    TreeNode * root2 = new TreeNode(9);
    root2-> left = new TreeNode(10);
    root2-> right = new TreeNode(11);
    root2-> left->left = new TreeNode(12);
    root2-> left->right = new TreeNode(13);
    root2-> right->left = new TreeNode(14);
    root2-> right-> right = new TreeNode(15);
    root2-> left->left->left = new TreeNode(16);
    root2-> left->left->right = new TreeNode(17);   
    root2-> left->right-> left = new TreeNode(18);
    root2-> left->right->right = new TreeNode(19);
    root2-> right->left->left = new TreeNode(20);
    root2-> right->left->right = new TreeNode(21);   
    root2-> right-> right->left = new TreeNode(22);
    root2-> right-> right->left = new TreeNode(23);
    
    bool sameTree = sl.isSameTree(root1,root2);
    if(sameTree) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}