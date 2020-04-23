/**
 * 题目描述：
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
问总共有多少条不同的路径？
*/

#include <algorithm>
#include <iostream>
#include <vector>

int uniquePaths(int m, int n);
int uniquePathsSingle(int i, int j, int m, int n);
int DP_uniquePathsSingle(int m, int n);

class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m == 0 && n == 0) return 0;
    m_ = m;
    n_ = n;

    stg = std::vector<long int>(m_ * n_, -1);
    int res = uniquePathsSingle(0, 0);

    int cnt = 0;
    for (auto& raw : stg) {
      std::cout << raw << " ";
      ++cnt;
      if (cnt == n_) {
        std::cout << std::endl;
        cnt = 0;
      }
    }
    return res;
  }

 private:
  int m_, n_;
  std::vector<long int> stg;

  long int uniquePathsSingle(int i, int j) {
    if (i == m_ - 1 && j == n_ - 1) {
      stg[calculateID(i, j)] = 1;
      return 1;
    }

    // int down = (i < m_ - 1) ? uniquePathsSingle(i + 1, j) : 0;
    // int right = (j < n_ - 1) ? uniquePathsSingle(i, j + 1) : 0;
    long int down = 0, right = 0;
    if (i < m_ - 1) {
      if (stg[calculateID(i + 1, j)] == -1)
        stg[calculateID(i + 1, j)] = uniquePathsSingle(i + 1, j);
      down = stg[calculateID(i + 1, j)];
    }
    if (j < n_ - 1) {
      if (stg[calculateID(i, j + 1)] == -1)
        stg[calculateID(i, j + 1)] = uniquePathsSingle(i, j + 1);
      right = stg[calculateID(i, j + 1)];
    }

    return down + right;
  }

  inline int calculateID(int i, int j) { return i * n_ + j; }
};

int main() {
  int m = 3, n = 3;

  std::cout << uniquePaths(m, n) << std::endl;

  Solution obj;
  std::cout << obj.uniquePaths(m, n) << std::endl;
  std::cout << DP_uniquePathsSingle(m, n) << std::endl;
  return 0;
}

int uniquePaths(int m, int n) {
  if (m == 0 && n == 0) return 0;

  return uniquePathsSingle(0, 0, m, n);
}

int uniquePathsSingle(int i, int j, int m, int n) {
  if (i == m - 1 && j == n - 1) return 1;

  int down = (i < m - 1) ? uniquePathsSingle(i + 1, j, m, n) : 0;
  int right = (j < n - 1) ? uniquePathsSingle(i, j + 1, m, n) : 0;

  return down + right;
}

int DP_uniquePathsSingle(int m, int n) {
  if (m == 0 && n == 0) return 0;

  std::vector<std::vector<int>> stg(m, std::vector<int>(n, -1));
  stg[m - 1][n - 1] = 1;

  for (int i = m - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (i == m - 1 && j == n - 1) continue;

      int down = (i < m - 1) ? stg[i + 1][j] : 0;
      int right = (j < n - 1) ? stg[i][j + 1] : 0;
      stg[i][j] = down + right;
    }
  }
  return stg[0][0];
}
