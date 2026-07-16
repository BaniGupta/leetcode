class Solution {
public:
    int maxel(vector<int> &arr)
    {
        int maxi = INT_MIN;
        for(int i = 0;i<arr.size();i++)
        {
            maxi = max(maxi,arr[i]);
        }
        return maxi;
    }
    
    int calculateDays(vector<int> &arr,int m,int k ,int day)
    {
        int bouq= 0;
        int cnt = 0;
        for(int i = 0;i<arr.size();i++)
        {
            if(arr[i]<=day) cnt++;
            else
            {
                bouq += ceil(cnt/k);
                cnt = 0;
            }
        }
        bouq += ceil(cnt/k); 
        return bouq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = maxel(bloomDay);
        int ans = high;
        if((1LL*m*k) > bloomDay.size()) return -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int bouq = calculateDays(bloomDay,m,k ,mid);
            if(bouq>=m)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;


        }
        return ans;
    }
};