#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 else
                     return a[0] < b[0];
             });

        int size = envelopes.size(), res = 0;

        vector<int> lis(size + 1, INT_MAX);
        lis[0] = -INT_MAX;

        for (int i = 0; i < size; i++) {
            auto it = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
            auto index = (int)(it - lis.begin());

            res = max(res, index);
            lis[index] = envelopes[i][1];
        }

        return res;
    }
};