#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int size = nums.size(), res = 0;
        
        vector<int> lis((size+1), INT_MAX);
        lis[0] = -INT_MAX;

        for(int i = 0; i < size; i++){

            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
            auto index = (int) (it - lis.begin());
            
            res = max(res, index);
            lis[index] = nums[i];
        }

        return res;
    }
};

//O(nlog(n))