/**METHOD 1
Priority Queue
Time: O(Nlog(K))
Space: O(K)
N = Billion Number
    k = 10number to find

METHOD 2
Let's say k = 2.
We know by maintaining 2 variables we can find max two number.
Similarly if k is very less we can maintain 10 variables or an array of size 10 and manipulate accordingly

Time: O(N)
Space: O(k)

For Max two we can
        **/
pair<int, int> maxTwo(vector<int> &arr) {
	int n = arr.size();
	int max = INT_MIN;
	int max2 = INT_MIN;
	for (int val : arr) {
		if (val > max) {
			max2 = max;
			max = val;
		} else if (val > max2) {
			max2 = val;
		}
	}
	return {max, max2};
}