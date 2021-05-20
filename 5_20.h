#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
		long long ret;
        sort(nums.begin(), nums.end());
		long long temp = 0;
        for (auto k : nums) {
            temp += k - nums[0];
        }
        int flag = 1;
        ret = temp;
        for (int i = 1; i < n; i++) {
            temp += 1LL * flag * (nums[i] - nums[i - 1]);
            temp -= 1LL * (n - flag) * (nums[i] - nums[i - 1]);
            ret = min(ret, temp);
            flag++;
        }

        return ret;
    }
};