
string encode(string str)
{
	int i = 0;
	int count = 0;
	string result = "";
	while (i < str.size() + 1) {
		//If at an i
		//(i-1) and (i) differ -> change
		if (i == str.size() || (i > 0 && str[i] != str[i - 1])) {
			result += str[i - 1];
			result += to_string(count);
			count = 0;
		}
		++count;
		++i;
	}
	return result;
}