class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int gIndex = 0, sIndex = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(sIndex < s.size() && gIndex < g.size())
        {
                if(g[gIndex]<=s[sIndex]) gIndex++;
                sIndex++;
        }
        return gIndex;
    }
};