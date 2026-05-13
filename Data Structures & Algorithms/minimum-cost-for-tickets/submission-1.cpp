class Solution {
    void dfs(int i, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if (i >= days.size()) return;          // 無旅行日，成本為 0（預設 dp 無此格，由呼叫者處理）
        if (dp[i] != -1) return;               // 已計算過

        dp[i] = INT_MAX;
        int j = i;
        vector<int> durs = {1, 7, 30};

        for (int k = 0; k < 3; ++k) {
            j = i;  // 每種票券都要重設游標
            while (j < days.size() && days[j] < days[i] + durs[k]) {
                ++j;
            }
            // 確保 dp[j] 已計算（若 j 超出範圍，代表後面無旅行日，花費 0）
            if (j < days.size()) {
                dfs(j, days, costs, dp);
                dp[i] = min(dp[i], costs[k] + dp[j]);
            } else {
                dp[i] = min(dp[i], costs[k]);
            }
        }
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       int n = days.size();
        vector<int> dp(n, -1);
        dfs(0, days, costs, dp);
        return dp[0];
    }
};