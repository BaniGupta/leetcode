class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        
        int maxa = INT_MIN;
        while(left<right)
        {
            maxa = max(maxa,(right-left)*min(height[right],height[left]));
            if(height[right]>height[left]) left++;
            else right--;
        }
        return maxa;
    }
};