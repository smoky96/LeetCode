#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int maxArea = 0;
        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i + 1; j < height.size(); j++) {
                maxArea = max((j - i) * min(height[i], height[j]), maxArea);
            }
        }
        return maxArea;
    }

    int maxAreaOptimized(vector<int>& height)
    {
        int front = 0;
        int rear = height.size() - 1;
        int maxArea = 0;
        while (front < rear) {
            maxArea = max((rear - front) * min(height[front], height[rear]), maxArea);
            if (height[front] > height[rear]) {
                rear = rear - 1;
            } else {
                front = front + 1;
            }
        }
        return maxArea;
    }
};