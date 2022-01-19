lass Solution{
public:
	vector<vector<string>> displayContacts(int n, string arr[], string str)
	{
		set<string> set;
		for (int i = 0; i < n; i++) {
			set.insert(arr[i]);
		}
		vector<string> contacts;
		for (string val : set) {
			contacts.push_back(val);
		}
		n = contacts.size();
		vector<vector<string>> result(str.size());
		vector<int> pointers(n, 0);
		for (int i = 0; str[i] != '\0'; i++) {
			for (int c = 0; c < n; c++) {
				if (pointers[c] != -1 && pointers[c] < contacts[c].size()) {
					if (contacts[c][pointers[c]] == str[i]) {
						result[i].push_back(contacts[c]);
						++pointers[c];
					} else {
						pointers[c] = -1;
					}
				}
			}
			if (result[i].size() == 0) {
				result[i].push_back("0");
			}
		}
		return result;
	}
};