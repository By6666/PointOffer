/**
 * 插入排序法
 **/

#include <iostream>
#include <vector>

void InsertSort(std::vector<int> data);

int main() {
  InsertSort(std::vector<int>{5, 6, 7, 1, 2, 4, 9, 3});
  return 0;
}

void InsertSort(std::vector<int> data) {
  for (int i = 1; i < data.size(); ++i) {
    int pre_index = i - 1;
    int temp = data[i];
    while (pre_index >= 0 && temp < data[pre_index]) {
      data[pre_index + 1] = data[pre_index];
      --pre_index;
    }
    data[pre_index + 1] = temp;
  }

  for (auto& elem : data) {
    std::cout << elem << std::endl;
  }
}