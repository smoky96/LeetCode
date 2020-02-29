#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        //要保证 n>=m，因为 i = [0, m), j = (m + n + 1) / 2 - i. j不能为负数
        if (n < m) {
            nums1.swap(nums2);
            int tmp = m;
            m = n;
            n = tmp;
        }
        int imin = 0;
        int imax = m;
        int halfLength = (m + n + 1) / 2;
        /*  left = i + j = m - i + n - j (+ 1) = right
            如果 m + n 为偶数：j = (m + n) / 2 - i 此时median是左边最大值和右边最小值的平均值
            如果 m + n 为奇数：j = (m + n + 1) / 2 - i 此时将median放在了左边，median是左边最大值
            且不论是奇数还是偶数 (m + n) / 2 和 (m + n + 1) / 2 的值都相同，所以取 j = (m + n + 1) / 2 - i
        */
        // j = (m + n (+ 1)) / 2 - i
        int i;      //nums1的划分点，采用二分查找的策略找到最佳划分点
        int j;      //nums2的划分点
        int leftMax;
        int rightMin;
        while (imin <= imax) {
            i = (imin + imax) / 2;
            j = halfLength - i;

            if (i > 0 && j < n && nums1[i-1] > nums2[j]) {
                // 这里的条件 m <= n , i > 0 ==> j = (m + n + 1) / 2 - i < (m + n + 1) / 2 <= (2 * n + 1) / 2 = n, 所以可以省略条件 j < n
                imax = i - 1;
            }else if (j > 0 && i < m && nums2[j-1] > nums1[i]) {
                // 同理 m <= n , i < m ==> j = (m + n + 1) / 2 - i > (m + n + 1) / 2 - m >= (2 * m + 1) / 2 - m = 0, 可神略条件 j > 0
                imin = i + 1;
            }else { 
                // 找到 i 的位置，处理边界情况

                // i = 0 或 j = 0 的情况，先确定 leftMax
                if (i == 0) {
                    //nums1 全部在右边且 j != 0
                    leftMax = nums2[j - 1];
                } else if (j == 0) {
                    //nums2 全部在右边且 i != 0
                    leftMax = nums1[i - 1];
                } else {
                    leftMax = max(nums1[i-1], nums2[j-1]);
                }  

                if ((m + n) % 2) {
                    return leftMax;
                }

                // i = m 或 j = n 的情况，确定rightMin
                if (i == m) {
                    //nums1 全部在左边且 j != n
                    rightMin = nums2[j];
                } else if (j == n) {
                    //nums2 全部在左边且 i != m
                    rightMin = nums1[i];
                } else {
                    rightMin = min(nums1[i], nums2[j]);
                }
                
                return (leftMax + rightMin) / 2.0;
            }
        }
        return 0.0;
    }
};

void test(vector<int>& nums1, vector<int>& nums2) {
    Solution s;
    double result = s.findMedianSortedArrays(nums1, nums2);
    cout << "numbers1: ";
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << ' ';
    }
    cout << endl;
    cout << "numbers2: ";
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i] << ' ';
    }
    cout << endl;
    cout << "median: " << result << endl << endl;
}

int main() {
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    nums2.push_back(3);
    test(nums1, nums2);

    nums1.clear();
    nums2.clear();
    nums1.push_back(1);
    nums1.push_back(2);
    nums2.push_back(3);
    nums2.push_back(4);
    test(nums1, nums2);

    nums1.clear();
    nums2.clear();
    nums1.push_back(2);
    nums1.push_back(5);
    nums1.push_back(10);
    nums1.push_back(14);
    nums2.push_back(1);
    nums2.push_back(3);
    nums2.push_back(9);
    nums2.push_back(11);
    nums2.push_back(13);
    test(nums1, nums2);

    cout << "press enter to continue" << endl;
    cin.get();

    return 0;
}