#include "Solution.cpp"

int main() {
  Solution s;
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(1);
  root->right->left = new TreeNode(5);

  s.printLevels(root);
  root = s.addOneRow(root, 1, 2);
  s.printLevels(root);
  delete[] root;
  return 0;
}