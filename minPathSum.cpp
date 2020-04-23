/**
 * 题目描述
给定一个包含非负整数的 m x n
网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。
示例:
输入:
[[1,3,1],
[1,5,1],
[4,2,1]]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
*/

#include <iostream>
#include <vector>

int minPathSum(const std::vector<std::vector<int>>& data, int m, int n,
               std::vector<std::vector<int>>& stg);
int minPathSum(std::vector<std::vector<int>>& data);
std::vector<int> path;
int cnt = 0;

int main() {
  std::vector<std::vector<int>> data;

  data.push_back(std::vector<int>{1, 4, 1});
  data.push_back(std::vector<int>{1, 5, 1});
  data.push_back(std::vector<int>{4, 2, 1});
  std::vector<std::vector<int>> stg(3, std::vector<int>(3, -1));

  std::cout << minPathSum(data, 0, 0, stg) << std::endl;
  std::cout << minPathSum(data) << std::endl;

  std::cout << "data: " << std::endl;

  for (auto& elem : data) {
    for (auto& it : elem) {
      std::cout << it << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "cnt : " << cnt << std::endl;
}

int minPathSum(const std::vector<std::vector<int>>& data, int m, int n,
               std::vector<std::vector<int>>& stg) {
  ++cnt;
  if (m < 0 && n < 0) return 0;

  if (m == data.size() - 1 && n == data.back().size() - 1) {
    if (stg[m][n] == -1) stg[m][n] = data[m][n];
    return stg[m][n];
  }
  if (m == data.size() - 1) {
    if (stg[m][n + 1] == -1) stg[m][n + 1] = minPathSum(data, m, n + 1, stg);

    return data[m][n] + stg[m][n + 1];
  }
  if (n == data.back().size() - 1) {
    if (stg[m + 1][n] == -1) stg[m + 1][n] = minPathSum(data, m + 1, n, stg);
    return data[m][n] + stg[m + 1][n];
  }

  if (stg[m][n + 1] == -1) stg[m][n + 1] = minPathSum(data, m, n + 1, stg);
  if (stg[m + 1][n] == -1) stg[m + 1][n] = minPathSum(data, m + 1, n, stg);

  if (stg[m][n] == -1)
    stg[m][n] = data[m][n] + std::min(stg[m][n + 1], stg[m + 1][n]);
  return stg[m][n];
}

int minPathSum(std::vector<std::vector<int>>& data) {
  if (data.size() == 0) return 0;

  int m = data.size() - 1, n = data.back().size() - 1;
  for (int i = m; i >= 0; --i) {
    for (int j = n; j >= 0; --j) {
      if (i == m && j == n) continue;
      int down = (i == m) ? data[i][j + 1] : data[i + 1][j];
      int right = (j == n) ? data[i + 1][j] : data[i][j + 1];
      //   int down = 0, right = 0;
      //   if (i < m && j < n) {
      //     down = data[i + 1][j];
      //     right = data[i][j + 1];
      //   } else if (i == m) {
      //     down = 0;
      //     right = data[i][j + 1];
      //   } else if (j == n) {
      //     down = data[i + 1][j];
      //     right = 0;
      //   }
      data[i][j] += std::min(down, right);
    }
  }
  return data[0][0];
}