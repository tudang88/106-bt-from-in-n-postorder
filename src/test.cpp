#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include "BinaryTree.h"

using namespace std;
// DO NOT MAKE CHANGES TO CAPTUREOUTPUT FUNCTION //
inline string captureOutput(function<void()> func) {
    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());
    func();
    cout.rdbuf(sbuf);
    return buffer.str();
}

/**
 * helper for printout
*/
static void printOutput(vector<vector<int>>& allLayers) {
    cout<<"Depth: "<< allLayers.size() << endl;
    cout<<"[";
    for (auto layer : allLayers) {
        cout<<"[";
        for (int idex = 0; idex < layer.size(); idex++) {
            cout<< layer.at(idex);
            if (idex != (layer.size() -1)) cout << ",";
        }
        cout<<"]";
    }
    cout<<"]\n";
}


static void test() {
  /**
   * test case 1
  */
  {
    cout<<"===============TEST 1 START================="<< endl;
    cout<<"Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3], "<< endl;
    cout<<"Output: [3,9,20,null,null,15,7]"<< endl;
    string expected ="3 9 20 15 7 ";
    Solution solution;
    vector<int> postorder = {9,15,7,20,3};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = solution.buildTree(inorder, postorder);
    std::string output = captureOutput([&]() {
            solution.DFSPreOrder(root);
        });
    cout << "EXPECTED: "<< expected << endl;
    cout << "RETURNED: " << output << "\n";
    cout << (output == expected ? "PASS\n" : "FAIL\n");
  }
  /**
   * test case 2
  */
  {
    cout<<"===============TEST 2 START================="<< endl;
    cout<<"Input: inorder = [-1], postorder = [-1]"<< endl;
    string expected ="-1 ";
    Solution solution;
    vector<int> postorder = {-1};
    vector<int> inorder = {-1};
    std::string output = captureOutput([&]() {
            TreeNode* root = solution.buildTree(inorder, postorder);
            solution.DFSPreOrder(root);
        });
    cout << "EXPECTED: "<< expected << endl;
    cout << "RETURNED: " << output << "\n";
    cout << (output == expected ? "PASS\n" : "FAIL\n");
  }
}
/**
 * main function
*/
int main(int argc, const char** argv) {
  test();
  return 0;
}


