class Solution {
public:

    vector<int> leftMax(const vector<int>& height){
        int n = height.size();
        vector<int> left(n);
        left[0] = height[0];
        for(int i = 1;i<n;i++){
            left[i] = max(left[i-1],height[i]);
        }
        return left;
    }
    vector<int> rightMax(const vector<int>& height){
        int n = height.size();
        vector<int> right(n);
        right[n-1] = height[n-1];
        for(int i = n-2;i>=0;i--){
            right[i] = max(right[i+1],height[i]);
        }
        return right;
    }
    int trap(vector<int>& height) {
        if(height.size() == 0){return 0;}
        int n = height.size();
        vector<int> left = leftMax(height);
        vector<int> right = rightMax(height);
        int total = 0;
        for(int i = 0;i<n;i++){
            total += min(left[i],right[i]) - height[i];
        }
        return total;
    }
};
