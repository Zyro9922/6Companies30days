class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		queue<pair<int, int>> rotten;
		int fresh = 0;

		int row = grid.size();
		int col = grid[0].size();

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == 1) {
					++fresh;
				} else if (grid[i][j] == 2) {
					rotten.push({i, j});
				}
			}
		}

		if (fresh == 0) return 0;

		vector<vector<int>> d = {{ -1, 0}, {0, +1}, { +1, 0}, {0, -1}};
		int time = 0;
		while (fresh > 0 && !rotten.empty()) {
			int size = rotten.size();

			for (int i = 0; i < size; i++) {
				pair<int, int> parent = rotten.front(); rotten.pop();

				for (int j = 0; j < 4; j++) {
					int nx = parent.first + d[j][0];
					int ny = parent.second + d[j][1];

					if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 1) {
						grid[nx][ny] = 2;
						--fresh;
						rotten.push({nx, ny});
					}
				}
			}

			++time;
		}
		return fresh == 0 ? time : -1;
	}
};