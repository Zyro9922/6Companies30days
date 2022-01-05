class Solution {
public:
	string intToComplementBinary(int n) {
		if (n == 0 || n == 1)
			return to_string(!n);
		return intToComplementBinary(n / 2) + to_string(!(n % 2));
	}

	int bitwiseComplement(int n) {
		if (n == 0 || n == 1)
			return !n;
		int ans = 0, k = 0;
		while (n) {
			ans = ans + pow(2, k++) * !(n % 2);
			n /= 2;
		}
		return ans;
	}
};