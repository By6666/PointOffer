/**
 * 冒泡排序法
 **/

#include <iostream>
#include <vector>

void BubbleSort(std::vector<int> data);

int main() {
  BubbleSort(std::vector<int>{5, 6, 7, 1, 2, 4, 9, 3});
  return 0;
}

void BubbleSort(std::vector<int> data) {
  for (int i = 0; i < data.size(); ++i) {
    for (int j = 0; j < data.size() - 1; ++j) {
      if (data[j] > data[j + 1]) std::swap(data[j], data[j + 1]);
    }
  }

  for (auto& elem : data) {
    std::cout << elem << std::endl;
  }
}