// this is breadth first search
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
    vector<vector<int>> levelOrder(TreeNode * root){
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i<size;i++){
                TreeNode * node = q.front();
                q.pop();
                if(node-> left !=NULL) q.push(node-> left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->data);
            }
            ans.push_back(level);
        }
        return ans;
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
    vector<vector<int>> level = sl.levelOrder(root);
    for(int i = 0; i< level.size();i++){
        for(int j = 0; j < level[i].size(); j++){
            cout<< level[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;}