class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i = -1;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> v;
        int n = intervals.size();
        int maxa = 0;

        for (int j = 0; j < n - 1; j++) {
            maxa = max(maxa, intervals[j][1]);
            if (i == -1) i = intervals[j][0];
            if (maxa < intervals[j + 1][0]) {
                v.push_back({i, maxa});
                i = -1;
                maxa = 0;
            }
        }
        if (i == -1) i = intervals[n - 1][0];
        v.push_back({i, max(maxa, intervals[n - 1][1])});
        return v;
    }
};