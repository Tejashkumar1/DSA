class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);
        vector<int> ans(nums.size(), 1);
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0) {
                prefix[i] = nums[i - 1] * prefix[i - 1];
            }
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (i != nums.size() - 1) {
                suffix[i] = nums[i + 1] * suffix[i + 1];
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};