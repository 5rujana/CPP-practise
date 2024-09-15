// problem statement: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/
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
    vector<vector<int>> verticalOrder(TreeNode * root){
        if (root == nullptr) return {};
        
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode * , pair<int,int>>> todo;
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode * temp = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(temp->data);

            if(temp-> left){
                todo.push({
                    temp->left,{
                        x-1,
                        y+1
                    }
                });
            }

            if(temp->right){
                todo.push({
                    temp->right,{
                        x+1,
                        y+1
                    }
                });
            }

        }
        vector<vector<int>> ans;
        for(auto p : nodes){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
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
    vector<vector<int>> vertical= sl.verticalOrder(root);
    for(int i = 0; i< vertical.size();i++){
        for(int j = 0;j<vertical[i].size();j++){
            cout<< vertical[i][j] << " ";
        }
            cout<<endl;
    }

    return 0;
}