class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
            int left = 0;
            int right  = 0;
            
            int n = nums.size();
            int len = 0;
            int ml = INT_MIN;
            while(right<n)
            {
                if(nums[right]==1)
                {
                    len = right - left + 1;
                }
                else
                {
                    if(k>0)
                    {
                        len = right - left + 1;
                        k--;
                        ml  = max(len,ml);
                        
                    }
                    else
                    {
                        while (nums[left] != 0)
                    {
                        left++;
                    }

                    left++;
                    len = right - left + 1;
                    }
                }
                
                ml  = max(ml,len);

                right++;
                
            }
            return ml;
    }
};