string colName (long long int n)
{

	string result = "";
	while (n) {
		result = (char)('A' + (n - 1) % 26) + result;
		n = (n - 1) / 26;
	}
	return result;
}