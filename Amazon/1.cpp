int longestMountain(vector<int>& arr) {
	int n = arr.size(), p = 0, q = 1, result = 0;
	while (q < n) {
		int left = 1, right = 0;
		while (q < n && arr[p] < arr[q]) {
			++left, ++p, ++q;
		}
		if (left > 1) {
			while (q < n && arr[p] > arr[q]) {
				++right, ++p, ++q;
			}
		}
		if (left > 1 && right > 0) {
			result = max(result, left + right);
		} else {
			++p, ++q;
		}
	}
	return result;
}