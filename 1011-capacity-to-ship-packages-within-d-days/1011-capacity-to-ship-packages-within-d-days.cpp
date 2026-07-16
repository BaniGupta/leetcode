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
    long long func(vector<int> &arr,int mid)
    {
        
        int cnt = 1;
        int sum = 0;
        for(int i = 0;i<arr.size();i++)
        {
            
            if(sum + arr[i] > mid)
            {
                cnt++;
                sum = arr[i];

            }
            else
            {
                
                sum +=arr[i];
            }
            
        }
        return cnt;


       
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = maxel(weights);
        int high = total(weights) ;
        int ans = high;
        while(low<=high)
        {
            int mid = (low+high)/2;
            long long totalweight = func(weights,mid);
            if(totalweight<=days)
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