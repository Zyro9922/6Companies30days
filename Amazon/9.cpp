class Solution {
public:
	bool checkValid(int x, int y, vector<vector<int>> &mat) {
		int cx = (x / 3) * 3;
		int cy = (y / 3) * 3;
		for (int i = cx; i < cx + 3; i++) {
			for (int j = cy; j < cy + 3; j++) {
				if (i != x && y != j && mat[x][y] == mat[i][j]) {
					return false;
				}
			}
		}

		for (int r = 0; r < 9; r++) {
			if (x != r && mat[r][y] == mat[x][y])
				return false;
		}

		for (int c = 0; c < 9; c++) {
			if (y != c && mat[x][c] == mat[x][y])
				return false;
		}
		return true;
	}
	int isValid(vector<vector<int>> mat) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (mat[i][j] != 0 && !checkValid(i, j, mat))
					return false;
			}
		}
		return true;
	}
};