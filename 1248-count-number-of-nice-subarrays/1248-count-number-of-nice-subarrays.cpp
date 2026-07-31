class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        int odd_count = 0;
        mp[0] = 1;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]%2==1){
                odd_count++;
            }
            if(mp.find(odd_count-k) != mp.end())
            {
                count += mp[odd_count-k];
            }
            mp[odd_count]++;
        }
        return count;
    }
};