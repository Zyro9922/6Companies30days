Anagrams(vector<string>& arr) {
	int n = arr.size();
	vector<string> temp;
	map<string, vector<string>> map;
	for (string val : arr) {
		string unsorted = val;
		sort(val.begin(), val.end());
		string sorted = val;
		temp.push_back(sorted);
		map[sorted].push_back(unsorted);
	}
	int k = map.size();
	vector<vector<string>> result(k);
	int i = 0;
	for (auto val : map) {
		string key = val.first;
		vector<string> keyVal = val.second;
		for (string v : keyVal) {
			result[i].push_back(v);
		}
		++i;
	}
	return result;
}