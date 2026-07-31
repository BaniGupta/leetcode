#include<string>
class Solution {
public:
    int numberOfSubstrings(string s) {
        int counta = 0;
        int countb = 0;
        int countc = 0;
        int count = 0;
        int left = 0,right = 0;
        while(right<s.size())
        {
            if(s[right] == 'a') counta++;
            else if(s[right]=='b')countb++;
            else countc++;
            while(counta >= 1 && countb >= 1 && countc >= 1)
            {
                
                
                    count += (s.size()-right);
                    if(s[left] == 'a') counta--;
                    else if(s[left]=='b')countb--;
                    else countc--;

                    left++;
                
            }
            right++;
            
        }
        return count;
    }
};