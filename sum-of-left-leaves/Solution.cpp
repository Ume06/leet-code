#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sum(root, 0, true);
    }

    int sum(TreeNode* root, int total, bool left) {
        if (root->left != nullptr) total = sum(root->left, total, true);
        if (root->right != nullptr) total = sum(root->right, total, false);
        if (root->left == nullptr && root->right == nullptr && left) return root->val + total;
        else return total;
    }

    void sumNumbersRecursive(TreeNode* root, vector<string>* paths, string path) {
      bool isLeaf = root->left == nullptr && root->right == nullptr;
      path += to_string(root->val);
      if (isLeaf) {
        paths->push_back(path);
        return;
      }
      else {
        if (root->left != nullptr) sumNumbersRecursive(root->left, paths, path);
        if (root->right != nullptr) sumNumbersRecursive(root->right, paths, path);
      }
      return;
    }
};