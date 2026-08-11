class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0, minlen = INT_MAX,cnt = 0,sIndex = -1;
        int n  = s.size ();
        int m = t.size();
        vector<int> hash(256,0);
        for (char c : t) {
            hash[c]++;
        }


        while(right<n)
        {
            if(hash[s[right]]>0) cnt = cnt + 1;
            hash[s[right]]--;
            while(cnt == m)
            {
                if((right-left+1) < minlen)
                {
                    minlen = right-left+1;
                    sIndex = left;
                }
                hash[s[left]]++;
                if(hash[s[left]] > 0) cnt = cnt -1;
                left++;
            }
            right++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex,minlen);
        
    }
};