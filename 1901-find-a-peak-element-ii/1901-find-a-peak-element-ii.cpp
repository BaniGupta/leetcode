class Solution {
public:
    int maxel(vector<vector<int>>& mat, int m, int mid)
{
    int row = 0;
    for(int i = 1; i < m; i++)
    {
        if(mat[i][mid] > mat[row][mid])
            row = i;
    }
    return row;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int low = 0;
        int high = n-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int row = maxel(mat,m,mid);

            int left = mid-1 >= 0 ? mat[row][mid-1] : -1;
            int right = (mid+1 < n)? mat[row][mid+1] : -1;

            if(mat[row][mid] > left && mat[row][mid]> right)
            return {row,mid};

            else if(mat[row][mid] > left ) low = mid +1;
            else high = mid-1;
        }
        return {-1,-1};
    }
};