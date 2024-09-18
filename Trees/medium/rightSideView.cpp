// problem statement : https://leetcode.com/problems/binary-tree-right-side-view/description/
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
        vector<int> rightSideview(TreeNode * root){
            vector<int> res;
            recursionRight(root, 0, res);
            return res;
        }
        void recursionRight(TreeNode * root, int level, vector<int>& res){
            if(root == NULL) return;
            if(res.size() == level){
                res.push_back(root->data);
            }
            recursionRight(root->right, level+1,res);
            recursionRight(root->left, level+1,res);
            
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
    vector<int> right = sl.rightSideview(root);
    for(int i = 0; i< right.size();i++){
            cout<< right[i] << " ";
        }
            cout<<endl;

    return 0;
}