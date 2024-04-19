#include <vector>
#include <queue>
#include <unordered_map>

class Solution
{
public:
  // given an m x n 2D binary grid, return the number of islands
  int numIslands(std::vector<std::vector<char>> &grid)
  {
    int numIslands = 0;
    int rowSize = grid.size();
    int colSize = grid[0].size();

    std::vector<std::vector<int>> visited(rowSize, std::vector<int>(colSize, 0));

    for (int row = 0; row < rowSize; row++)
    {
      for (int col = 0; col < colSize; col++)
      {
        if (grid[row][col] == '1' && !visited[row][col])
        {
          numIslands++;
          floodFill(grid, visited, row, col);
        }
      }
    }

    return numIslands;
  }

  void floodFill(std::vector<std::vector<char>> &grid, std::vector<std::vector<int>> &visited, int row, int col)
  {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1')
    {
      return;
    }

    grid[row][col] = '2';
    visited[row][col] = 1;
    // Recursively flood fill the adjacent positions
    floodFill(grid, visited, row - 1, col); // Up
    floodFill(grid, visited, row + 1, col); // Down
    floodFill(grid, visited, row, col - 1); // Left
    floodFill(grid, visited, row, col + 1); // Right
  }
};