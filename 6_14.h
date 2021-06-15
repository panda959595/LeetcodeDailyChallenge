#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	static bool compare(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int ret = 0;
        for (auto k : boxTypes) {
			ret += min(truckSize, k[0]) * k[1];
            truckSize -= min(truckSize, k[0]);
            if (truckSize == 0) {
                break;
            }
        }
        return ret;
    }
};