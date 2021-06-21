#include <vector>
using namespace std;
class Solution {
public:
	pair<int, int> find(pair<int, int> u) {
		if (u == parent[u.first][u.second]) {
			return u;
		}
		else {
			return parent[u.first][u.second] = find(parent[u.first][u.second]);
		}
	}
	void merge(pair<int, int> u, pair<int, int> v) {
		if (u == v) {
			return;
		}
		parent[u.first][u.second] = v;
	}
	int swimInWater(vector<vector<int>>& grid) {
		int n = grid.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				parent[i][j] = { i,j };
				arr[grid[i][j]] = { i,j };
			}
		}
		for (int i = 0; i < n * n; i++) {
			pair<int, int> now = arr[i];
			for (int j = 0; j < 4; j++) {
				pair<int, int> temp;
				temp.first = now.first + dxy[j].first;
				temp.second = now.second + dxy[j].second;
				if (temp.first < 0 || temp.first >= n || temp.second < 0 || temp.second >= n) {
					continue;
				}
				if (grid[temp.first][temp.second] > i) {
					continue;
				}
				pair<int, int> u = find(now);
				pair<int, int> v = find(temp);
				merge(u, v);
			}
			if (find({ 0,0 }) == find({ n - 1,n - 1 })) {
				return i;
			}
		}
		return n * n - 1;
	}
	pair<int, int> parent[55][55];
	pair<int, int> arr[2505];
	pair<int, int>  dxy[4] = { {0,1},{0,-1},{1,0},{-1,0 } };
};