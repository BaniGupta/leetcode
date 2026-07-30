class Solution {
public:
    int characterReplacement(string s, int k) {
     int left = 0, right = 0;
     int n = s.size();
     int maxfreq = INT_MIN;
     
     int len = 0;
    int maxlen = INT_MIN;
    vector<int> hashset(26,0);
     while(right < n)
     {
        
        hashset[s[right]-'A']++;
        maxfreq = max(maxfreq,hashset[s[right]-'A']);
        len = right-left+1;
        
        if((len - maxfreq) <= k) 
        {
            maxlen = max(maxlen,len);
            right++;
        }
        else 
        {
            hashset[s[left]-'A']--;
            left++;
            right++;
        }
     } 
     return maxlen;
    }
};