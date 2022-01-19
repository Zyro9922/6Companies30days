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

string FirstNonRepeating(string str) {
	string result = "";
	class Node {
	public:
		char val;
		Node* prev = NULL;
		Node* next = NULL;
		Node(char val) {
			this->val = val;
		}
	};
	Node* head = NULL;
	Node* cur = NULL;
	map<char, Node*> map;
	int i = 0;
	while (str[i] != '\0') {
		if (map.find(str[i]) == map.end()) {
			map[str[i]] = new Node(str[i]);
			if (head == NULL) {
				head = map[str[i]];
			} else {
				cur->next = map[str[i]];
				map[str[i]]->prev = cur;
			}
			cur = map[str[i]];
		} else {
			if (map[str[i]]) {
				if (map[str[i]]->prev == NULL && map[str[i]]->next == NULL) {
					head = NULL;
				} else if (map[str[i]]->prev == NULL) {
					head = head->next;
					head->prev = NULL;
				}
				else if (map[str[i]]->next == NULL) {
					cur = cur->prev;
				}
				else if (map[str[i]]->prev && map[str[i]]->next) {
					map[str[i]]->next->prev = map[str[i]]->prev;
					map[str[i]]->prev->next = map[str[i]]->next;
				}
			}
			map[str[i]] = NULL;
		}
		result += head == NULL ? '#' : head->val;
		i++;
	}
	return result;
}

int main()
{
	string str;
	cin >> str;
	cout << FirstNonRepeating(str);
}