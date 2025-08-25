class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            if(mp.find(x) != mp.end())
            return true;
            mp[x]=1;
        }
        return false;
     
    }
};