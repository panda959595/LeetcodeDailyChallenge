#include <string>
using namespace std;
class Solution {
public:
    int minPartitions(string n) {
        int ret = 0;
        for (int i = 0; i < n.length(); i++) {
            ret = max(ret, n[i] - '0');
        }
        return ret;
    }
};