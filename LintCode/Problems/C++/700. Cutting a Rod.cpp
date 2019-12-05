// https://www.lintcode.com/problem/cutting-a-rod/description


class Solution {
public:
    /**
     * @param prices: the prices
     * @param n: the length of rod
     * @return: the max value
     */
    int cutting(vector<int> &prices, int n) {
        // Write your code here
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                dp[j] = max(dp[j], dp[j - i] + prices[i - 1]);
            }
        }
        return dp[n];
    }
};


class Solution {
public:
    /**
     * @param prices: the prices
     * @param n: the length of rod
     * @return: the max value
     */
    int cutting(vector<int> &prices, int n) {
        // Write your code here
        vector<int> dp(n + 1);
        for (int i = n; i >= 1; --i) {
            for (int j = i; j <= n; ++j) {
                dp[j] = max(dp[j], dp[j - i] + prices[i - 1]);
            }
        }
        return dp[n];
    }
};

