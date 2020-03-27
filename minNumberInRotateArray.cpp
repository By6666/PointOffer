/**
 题目描述
 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
**/

#include <iostream>
#include <vector>

int minNumberInRotateArray(std::vector<int> rotateArray);

int main() {
  std::vector<int> data{1, 2, 1, 1, 1, 1};
  std::cout << minNumberInRotateArray(data) << std::endl;
  return 0;
}

int minNumberInRotateArray(std::vector<int> rotateArray) {
  int low = 0, hight = rotateArray.size() - 1, mid = 0;

  while (low < hight) {
    if (rotateArray[low] < rotateArray[hight]) return rotateArray[low];
    mid = (low + hight) >> 1;

    if (rotateArray[low] < rotateArray[mid])
      low = mid + 1;
    else if (rotateArray[mid] < rotateArray[hight])
      hight = mid;
    else
      ++low;
  }
  return rotateArray[low];
}