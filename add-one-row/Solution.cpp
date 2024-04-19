#include <queue>
#include <iostream>

using namespace std;

// Definition for a binary tree node.
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return addOneRowHelper(root, val, depth, 2);
    }

    TreeNode* addOneRowHelper(TreeNode* root, int val, int replacementDepth, int currentDepth) {
      if (currentDepth == replacementDepth) {
        cout << "found layer to be replaced: " << endl;
        if (root->left != nullptr) {
          TreeNode* left = new TreeNode(val);
          left->left = root->left;
          root->left = left;
        } else {
          root->left = new TreeNode(val);
        }

        if (root->right != nullptr) {
          TreeNode* right = new TreeNode(val);
          right->right = root->right;
          root->right = right;
        } else {
          root->right = new TreeNode(val);
        }
        return root;
      } else {
        root->left = addOneRowHelper(root->left, val, replacementDepth, currentDepth + 1);
        root->right = addOneRowHelper(root->right, val, replacementDepth, currentDepth + 1);
      }
    }

    void printLevels(TreeNode* root) {
      if (root == nullptr)
          return;

      std::queue<TreeNode*> q;
      q.push(root);

      while (!q.empty()) {
          int levelSize = q.size();
          for (int i = 0; i < levelSize; ++i) {
              TreeNode* node = q.front();
              q.pop();
              std::cout << node->val << " ";

              if (node->left)
                  q.push(node->left);
              if (node->right)
                  q.push(node->right);
          }
          std::cout << std::endl; // Move to the next level
      }
    }
};