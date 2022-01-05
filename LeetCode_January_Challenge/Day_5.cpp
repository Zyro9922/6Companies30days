class Solution {
public:
	vector<vector<string>> isPalindrome;
	vector<vector<string>> result;

	void partition(string str, int i, vector<string> ongoing, int n) {
		if (i == n) {
			result.push_back(ongoing);
			return;
		}
		for (int len = 1, j = i + len - 1; j < n; j++) {
			if (isPalindrome[i][j] != "#") {
				ongoing.push_back(isPalindrome[i][j]);
				partition(str, j + 1, ongoing, n);
				ongoing.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string str) {
		int n = str.size();
		isPalindrome.resize(n, vector<string>(n, "#"));

		for (int len = 1; len <= n; len++) {
			for (int i = 0, j = i + len - 1; i < n && j < n; i++, j++) {
				if (len == 1) {
					string oneLetter = "";
					oneLetter += str[i];
					isPalindrome[i][j] = oneLetter;
				}
				else if (len == 2 && str[i] == str[j]) {
					string twoLetter = "";
					twoLetter += str[i];
					twoLetter += str[j];
					isPalindrome[i][j] = twoLetter;
				}
				else if (str[i] == str[j] && isPalindrome[i + 1][j - 1] != "#") {
					isPalindrome[i][j] = str[i] + isPalindrome[i + 1][j - 1] + str[j];
				}
			}
		}

		vector<string> ongoing;
		partition(str, 0, ongoing, n);

		return result;
	}
};