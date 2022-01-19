
class Solution
{
public:
	//Function to serialize a tree and return a list containing nodes of tree.
	vector<int> result;
	vector<int> serialize(Node *root)
	{
		if (root == NULL) {
			result.push_back(-1);
			return {};
		}

		result.push_back(root->data);
		serialize(root->left);
		serialize(root->right);

		return result;
	}

	//Function to deserialize a list and construct the tree.
	int idx = 0;
	Node * deSerialize(vector<int> &A)
	{
		int val = A[idx++];
		if (val == -1)
			return NULL;

		Node* root = new Node(val);
		root->left = deSerialize(A);
		root->right = deSerialize(A);
		return root;
	}

};