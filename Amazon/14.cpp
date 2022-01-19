/**
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

// C++ template to print vector container elements
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	for (int i = 0; i < v.size(); ++i) {
		os << v[i];
		if (i != v.size() - 1)  os << ", ";
	}
	return os;
}

class TreeNode {
public:
	int val;
	TreeNode* left = NULL;
	TreeNode* right = NULL;

	TreeNode(int data) : val(data) {}
};

// C++ template to print Tree
ostream& operator<<(ostream& os, TreeNode* root) {
	stack<pair<TreeNode*, int>> stack;

	stack.push({root, 1});

	vector<int> pre;
	vector<int> in;
	vector<int> post;

	while (!stack.empty()) {
		pair<TreeNode*, int> top = stack.top();

		switch (top.second) {
		case 1:
			pre.push_back(top.first->val);
			++stack.top().second;
			if (top.first->left)
				stack.push({top.first->left, 1});
			break;
		case 2:
			in.push_back(top.first->val);
			++stack.top().second;
			if (top.first->right)
				stack.push({top.first->right, 1});
			break;
		case 3:
			post.push_back(top.first->val);
			++stack.top().second;
			break;
		case 4:
			stack.pop();
		}
	}
	os << "Tree print:\n";
	os << "Pre: " << pre << endl;
	os << "Ino: " << in << endl;
	os << "Pos: " << post << endl;
	return os;
}

/**
1 2 . . 3 . .

27 10 4 . . 6 . . 3 . 3 . .

2 2 7 5 13 . . . 2 . . 10 . 14 . . 13 1 5 . . 11 . . 10 5 . . .

10 20 40 . . 50 80 . . 90 . . 30 60 100 . . . 70 110 . . 120 . .

7 8 1 6 . . 7 . . 3 6 . . 19 . . 9 2 4 22 . . . 1 . . 19 -10 . . 10 . 21 . .
**/

TreeNode* buildTree()
{
	string str;
	cin >> str;

	if (str == ".")
		return NULL;

	int d = stoi(str);

	TreeNode* root = new TreeNode(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;

}

int height(TreeNode* root) {
	if (root == NULL)
		return -1;

	if (root->left == NULL && root->right == NULL)
		return 0;

	return std::max(height(root->left), height(root->right)) + 1;
}

int maxTime = 0;
int burn(TreeNode* root, int target)
{
	if (root == NULL)
		return 0;
	if (root->val == target) {
		maxTime = height(root);
		return 1;
	}
	int leftAns = burn(root->left, target);
	if (leftAns > 0) {
		maxTime = max(maxTime, leftAns + height(root->right) + 1);
		return leftAns + 1;
	}

	int rightAns = burn(root->right, target);
	if (rightAns > 0) {
		maxTime = max(maxTime, rightAns + height(root->left) + 1);
		return rightAns + 1;
	}
	return 0;
}

int minTime(TreeNode* root, int target)
{
	burn(root, target);
	return maxTime;
}

//BFS BELOW
class Solution {
public:
	void buildGraph(Node* root, Node* parent, int target, map<Node*, Node*> &parentMap, Node* &targetNode) {
		if (root == NULL)
			return;

		if (root->data == target) {
			targetNode = root;
		}

		parentMap[root] = parent;

		buildGraph(root->left, root, target, parentMap, targetNode);
		buildGraph(root->right, root, target, parentMap, targetNode);
	}

	int minTime(Node* root, int target)
	{
		map<Node*, Node*> parentMap;
		Node* targetNode = NULL;
		buildGraph(root, NULL, target, parentMap, targetNode);
		queue<Node*> q;
		map<Node*, bool> visited;
		q.push(targetNode);
		int level = -1;
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				Node* parent = q.front(); q.pop();
				// deb2("Parent", parent->val);
				if (visited[parent] == true)
					continue;
				visited[parent] = true;
				if (parent->left && !visited[parent->left]) {
					q.push(parent->left);
					// deb(parent->left->val);
				}
				if (parent->right && !visited[parent->right]) {
					q.push(parent->right);
					// deb(parent->right->val);
				}
				if (parentMap[parent] && !visited[parentMap[parent]]) {
					q.push(parentMap[parent]);
					// deb(parentMap[parent]->val);
				}
			}
			++level;
			// deb(level);
			// cout << endl << endl;

		}
		return level;
	}
};

int main()
{
	TreeNode* root = buildTree();
	cout << minTime(root, 1);
}