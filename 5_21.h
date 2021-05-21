#include <vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	void inOrder(TreeNode* now, int level) {
		if (now == nullptr) {
			return;
		}
		if (vec.size() == level) {
			vector<int> temp;
			vec.push_back(temp);
		}
		vec[level].push_back(now->val);
		inOrder(now->left, level + 1);
		inOrder(now->right, level + 1);
	}
	vector<vector<int>> levelOrder(TreeNode* root) {
		inOrder(root, 0);
		return vec;
	}
private: vector< vector<int> > vec;
};