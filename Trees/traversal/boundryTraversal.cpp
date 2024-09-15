// problem statement: https://leetcode.com/problems/boundary-of-binary-tree/description/
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
        bool isLeaf(TreeNode * root){
            return !root->left && !root->right;
        }

        void addLeftBoundary(TreeNode * root, vector<int>& res){
            TreeNode * curr = root-> left;
            while(curr != NULL){
                if(!isLeaf(curr)){
                    res.push_back(curr->data);
                }

                if(curr->left != NULL){
                    curr = curr-> left;
                }else{
                    curr = curr-> right;
                }
            }
        }


        void addRightBoundary(TreeNode * root, vector<int>& res){
            TreeNode * curr = root-> right;
            vector<int> temp;
            while(curr != NULL){
                if(!isLeaf(curr)){
                    temp.push_back(curr-> data);
                }

                if(curr->right != NULL){
                    curr = curr->right;
                }else{
                    curr = curr-> right;
                }
            }
            for (int i = temp.size() - 1; i >= 0; --i) {
                res.push_back(temp[i]);
            }
        }

        void addLeaves(TreeNode * root, vector<int>& res){
            if(isLeaf(root)){
                res.push_back(root->data);
                return;
            }
            if (root->left != NULL) {
            addLeaves(root->left, res);
            }
            if (root->right != NULL) {
                addLeaves(root->right, res);
            }
        }

        vector<int> printBoundary(TreeNode * root){
            vector<int> res;
            if(root == NULL) return res;
            if(!isLeaf(root)){
                res.push_back(root->data);
            }
            addLeftBoundary(root,res);
            addLeaves(root,res);
            addRightBoundary(root,res);
            return res;
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
    vector<int> boundary = sl.printBoundary(root);
    for(int i = 0; i< boundary.size();i++){
            cout<< boundary[i] << " ";
    }
            cout<<endl;
    return 0;}