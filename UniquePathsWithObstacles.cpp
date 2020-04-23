/**
 * 题目描述：
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
问总共有多少条不同的路径？
*/

#include <algorithm>
#include <iostream>
#include <vector>

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid);

int main() {
  int m = 3, n = 3;

  return 0;
}

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
  if (obstacleGrid.size() == 0) return 0;
  if (obstacleGrid.back().back() == 1) return 0;
  int m = obstacleGrid.size(), n = obstacleGrid.back().size();

  std::vector<std::vector<int>> stg(m, std::vector<int>(n, 0));
  stg[m - 1][n - 1] = 1;

  for (int i = m - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (i == m - 1 && j == n - 1) continue;
      if (obstacleGrid[i][j] == 1) continue;
      int down = (i < m - 1) ? stg[i + 1][j] : 0;
      int right = (j < n - 1) ? stg[i][j + 1] : 0;

      stg[i][j] = down + right;
    }
  }
  return stg[0][0];
}