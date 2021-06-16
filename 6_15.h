#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	bool func(vector<long long> vec, vector<int> stick, int index, int size, long long len) {
		check++;
		if (index == size) {
			for (auto k : vec) {
				if (k != len) {
					return false;
				}
			}
			return true;
		}
		for (int i = 0; i < 4; i++) {
			bool ret = false;
			if (vec[i] + stick[index] <= len) {
				vec[i] += stick[index];
				ret |= func(vec, stick, index + 1, size, len);
				vec[i] -= stick[index];
			}
			if (ret) {
				return true;
			}
			if (vec[i] == 0) {
				break;
			}
		}
		return false;
	}
	bool makesquare(vector<int>& matchsticks) {
		long long len = 0;
		for (auto k : matchsticks) {
			len += k;
		}
		if (len % 4 != 0) {
			return false;
		}
		len /= 4;
		vector<long long> vec(4, 0);
		sort(matchsticks.begin(), matchsticks.end());
		reverse(matchsticks.begin(), matchsticks.end());
		bool ret = func(vec, matchsticks, 0, matchsticks.size(), len);

		cout << check << endl;
		return ret;
	}
	int check = 0;
};