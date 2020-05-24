#include <iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int newTarget = target - nums[i];
            if (hash.find(newTarget) != hash.end()){
                result.push_back(hash[newTarget]);
                result.push_back(i);
                return result;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};

void test(vector<int>& nums, int target) {
    Solution s;
    vector<int> result = s.twoSum(nums, target);
    cout << "numbers: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;
    cout << "target: " << target << " = " << nums[result[0]] << " + " << nums[result[1]] << endl;
}

int main() {
    vector<int> nums;
    int target = 9;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    test(nums, target);

    nums.clear();
    target = 16;
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(8);
    nums.push_back(10);
    nums.push_back(21);
    test(nums, target);

    cout << "press enter to continue" << endl;
    cin.get();

    return 0;
}