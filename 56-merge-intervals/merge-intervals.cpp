class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        vector<vector<int>> res;
        for (int i = 1; i < intervals.size(); i++) {
            int s = intervals[i][0], e = intervals[i][1];
            if (s >= start && s <= end) end = max(end, e);
            else {
                res.push_back({start, end});
                start = s;
                end = e;
            }
        }

        res.push_back({start, end});
        return res;
    }
};