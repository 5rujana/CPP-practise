// problem statement: https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
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
    int FindmaxPathSum(TreeNode * root, int &maxi){
        if(root == NULL) return 0;

        int leftMaxPathSum = max(0,FindmaxPathSum(root->left,maxi));
        int rightMaxPathSum = max(0,FindmaxPathSum(root->right,maxi));

        maxi = max(maxi ,leftMaxPathSum + rightMaxPathSum + root->data);
        return max(leftMaxPathSum,rightMaxPathSum) + root-> data;
    }

    int maxPathSum(TreeNode * root){
        int maxi = INT_MIN;
        FindmaxPathSum(root,maxi);
        return maxi;
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
    int pathSum = sl.maxPathSum(root);
    cout<< pathSum << endl;
    return 0;
}
