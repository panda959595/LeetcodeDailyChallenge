#include <string>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        check[0][0] = true;
        for (int i = 1; i <= s1.length(); i++) {
            if (check[i - 1][0] && s1[i - 1] == s3[i - 1]) {
                check[i][0] = true;
            }
            else {
                check[i][0] = false;
            }
        }
        for (int j = 1; j <= s2.length(); j++) {
            if (check[0][j - 1] && s2[j - 1] == s3[j - 1]) {
                check[0][j] = true;
            }
            else {
                check[0][j] = false;
            }
        }
        for (int i = 1; i <= s1.length(); i++) {
            for (int j = 1; j <= s2.length(); j++) {
                check[i][j] = false;
                if (check[i - 1][j] && s1[i - 1] == s3[i + j - 1]) {
                    check[i][j] = true;
                }
                if (check[i][j - 1] && s2[j - 1] == s3[i + j - 1]) {
                    check[i][j] = true;
                }
            }
        }
        if (check[s1.length()][s2.length()]) {
            return true;
        }
        else {
            return false;
        }
    }
    bool check[105][105];
};