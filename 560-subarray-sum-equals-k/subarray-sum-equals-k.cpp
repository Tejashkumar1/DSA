class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        
        unordered_map<int, int>mpp;
        mpp[0] = 1;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum = sum+nums[i];
            int rem = sum-k;
            if(mpp.find(rem)!=mpp.end())ans+=mpp[rem];
            mpp[sum]++;
        }
        return ans;
    }
};