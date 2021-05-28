#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> vec;
        for (auto str : words) {
            int temp = 0;
            for (char c : str) {
				temp |= (2 << (c - 'a'));
            }
            vec.push_back(temp);
        }
        int ret = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < i; j++) {
                if ((vec[i] & vec[j]) == 0) {
                    int temp = words[i].size() * words[j].size();
					ret = max(ret, temp);
                }
            }
        }
        return ret;
    }
};