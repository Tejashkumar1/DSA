class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        int currSum=0;
        for(int x: nums){
            currSum=max(x,currSum+x);
            maxSum=max(maxSum,currSum);
        }
        return maxSum;

     




    }
};