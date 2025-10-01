class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);  // dp[i] = number of new people who learn on day i
        vector<long long> share(n + 2, 0); // to manage sliding window of sharers

        dp[1] = 1;           // on day 1, one person knows
        share[1 + delay] = 1; // they start sharing after delay days
        share[1 + forget] = (share[1 + forget] - 1 + MOD) % MOD; // they forget after forget days

        for (int day = 2; day <= n; day++) {
            share[day] = (share[day] + share[day - 1]) % MOD; // accumulate
            dp[day] = share[day]; // new learners today

            // these new learners will share later
            if (day + delay <= n) {
                share[day + delay] = (share[day + delay] + dp[day]) % MOD;
            }
            if (day + forget <= n) {
                share[day + forget] = (share[day + forget] - dp[day] + MOD) % MOD;
            }
        }

        long long ans = 0;
        // Count people who still remember at day n
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) ans = (ans + dp[i]) % MOD;
        }
        return (int)ans;
    }
};
