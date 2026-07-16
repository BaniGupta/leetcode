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

    long long func(vector<int> &piles,int mid)
    {
        long long totalHours = 0;
        for(int i = 0;i<piles.size();i++)
        {
            totalHours += ceil((double)piles[i]/mid);
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxel(piles);
        int ans = high;
        while(low<=high)
        {
            int mid = (low+high)/2;
            long long totalHours = func(piles,mid);
            if(totalHours<=h)
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