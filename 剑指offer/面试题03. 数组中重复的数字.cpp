#include <vector>
using namespace std;

class Solution {
 public:
  int findRepeatNumber(vector<int>& nums) {
    int i = 0;
    int len = nums.size();
    int ret = 0;
    while (i < len) {
      if (nums[i] != i) {
        if (nums[i] == nums[nums[i]]) {
          ret = nums[i];
          break;
        }
        swap(nums[i], nums[nums[i]]);
      } else {
        ++i;
      }
    }
    return ret;
  }
};