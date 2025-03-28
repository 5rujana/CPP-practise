// problem statement:https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
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
        vector<int> TopView(TreeNode * root){
            vector<int> ans;
            if(root == NULL) return ans;
            map<int,int> mpp;
            queue<pair<TreeNode*,int>> q;
            q.push({root,0});
            while(!q.empty()){
                auto it = q.front();
                q.pop();
                TreeNode * temp = it.first;
                int line = it.second;
                if(mpp.find(line)==mpp.end()) mpp[line] = temp->data;
                if(temp -> left) q.push({temp-> left, line-1});
                if(temp->right) q.push({temp->right, line+1}); 
            }
            for(auto it: mpp){
                ans.push_back(it.second);
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
    root-> right-> right->right = new TreeNode(23);
    vector<int> top= sl.TopView(root);
    for(int i = 0; i< top.size();i++){
            cout<< top[i] << " ";
        }
            cout<<endl;

    return 0;
}