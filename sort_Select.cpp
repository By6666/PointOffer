/**
 * 选择排序法
 **/

#include <iostream>
#include <vector>

void SelectSort(std::vector<int> data);

int main() {
  SelectSort(std::vector<int>{5, 6, 7, 1, 2, 4, 9, 3});
  return 0;
}

void SelectSort(std::vector<int> data) {
  for (int i = 0; i < data.size() - 1; ++i) {
    int min = i;
    for (int j = i + 1; j < data.size(); ++j) {
      min = (data[min] > data[j]) ? j : min;
    }
    std::swap(data[i], data[min]);
  }

  for (auto& elem : data) {
    std::cout << elem << std::endl;
  }
}