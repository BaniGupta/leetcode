class Solution {
public:
    int maxel(vector<int> &piles)
    {
        int maxi = INT_MIN;
        for(int i = 0;i<piles.size();i++)
        {
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    int func(vector<int> &arr,int mid)
    {
        int sum = 0;
        for(int i = 0;i<arr.size();i++)
        {
            sum += ceil((double)arr[i]/mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = maxel(nums);
        int ans = high;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int div = func(nums,mid);
            if(div<=threshold)
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
        
    }
};