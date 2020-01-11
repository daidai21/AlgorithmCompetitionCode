class Solution {
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        // write your code here
        if (s.size() == 0)
            return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= (int)s.size(); ++i) {
            // last : one digit
            // s[i - 1]
            if (s[i - 1] != '0')
                dp[i] = dp[i - 1];
            // last : two digits
            // s[i - 1]s[i]
            if (i >= 2 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
                dp[i] += dp[i - 2];
        }
        return dp[dp.size() - 1];
    }
};
