#include <algorithm>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int minArray(vector<int>& numbers) {
    int i = 0;
    int j = numbers.size() - 1;
    if (i == j) return numbers[0];
    int mid = 0;
    while (numbers[i] >= numbers[j]) {
      if (i == j - 1) {
        mid = j;
        break;
      }
      mid = (i + j) >> 1;
      if (numbers[mid] == numbers[i] && numbers[mid] == numbers[j]) {
        --j;
        for (; j > mid; --j) {
          if (numbers[j] != numbers[j + 1]) break;
        }
      } else if (numbers[mid] >= numbers[i]) {
        i = mid;
      } else if (numbers[mid] <= numbers[j]) {
        j = mid;
      }
    }
    return numbers[mid];
  }
};