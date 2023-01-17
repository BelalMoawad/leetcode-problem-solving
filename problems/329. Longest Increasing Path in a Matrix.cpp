// Link to problem : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

// code

class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int n, m;
    vector<vector<int> > dp;

    bool valid (int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int solve (int i, int j, vector<vector<int>>& matrix) {

        int &ret = dp[i][j];
        if(~ret) return ret;

        ret = 1;
        for (int k = 0; k < 4; ++k) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(valid(ni, nj) && matrix[i][j] < matrix[ni][nj])
                ret = max(ret, 1 + solve(ni, nj, matrix));
        }
        return ret;
    };
public:

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = (int) matrix.size(), m = (int) matrix[0].size();
        dp = vector<vector<int> > (n, vector<int>(m, -1));
        int mxPath = 1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                mxPath = max(mxPath, solve(i, j, matrix));
        return mxPath;
    }
};
