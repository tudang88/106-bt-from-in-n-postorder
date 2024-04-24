#include <iostream>
#include "BinaryTree.h"
using namespace std;

/**
 * preorder traverser
*/
void Solution::DFSPreOrder(TreeNode *currentNode)
{
    if (currentNode == nullptr) return;
    cout << currentNode->val <<" ";
    if (currentNode->left != nullptr) {
        DFSPreOrder(currentNode->left);
    }
    if (currentNode->right != nullptr) {
        DFSPreOrder(currentNode->right);
    }
}

// /**
//  * traverser all level
//  * Depth First Search Solution
// */
TreeNode *Solution::createNode(vector<int>& postorder, vector<int>& inorder, 
unordered_map<int, int> &inorderMap, int& rootIdx, int leftInorderIndex, int lastInorderIndex)
{
    // base case
    if ( leftInorderIndex > lastInorderIndex || rootIdx < 0)
        return nullptr;
    int rootVal = postorder.at(rootIdx--);

    int pivot = inorderMap.at(rootVal);

    TreeNode* root = new TreeNode(rootVal);
    root->right = createNode(postorder, inorder, inorderMap, rootIdx, pivot + 1, lastInorderIndex);
    root->left = createNode(postorder, inorder, inorderMap, rootIdx, leftInorderIndex, pivot -1);
 
    return root;
}

/**
 * main method
*/
TreeNode *Solution::buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> inoderMap;
    // store value-index in a map
    int size = inorder.size();
    int rootIdx = size - 1;
    for (int i = 0 ; i < size; i++) {
        inoderMap[inorder.at(i)] = i;
    }
    return createNode(postorder, inorder, inoderMap, rootIdx, 0, size -1);
}
