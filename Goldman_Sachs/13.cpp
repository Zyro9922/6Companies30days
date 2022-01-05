string decodedString(string str) {
	stack<int> numbers;
	stack<string> words;
	int n = str.size();
	for (int i = 0; i < n; i++) {
		char c = str[i];
		// deb(c);
		if (c >= '0' && c <= '9') {
			string number = "";
			while (c >= '0' && c <= '9') {
				number += c;
				c = str[++i];
			}
			--i;
			numbers.push(stoi(number));
		} else if (c == '[') {
			words.push("[");
		} else if (c >= 'a' && c <= 'z') {
			string word = "";
			while (c >= 'a' && c <= 'z') {
				word += c;
				c = str[++i];
			}
			--i;
			words.push(word);
		} else if (c == ']') {
			int number = numbers.top(); numbers.pop();
			string word = "";
			// deb(number);
			while (words.top() != "[") {
				word = words.top() + word;
				words.pop();
			}
			words.pop();
			// deb(word);
			string numWord = "";
			while (number--)
				numWord += word;
			// deb(numWord);
			words.push(numWord);
			// cout << endl;

		}
	}
	return words.top();
}