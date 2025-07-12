#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int nums_size = nums.size();
        vector<int> lis(nums_size, 1);

        for (int i = 1; i < nums_size; i++) {

            for (int j = i - 1; j >= 0; j--) {
                
                if (nums[i] > nums[j])
                    lis[i] = max(lis[i], 1 + lis[j]);
            }
        }
        
        return *max_element(lis.begin(), lis.end());
    }
};