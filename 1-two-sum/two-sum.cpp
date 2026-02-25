class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int>m;
    for(int i = 0; i < nums.size(); i++){
        int remaining = target - nums[i];
        if(m.find(remaining) != m.end()){
        return {m[remaining], i};
        }
        m[nums[i]] = i;
    }
      
    return {};
    }
};