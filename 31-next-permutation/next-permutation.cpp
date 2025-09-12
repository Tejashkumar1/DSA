class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        
        int myIndex = -1;

        for (int i = n - 1; i > 0; i--) {   
            if (nums[i - 1] < nums[i]) {
                myIndex = i - 1;
                break;
            }
        }
        if (myIndex != -1) { 
            int swap_index = myIndex;
            for (int j = n - 1; j >= myIndex + 1; j--) {
                if (nums[j] > nums[myIndex]) {
                    swap_index = j;
                    break;
                }
            }
            swap(nums[myIndex], nums[swap_index]);
        }
        reverse(nums.begin() + myIndex + 1, nums.end());
    }
};