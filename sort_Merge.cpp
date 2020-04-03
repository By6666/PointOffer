/**
 * 归并排序法
 **/

#include <iostream>
#include <vector>

void MergeSort(std::vector<int>& data, int left, int right,
               std::vector<int>& temp_stg);
void Merge(std::vector<int>& data, int left, int right, int mid,
           std::vector<int>& temp_stg);

int main() {
  std::vector<int> data{5, 6, 7, 1, 2, 4, 9, 3, 0};
  std::vector<int> temp_stg(data.size());
  MergeSort(data, 0, data.size() - 1, temp_stg);
  for (auto& elem : data) {
    std::cout << elem << std::endl;
  }
  return 0;
}

void MergeSort(std::vector<int>& data, int left, int right,
               std::vector<int>& temp_stg) {
  if (left >= right) return;

  int mid = (left + right) >> 1;
  MergeSort(data, left, mid, temp_stg);
  MergeSort(data, mid + 1, right, temp_stg);

  Merge(data, left, right, mid, temp_stg);
}

void Merge(std::vector<int>& data, int left, int right, int mid,
           std::vector<int>& temp_stg) {
  int i = left, j = mid + 1, k = left;

  while (i <= mid && j <= right) {
    if (data[i] <= data[j])
      temp_stg[k++] = data[i++];
    else
      temp_stg[k++] = data[j++];
  }

  if (i > mid)
    while (j <= right) temp_stg[k++] = data[j++];
  if (j > right)
    while (i <= mid) temp_stg[k++] = data[i++];

  for (int n = left; n <= right; ++n) data[n] = temp_stg[n];
}
