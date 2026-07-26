class Solution {
public:
    int reverse(int x) {
        long long reversed = 0;

        while(x != 0)
        {
            int rem = x % 10;
            reversed = reversed * 10 + rem;
            x = x / 10;
        }

        if(reversed > INT_MAX || reversed < INT_MIN)
            return 0;

        return (int)reversed;
    }
};