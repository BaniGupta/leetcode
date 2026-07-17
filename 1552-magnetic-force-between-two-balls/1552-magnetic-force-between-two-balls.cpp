class Solution {
public:
    bool canWePlace(vector<int> position,int m,int mid)
    {
        int cnt = 1, last = position[0];
        for(int iterator=0;iterator<position.size();iterator++)
        {
            if(position[iterator]-last>=mid)
            {
                cnt++;
                last = position[iterator];
            }
            
        }
        if(cnt >= m)
            {
                return true;
            }
            else
            {
                return false;
            }
        
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());

        int low = 0;
        int high = position[position.size()-1] - position[0];
        int ans;
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            if(canWePlace(position,m,mid) == true)
            {
                 ans = mid;
                low=mid+1;
               
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }
};