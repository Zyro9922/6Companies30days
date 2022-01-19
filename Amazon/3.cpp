/**
 * Muhammad Ali, one of my great heroes, had a great line
 * in the '70s when he was asked "How many sit-ups do you do?"
 * He said, "I don't count my sit-ups. I only start counting when
 * it starts hurting. When I feel pain, that's when I start counting
 * because that's when it really counts". That's what makes you a
 * champion. And that's the way it is with everything.
 * ~ Arnold Schwarzenegger
**/
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define fi              first
#define se              second
#define ll              long long
#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define min3(x,y,z)      (x < y ? (x < z ? x : z) : (y < z ? y : z))
#define mod             1000000007

// C++ template to print vector container elements
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1)  os << " ";
	}
	return os;
}

vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
	vector<int> result;
	deque<int> dq;
	for (int i = 0; i < k - 1; i++) {
		while (!dq.empty() && arr[dq.back()] < arr[i]) {
			dq.pop_back();
		}
		dq.push_back(i);
	}

	for (int i = 0; i <= n - k; i++) {
		int start = i;
		int end = i + k - 1;
		if (dq.front() < start)
			dq.pop_front();
		//Process new element
		while (!dq.empty() && arr[dq.back()] < arr[end]) {
			dq.pop_back();
		}
		dq.push_back(end);
		result.push_back(arr[dq.front()]);
	}
	return result;
}

int main()
{
	vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
	cout << max_of_subarrays(arr, arr.size(), 3);
}