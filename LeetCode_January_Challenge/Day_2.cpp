class Solution {
public:
	int numPairsDivisibleBy60(vector<int>& arr) {
		int n = arr.size();
		map<int, int> map;
		for (int val : arr)
			++map[val % 60];

		int result = 0;
		for (int val : arr) {
			val = val % 60;
			if (val != 30 && map.find(60 - val) != map.end()) {
				result += map[60 - val];
			}
		}
		result /= 2;
		result += (map[0] * (map[0] - 1)) / 2 + (map[30] * (map[30] - 1)) / 2;
		return result;
	}
};