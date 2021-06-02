#include <vector>
using namespace std;
class Solution {
public:
	int func(int x, int y) {
		int ret = 1;
		check[x][y]++;
		for (int i = 0; i < 4; i++) {
			int X = x + dx[i];
			int Y = y + dy[i];
			if (X < 0 || X >= check.size() || Y < 0 || Y >= check[0].size()) {
				continue;
			}
			if (check[X][Y] == 10) {
				ret += func(X, Y);
			}
		}
		return ret;
	}
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		for (int i = 0; i < grid.size(); i++) {
			vector<int> temp;
			for (int j = 0; j < grid[i].size(); j++) {
				temp.push_back(grid[i][j] * 10);
			}
			check.push_back(temp);
		}
		int ret = 0;
		for (int i = 0; i < check.size(); i++) {
			for (int j = 0; j < check[i].size(); j++) {
				if (check[i][j] == 10) {
					int temp = func(i, j);
					ret = max(ret, temp);
				}
			}
		}
		return ret;
	}
	vector< vector<int> > check;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
};