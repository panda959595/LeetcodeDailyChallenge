#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		int x, y;
		horizontalCuts.push_back(0);
		horizontalCuts.push_back(h);
		verticalCuts.push_back(0);
		verticalCuts.push_back(w);
		sort(horizontalCuts.begin(), horizontalCuts.end());
		sort(verticalCuts.begin(), verticalCuts.end());
		x = 0;
		for (vector<int>::iterator ite = horizontalCuts.begin() + 1; ite != horizontalCuts.end(); ite++) {
			x = max(x, (*ite) - *(ite - 1));
		}
		y = 0;
		for (vector<int>::iterator ite = verticalCuts.begin() + 1; ite != verticalCuts.end(); ite++) {
			y = max(y, (*ite) - *(ite - 1));
		}
		return (1LL*x)*(1LL*y)% 1000000007;
	}
};