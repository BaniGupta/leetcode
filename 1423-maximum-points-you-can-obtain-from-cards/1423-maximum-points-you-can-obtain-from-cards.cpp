class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left  = 0;
        int right = n-1;
        int score = 0;
        
        for(int i = 0;i<k;i++)
        {
            score+=cardPoints[left];
            left++;
        }
        left--;
        int temp = score;
        int maxsc= score;
        for(int i = 0;i<k;i++)
        {
            temp = temp - cardPoints[left];
            left--;
            temp += cardPoints[right];
            right--;
            maxsc = max(maxsc,temp);
        }
        return maxsc;
    }
};