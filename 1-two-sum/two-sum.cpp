class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
        int x = nums[i];
        int y = target-x;
        if(mp.find(y) != mp.end()){
            ans.push_back(mp[y]);
            ans.push_back (i);
        }
        mp[x]=i;
        
        }
        return ans;
    }
};