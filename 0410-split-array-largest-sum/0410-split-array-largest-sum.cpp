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

    int total(vector<int> &arr)
    {
        int sum = 0;
        for(int i = 0;i<arr.size();i++)
        {
            sum += arr[i];
        }
        return sum;
    }

    int func(vector<int> &nu,int k,int mid)
    {
        int cntarr = 1;
        int arrsum = 0;
        for(int i = 0;i < nu.size();i++)
        {
            if( nu[i]+ arrsum <= mid)
            {
                arrsum += nu[i];
            }
            else
            {
                cntarr++;
                arrsum = nu[i];
            }
            
        }
        return cntarr;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = maxel(nums);
        int high  = total(nums);
        int ans;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int cnt = func(nums,k,mid);
            if(cnt <= k)
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