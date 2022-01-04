countSubArrayProductLessThanK(const vector<int>& arr, int n, long long k) {
    int left = 0, right = 0;
    long long prod = 1;
    int result = 0;
    while (right < n) {
        prod *= arr[right];
        while (prod >= k) {
            prod /= arr[left++];
        }
        result += right - left + 1;
        ++right;
    }
    return result;
}