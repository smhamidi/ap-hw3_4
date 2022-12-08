#ifndef STL_H
#define STL_H

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

inline void initial_vector_with_3_mutiplies(std::vector<int> &v, size_t size) {
  std::vector<int> backup(size);

  int counter_3 = 0;
  std::generate(backup.begin(), backup.end(), [&counter_3] {
    counter_3 += 3;
    return counter_3;
  });
  v = backup;
}

inline int count_unique_above(std::vector<int> v, int n) {
  std::unordered_set<int> unique;
  std::count_if(v.begin(), v.end(), [&n, &unique](int i) {
    if (i > n) {
      unique.insert(i);
      return true;
    }
    return false;
  });
  return unique.size();
}

// inline std::string vector_to_string(std::vector<int> v, char separator) {

//   std::string string_separator(1, separator);
//   auto dash_fold = [string_separator](std::string a, int b) {
//     return std::move(a) + string_separator + std::to_string(b);
//   };

//   std::string s =
//       std::accumulate(std::next(v.rbegin()), v.rend(),
//                       std::to_string(v.size()), // start with last element
//                       dash_fold);

//   return s;
// }

#endif // STL_H