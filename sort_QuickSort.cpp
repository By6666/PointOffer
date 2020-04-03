/**
 * 快速排序法
 **/

#include <iostream>
#include <vector>

void QuickSort_base(std::vector<int>& data, int left, int right);
void QuickSort(std::vector<int>& data, int left, int right);

int main() {
  std::vector<int> data{5, 6, 7, 1, 2, 4, 9, 3, 0};
  QuickSort(data, 0, data.size() - 1);
  for (auto& elem : data) {
    std::cout << elem << std::endl;
  }
  return 0;
}

void QuickSort_base(std::vector<int>& data, int left, int right) {
  if (left >= right) return;

  int i = left, j = right, temp = data[left];
  while (i < j) {
    while (i < j && data[j] >= temp) --j;
    while (i < j && data[i] <= temp) ++i;
    if (i < j) std::swap(data[i], data[j]);
  }
  std::swap(data[i], data[left]);
  QuickSort_base(data, left, i - 1);
  QuickSort_base(data, i + 1, right);
}

void QuickSort(std::vector<int>& data, int left, int right) {
  if (left >= right) return;
  int i = left, j = right, key = data[left];
  while (i < j) {
    while (i < j && data[j] >= key) --j;
    data[i] = data[j];
    while (i < j && data[i] <= key) ++i;
    data[j] = data[i];
  }
  data[i] = key;
  QuickSort(data, left, i - 1);
  QuickSort(data, i + 1, right);
}
