/**
题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
 例如 :
 | a b c e |
 | s f c s |
 | a d e e |
矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/

#include <string.h>

#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>

// using namespace std;

// class Solution {
//  public:
//   bool hasPath(char* matrix, int rows, int cols, char* str) {
//     if (strlen(str) == 0 || (rows == 0 && cols == 0)) return false;

//     row_ = rows;
//     col_ = cols;
//     matrix_ = matrix;

//     for (int i = 0; i < rows; ++i) {
//       for (int j = 0; j < cols; ++j) {
//         int temp_id = i * cols + j;
//         if (matrix[temp_id] == str[0]) {
//           if (FindPath(str, temp_id)) return true;
//         }
//       }
//     }
//     return false;>
//   }

//  private:
//   int row_, col_;
//   char* matrix_;
//   set<int> id_stg;

//   struct node_type {
//     char c;
//     int curr_id;
//     int last_id;
//     node_type(char c_, int curr_id_, int last_id_)
//         : c(c_), curr_id(curr_id_), last_id(last_id_) {}
//   };

//   bool FindPath(char* str, int s_id) {
//     int len = strlen(str);
//     int str_index = 1;
//     if (len == 1) return true;

//     stack<node_type> openlist;
//     openlist.push(node_type(matrix_[s_id], s_id, -1));

//     while (!openlist.empty()) {
//       node_type temp_node = openlist.top();
//       openlist.pop();

//       if (id_stg.find(temp_node.curr_id) == id_stg.end()) {
//         vector<int> next_node = GetNextNode(temp_node);
//         id_stg.insert(temp_node.curr_id);
//         int push_flag = 0;
//         for (auto& elem : next_node) {
//           if (matrix_[elem] == str[str_index]) {
//             openlist.push(node_type(matrix_[elem], elem, temp_node.curr_id));
//             ++push_flag;
//           }
//         }
//         if (push_flag) {
//           ++str_index;
//           if (str_index == len) return true;
//         } else
//           --str_index;
//       }
//     }

//     return false;
//   }

//   vector<int> GetNextNode(const node_type& node) {
//     vector<int> res;
//     int curr_r = node.curr_id / col_;
//     int curr_c = node.curr_id % col_;
//     int temp = 0;
//     if (curr_r > 0) {
//       temp = CalculateId(curr_r - 1, curr_c);
//       if (temp != node.last_id && temp < row_ * col_ && temp >= 0)
//         res.push_back(temp);
//     }

//     if (curr_r < row_ - 1 && curr_r >= 0) {
//       temp = CalculateId(curr_r + 1, curr_c);
//       if (temp != node.last_id && temp < row_ * col_ && temp >= 0)
//         res.push_back(temp);
//     }

//     if (curr_c > 0) {
//       temp = CalculateId(curr_r, curr_c - 1);
//       if (temp != node.last_id && temp < row_ * col_ && temp >= 0)
//         res.push_back(temp);
//     }

//     if (curr_c < col_ - 1 && curr_c >= 0) {
//       temp = CalculateId(curr_r, curr_c + 1);
//       if (temp != node.last_id && temp < row_ * col_ && temp >= 0)
//         res.push_back(temp);
//     }
//     std::cout << "current id :" << node.curr_id << " neighbor-> : ";
//     for (auto& elem : res) {
//       std::cout << elem << "  ";
//     }
//     std::cout << std::endl;

//     return res;
//   }

//   inline int CalculateId(int r, int c) { return r * col_ + c; }
// };

bool hasPath(char* matrix, int rows, int cols, char* str);
bool dfs(const char* matrix, int rows, int cols, char* str, int cnt, int col,
         int row, int last_id);
inline int CalculateId(int r, int c, int col) { return r * col + c; }

int main() {
  // char* matrix =
  // const_cast<char*>("ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS"); char* str =
  // const_cast<char*>("SGGFIECVAASABCEHJIGQEMS");
  char* matrix = const_cast<char*>("abcesfcsadee");
  char* str = const_cast<char*>("see");
  // bool flag = stu.hasPath(matrix, 5, 8, str);
  bool flag = hasPath(matrix, 3, 4, str);
  std::cout << flag << std::endl;
  return 0;
}

bool hasPath(char* matrix, int rows, int cols, char* str) {
  if (strlen(str) == 0 || (rows == 0 && cols == 0)) return false;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      int temp_id = i * cols + j;
      if (matrix[temp_id] == str[0]) {
        std::cout << "start_id = " << temp_id << std::endl;
        bool flag = dfs(matrix, i, j, str, 0, cols, rows, -1);
        if (flag) return true;
      }
    }
  }
  return false;
}

bool dfs(const char* matrix, int rows, int cols, char* str, int cnt, int col,
         int row, int last_id) {
  bool flag = false;
  if (cnt == strlen(str) - 1 &&
      matrix[CalculateId(rows, cols, col)] == str[cnt]) {
    std::cout << "cnt = " << cnt << std::endl;
    return true;
  }

  if (rows - 1 >= 0) {
    int temp_id = CalculateId(rows - 1, cols, col);

    if (temp_id != last_id && matrix[temp_id] == str[cnt + 1]) {
      std::cout << "temp_id = " << temp_id << std::endl;
      flag |= dfs(matrix, rows - 1, cols, str, cnt + 1, col, row,
                  CalculateId(rows, cols, col));
    }
  }
  if (rows + 1 < row) {
    int temp_id = CalculateId(rows + 1, cols, col);

    if (temp_id != last_id && matrix[temp_id] == str[cnt + 1]) {
      std::cout << "temp_id = " << temp_id << std::endl;
      flag |= dfs(matrix, rows + 1, cols, str, cnt + 1, col, row,
                  CalculateId(rows, cols, col));
    }
  }
  if (cols - 1 >= 0) {
    int temp_id = CalculateId(rows, cols - 1, col);
    if (temp_id != last_id && matrix[temp_id] == str[cnt + 1]) {
      std::cout << "temp_id = " << temp_id << std::endl;

      flag |= dfs(matrix, rows, cols - 1, str, cnt + 1, col, row,
                  CalculateId(rows, cols, col));
    }
  }
  if (cols + 1 < col) {
    int temp_id = CalculateId(rows, cols + 1, col);

    if (temp_id != last_id && matrix[temp_id] == str[cnt + 1]) {
      std::cout << "temp_id = " << temp_id << std::endl;
      flag |= dfs(matrix, rows, cols + 1, str, cnt + 1, col, row,
                  CalculateId(rows, cols, col));
    }
  }
  return flag;
}
