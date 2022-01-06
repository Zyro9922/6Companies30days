class Solution {
public:
	string printMinNumberForPattern(string str) {
		// code here
		string result = "";
		int n = str.size(), count = 1, d = 1;
		for (int i = 0; i <= n; i++) {
			if (str[i] == 'I' || str[i] == '\0') {
				string ans = "";
				if (d < count) {
					while (d <= count) {
						ans = to_string(count++) + ans;
					}
				}
				else {
					while (count <= d) {
						ans = to_string(count++) + ans;
					}
				}
				result += ans;
			}
			d++;
		}
		return result;
	}
};