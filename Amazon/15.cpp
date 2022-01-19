class Solution
{
public:
	void linkdelete(struct Node  *head, int mx, int nx)
	{
		while (head) {
			int M = mx, N = nx;
			Node* A = head; //will point to Mth node
			--M;
			while (A && M--)
				A = A->next;
			if (A == NULL)
				return;
			Node* B = A->next; //will point to Nth node + 1
			while (B && N--)
				B = B->next;
			A->next = B;
			head = B;
		}
	}
};