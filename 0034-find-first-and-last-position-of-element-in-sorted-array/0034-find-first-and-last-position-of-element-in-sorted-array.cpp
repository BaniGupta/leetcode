class Solution {
public:

int lower_bound(vector<int> nums,int target)
{
    int ans = nums.size();
    int low = 0;
    int high = nums.size()-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(nums[mid]>=target)
        {
            ans = mid;
            high  =mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return ans;
}
int upper_bound(vector<int> nums,int target)
{
    int ans = nums.size();
    int low = 0;
    int high = nums.size()-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(nums[mid]>target)
        {
            ans = mid;
            high  =mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums,target);
        if(lb == nums.size() || nums[lb] != target) return {-1,-1};
        return{lb,upper_bound(nums,target)-1};
    }
};