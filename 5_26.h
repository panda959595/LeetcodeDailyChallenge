#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sta;
        for (auto str : tokens) {
            if (str == "+") {
                int a = sta.top();
                sta.pop();
                int b = sta.top();
                sta.pop();
                sta.push(a + b);
            }
            else if (str == "-") {
                int a = sta.top();
                sta.pop();
                int b = sta.top();
                sta.pop();
				sta.push(b - a);
            }
            else if (str == "*") {
                int a = sta.top();
                sta.pop();
                int b = sta.top();
                sta.pop();
                sta.push(a * b);
            }
            else if (str == "/") {
                int a = sta.top();
                sta.pop();
                int b = sta.top();
                sta.pop();
				sta.push(b / a);
            }
            else {
                sta.push(stoi(str));
            }
        }
        return sta.top();
    }
};