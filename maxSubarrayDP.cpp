#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], maxSum = nums[0];
        int size = nums.size();

        for(int i = 1; i < size; i++){
            sum = max(nums[i], sum + nums[i]);
            maxSum = max(sum, maxSum);
        }
        
        return maxSum;
    }
};

/*
    find_sum(i) = {
                   nums[0],                     i == 0
                   max(nums[i], sum + nums[i]), i > 0
                  }

    find_Max(i) = {
                   max(sum, maxSum),             i >= 0
                  }
*/