/**
题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。
即输出P%1000000007
 **/

#include <iostream>
#include <vector>

int InversePairs(std::vector<int> data);
void MeargeSort(std::vector<int>& data, int left, int right,
                std::vector<int>& temp_stg, int& res);
void Mearge(std::vector<int>& data, int left, int right, int min,
            std::vector<int>& temp_stg, int& res);

int main() {
  std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 0};
  std::cout << InversePairs(data) << std::endl;
  return 0;
}

int InversePairs(std::vector<int> data) {
  if (data.size() < 2) return 0;

  std::vector<int> temp(data.size());
  int res = 0;
  MeargeSort(data, 0, data.size() - 1, temp, res);

  return res;
}

void MeargeSort(std::vector<int>& data, int left, int right,
                std::vector<int>& temp_stg, int& res) {
  if (left >= right) return;

  int mid = (left + right) >> 1;
  MeargeSort(data, left, mid, temp_stg, res);
  MeargeSort(data, mid + 1, right, temp_stg, res);

  Mearge(data, left, right, mid, temp_stg, res);
}

void Mearge(std::vector<int>& data, int left, int right, int min,
            std::vector<int>& temp_stg, int& res) {
  int i = left, j = min + 1, k = left;
  while (i <= min && j <= right) {
    if (data[i] <= data[j]) {
      temp_stg[k++] = data[i++];
    } else {
      temp_stg[k++] = data[j++];
      res = (res + j - k) % 1000000007;
    }
  }
  if (i > min)
    while (j <= right) temp_stg[k++] = data[j++];
  if (j > right)
    while (i <= min) temp_stg[k++] = data[i++];

  for (int n = left; n <= right; ++n) {
    data[n] = temp_stg[n];
  }
}