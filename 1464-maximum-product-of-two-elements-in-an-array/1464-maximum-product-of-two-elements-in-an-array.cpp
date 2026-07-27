class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxel = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
               maxel = max(maxel,((nums[i]-1)*(nums[j]-1)));
            }
        }
        return maxel;
    }
};