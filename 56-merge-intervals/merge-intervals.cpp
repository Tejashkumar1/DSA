class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        int n = in.size();
        if(n==1)
            return in;
        sort(in.begin(),in.end());
        int i = 0;
        vector<vector<int>> ans;
        while(i<n){
            int j = i+1;
            int st = in[i][0];
            int en = in[i][1];
            while(j<n && in[j][0] <= en){    
                st = min(st,in[j][0]);
                en = max(en,in[j][1]);
                j++;
            }
            ans.push_back({st,en});
            i = j;
        }
        return ans;
    }
};