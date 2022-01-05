class Solution {
public:
	int minSubArrayLen(int target, vector<int>& arr) {
		int i = 0, j = 0, n = arr.size();
		int result = INT_MAX;
		bool atLeastOne = false;
		int cur_sum = 0;
		while (j < n) {
			if (cur_sum >= INT_MAX - arr[j]) {
				i = j;
			}
			else if (cur_sum < target) {
				cur_sum += arr[j];
			}
			while (cur_sum >= target && i <= j) {
				atLeastOne = true;
				result = min(result, j - i + 1);
				cur_sum -= arr[i];
				i++;
			}
			j++;
		}
		return atLeastOne == false ? 0 : result == INT_MAX ? 0 : result;
	}
};