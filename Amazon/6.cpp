class Solution
{
public:
	//Function to find maximum of each subarray of size k.
	vector <int> max_of_subarrays(int *arr, int n, int k)
	{
		vector<int> nge(n);
		stack<int> st;
		st.push(INT_MAX);
		for (int i = n - 1; i >= 0; i--) {
			while (st.top() != INT_MAX && arr[st.top()] < arr[i])
				st.pop();
			nge[i] = st.top() == INT_MAX ? n : st.top();
			st.push(i);
		}
		vector<int> result;
		int i = 0, start = 0, end = k - 1;
		while (end < n) {
			if (i < start)
				i = start;
			if (nge[i] <= end) {
				i = nge[i];
			} else {
				result.push_back(arr[i]);
				++start;
				++end;
			}
		}
		return result;
	}
};