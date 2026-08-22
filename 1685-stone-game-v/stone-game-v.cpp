class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Process smaller intervals first
        for (int len = 2; len <= n; len++) {

            for (int l = 0; l + len <= n; l++) {

                int r = l + len - 1;

                int k = l;
                int leftSum = 0;
                int total = prefix[r + 1] - prefix[l];

                while (k < r) {

                    leftSum += stoneValue[k];
                    int rightSum = total - leftSum;

                    if (leftSum < rightSum) {
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + dp[l][k]
                        );
                    }
                    else if (leftSum > rightSum) {
                        dp[l][r] = max(
                            dp[l][r],
                            rightSum + dp[k + 1][r]
                        );
                    }
                    else {
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + max(dp[l][k], dp[k + 1][r])
                        );
                    }

                    k++;
                }
            }
        }

        return dp[0][n - 1];
    }
};