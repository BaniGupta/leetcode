class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_map <char,int> mp;
        int n = s.size();
        int ans = 0;
    
        while(right<n)
        {
            if(mp.find(s[right])!=mp.end()&& mp[s[right]] >= left)
            {
                left = mp[s[right]] + 1;
            }
             mp[s[right]] = right;

            ans = max(ans, right - left + 1);
            right++;
        } 
        return ans;
    }
};