class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		map<int, int> m;
		int maxp = 0;
		for (auto& t : trips) m[t[1]] += t[0], m[t[2]] -= t[0];
		for (auto x : m)
			if ((maxp += x.second) > capacity) return false;
		return true;
	}
};