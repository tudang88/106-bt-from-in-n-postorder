#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <iostream>
#include <queue>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * solution class
*/
class Solution {
public:
    void DFSPreOrder(TreeNode *currentNode);
   TreeNode* createNode(vector<int>& postorder, vector<int>& inorder, unordered_map<int, int> &inorderMap, int& rootIdx, int leftInorderIndex, int lastInorderIndex);    
   TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder);
};
#endif