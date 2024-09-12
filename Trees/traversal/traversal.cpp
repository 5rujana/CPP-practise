// this is depth first
#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){
        data = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int data){
        this->data = data;
        this-> left = NULL;
        this -> right = NULL;
    }
};

class Solution{
    public:
    void preOrder(TreeNode * root, vector<int>& ans){
        if(root == NULL) return;
        ans.push_back(root->data);
        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }
    vector<int> preOrderTraversal(TreeNode * root){
        vector<int> ans;
        preOrder(root, ans);
        return ans;
    }
    void postOrder(TreeNode * root, vector<int>& ans){
        if(root == NULL) return;
        preOrder(root->left,ans);
        preOrder(root->right, ans);
        ans.push_back(root-> data);
    }
    vector<int> postOrderTraversal(TreeNode * root){
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
    void inOrder(TreeNode * root, vector<int>& ans){
        if(root == NULL) return;
        inOrder(root->left,ans);
        ans.push_back(root->data);
        inOrder(root->right,ans);
    }
    vector<int> inOrderTraversal(TreeNode * root){
        vector<int> ans;
        inOrder(root, ans);
        return ans;
    }
};

int main(){
    Solution sl;
    TreeNode * root = new TreeNode(9);
    root-> left = new TreeNode(10);
    root-> right = new TreeNode(11);
    root-> left->left = new TreeNode(13);
    root-> left->right = new TreeNode(14);
    root-> right->left = new TreeNode(15);
    root-> right-> right = new TreeNode(16);
    root-> left->left->left = new TreeNode(17);
    root-> left->left->right = new TreeNode(18);   
    root-> left->right-> left = new TreeNode(19);
    root-> left->right->right = new TreeNode(20);
    root-> right->left->left = new TreeNode(21);
    root-> right->left->right = new TreeNode(22);   
    root-> right-> right->left = new TreeNode(23);
    root-> right-> right->left = new TreeNode(24);
    vector<int> preOrder = sl.preOrderTraversal(root);
    for(int i = 0; i < preOrder.size();i++){
        cout<< preOrder[i] << " ";
    }
    cout<< endl;
    vector<int> postOrder = sl.postOrderTraversal(root);
    for(int i = 0; i < postOrder.size();i++){
        cout<< postOrder[i] << " ";
    }
    cout<< endl;
    vector<int> inOrder = sl.inOrderTraversal(root);
    for(int i = 0; i < inOrder.size();i++){
        cout<< inOrder[i] << " ";
    }
    cout<< endl;
    return 0;
}


