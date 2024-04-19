#include "Solution.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  Solution nodeSolver;
  TreeNode three(3);
  TreeNode two(2);
  TreeNode root(1, &two, &three);
  vector<string> paths;
  nodeSolver.sumNumbersRecursive(&root, &paths, "");
  int total = 0;
  for (int i = 0; i < paths.size(); i++) {
    total += stoi(paths.at(i));
  }
  cout << total << endl;
}