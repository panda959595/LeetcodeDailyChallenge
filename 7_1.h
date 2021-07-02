#include <vector>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        ret.push_back(1);
        int temp = 1;
        for (int i = 2; i <= n; i++) {
            temp *= 2;
			for (int j = temp - 1; j >= 0; j--) {
                ret.push_back(temp + ret[j]);
            }
        }
        return ret;
    }
};