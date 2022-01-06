class Solution {
public:
	int *findTwoElement(int *arr, int n) {
		int repeating = -1, missing = -1;
		for (int i = 0; i < n; i++) {
			int key = abs(arr[i]) - 1;
			if (arr[key] < 0) {
				repeating = arr[i];
			} else {
				arr[key] = -arr[key];
			}
		}
		for (int i = 0; i < n; i++) {
			if (arr[i] > 0) {
				missing = i + 1;
				break;
			}
		}
		int *ans = new int[2];
		ans[0] = missing;
		ans[1] = repeating;
		return ans;
	}
};