class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0,right = 0,left = 0,count = 0;
        map<long long,int> presummap;
        presummap[0] = 1;
        for(int i = 0;i < nums.size();i++)
        {
            sum+= nums[i];
           
            long long rem = sum-goal;
            if(presummap.find(rem)!=presummap.end()) count+= presummap[rem];
            presummap[sum]++;

        } 
        


       
        return count;
    }
};