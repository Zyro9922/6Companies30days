class Solution {
public:
	int maxCoins(vector<int>& nums) {
		// insert 1 at begin and end
		nums.insert(nums.begin(), 1);
		nums.push_back(1);

		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));

		for (int len = 1; len < n; len++) {
			for (int i = 1; i < n - len; i++) {
				int j = i + len;
				int min_cost = INT_MIN;

				for (int k = i; k < j; k++) {
					int cost = dp[i][k] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j];
					min_cost = max(min_cost, cost);
				}
				dp[i][j] = min_cost;
			}
		}

		return dp[1][n - 1];
	}
};