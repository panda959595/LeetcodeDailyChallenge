#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int> > ret;
		for (int i = 0; i < numRows; i++) {
			vector<int> temp;
			if (i == 0) {
				temp.push_back(1);
				ret.push_back(temp);
				continue;
			}
			temp.push_back(1);

			for (int j = 0; j < i - 1; j++) {
				temp.push_back(ret[i - 1][j] + ret[i - 1][j + 1]);
			}


			temp.push_back(1);
			ret.push_back(temp);
		}
		return ret;
	}
};