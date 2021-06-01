#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector< vector<string> > ret;
        vector<string> temp;
        sort(products.begin(), products.end());
        int s, e;
        s = 0;
        e = products.size();
        string str = "0";
		str[0] = searchWord[0];
        s = lower_bound(products.begin(), products.end(), str) - products.begin();
        str[0]++;
        e = lower_bound(products.begin(), products.end(), str) - products.begin();
        for (int i = 0; i < searchWord.length(); i++) {
            ret.push_back(temp);
            while (s < e) {
                if (products[s][i] == searchWord[i]) {
                    break;
                }
                else {
                    s++;
                }
            }
            while (s < e) {
                if (products[e - 1][i] == searchWord[i]) {
                    break;
                }
                else {
                    e--;
                }
            }
            for (int j = s; j < e; j++) {
                if (j - s == 3) {
                    break;
                }
                 ret[i].push_back(products[j]);
            }
        }
        return ret;
    }
};