class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0; 
        int right = 1;
        int k = 1;
        while(right < nums.size()){
            if(nums[right] == nums[right-1]){
                right++;
                continue;
            }
            nums[left+1] = nums[right] ;
            left++;
            k++;
            right++;
        }
        return k;
    }
};