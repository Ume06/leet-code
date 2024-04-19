#include <string>

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

/**
 * Problem:
 * Find smallest lexicographic string (each value from beginning is smallest)
 * eg: 
 *  'ab' < 'ac'
 *  'aba' < 'ac'
 *  'ab........a' < 'ac'
 *  'ab........a' > 'ab'
 * 
 * Approach:
 * Find the lowest value leaf, then  use that string
 * If two leaves have the same value, repeat for next level up
 * repeat until either you hit root or val is smaller

 * Solution:
 * when coming up from leaves, what is above must be taken into consideration when comparing
 * string values. Therefore prev character must be passed down for comparison. Solution is
 * optimised by snipping a brnach at the earlist possible opporunity, and only considering the
 * current smallest lexicographic string
 */
class Solution {
public:
    string smallestFromLeaf(TreeNode* root, string prev = "") {
      
      string val = string(1, alphabet[root->val]);

      if (root->left == nullptr && root->right != nullptr) 
        return smallestFromLeaf(root->right, val) + val;
      else if (root->left != nullptr && root->right == nullptr)
        return smallestFromLeaf(root->left, val) + val;
      else if (root->left == nullptr && root->right == nullptr)
        return val;

      string left = smallestFromLeaf(root->left, val) + val;
      string right = smallestFromLeaf(root->right, val) + val;
      string leftComp = left + prev;
      string rightComp = right + prev;
      // cout << root->val << " :" << endl << "  " << leftComp << endl << "  " << rightComp << endl;
      int length = min(leftComp.size(), rightComp.size());
      for (int i = 0; i < length; i++) {
        if (leftComp[i] < rightComp[i]) return left;
        if (rightComp[i] < leftComp[i]) return right;
      }

      if (left.size() < right.size())
        return left;
      else 
        return right;
    }
    

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
};