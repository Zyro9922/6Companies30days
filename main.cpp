/**
 * Muhammad Ali, one of my great heroes, had a great line
 * in the '70s when he was asked "How many sit-ups do you do?"
 * He said, "I don't count my sit-ups. I only start counting when
 * it starts hurting. When I feel pain, that's when I start counting
 * because that's when it really counts". That's what makes you a
 * champion. And that's the way it is with everything.
 * ~ Arnold Schwarzenegger
**/
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define fi              first
#define se              second
#define ll              long long
#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl
#define min3(x,y,z)      (x < y ? (x < z ? x : z) : (y < z ? y : z))
#define mod             1000000007

// C++ template to print vector container elements
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1)  os << " ";
	}
	return os;
}


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



int main()
{
	string str;
	cin >> str;
	cout << encode(str);
}