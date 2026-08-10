class Solution {
public:
    int atmost(vector<int>& nums,int k)
    {
         int left = 0;
        unordered_map<int,int> freq;
        int count = 0;
        for(int right = 0; right < nums.size();right++)
        {
            freq[nums[right]]++;
            
            while(freq.size()>k)
            {
                freq[nums[left]]--;
                if(freq[nums[left]]==0) 
                {
                    freq.erase(nums[left]);

                }
                left++;
            }
             count += right-left+1;
            
            
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return (atmost(nums,k) - atmost(nums,k-1));
    }
};