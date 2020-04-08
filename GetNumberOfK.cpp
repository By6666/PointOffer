/**
 * 题目描述
 * 统计一个数字在排序数组中出现的次数。
 **/

#include <iostream>
#include <vector>
#include <unordered_map>

int GetNumberOfK(std::vector<int> data, int k);
int FindK(const std::vector<int>& data, int k);

int main() {
  std::cout << GetNumberOfK(std::vector<int>{1, 2, 2, 2, 3, 4, 5}, 2)
            << std::endl;
  return 0;
}

int GetNumberOfK(std::vector<int> data, int k) {
  if (data.size() == 0) return 0;

  int res = FindK(data, k);
  if (res == -1) return 0;

  int i = res - 1, j = res + 1;
  int len = data.size();
//   while (true) {
//     if (i >= 0 && data[i] == k) --i;
//     if (j < len && data[j] == k) ++j;
//     if(data[i] = k)
//   }

while(i >= 0 && data[i] == k) --i;
while(j < len && data[j] == k) ++j;
  return j - i - 1;
}

int FindK(const std::vector<int>& data, int k) {
  int left = 0, right = data.size() - 1;

  while (left <= right) {
    int mid = (left + right) >> 1;
    if (data[mid] < k)
      left = mid + 1;
    else if (data[mid] > k)
      right = mid - 1;
    else
      return mid;
  }

  return -1;
}