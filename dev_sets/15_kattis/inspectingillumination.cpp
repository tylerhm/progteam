#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

struct node {
	vector<int> queries;
	set<int> kept;
	struct node* left = nullptr;
	struct node* right = nullptr;
	struct node* parent = nullptr;
	bool complete = false;

	void pruneResults(vector<int> results) {
		for (int i : results)
			if (parent->kept.count(i))
				kept.insert(i);
	}
};

void getQueries(node *curNode, vector<int> &leftQueries, vector<int> &rightQueries, bool isLeft) {
	if (curNode->left == nullptr && curNode->right == nullptr) {
		if (isLeft) {
			for (int i : curNode->queries)
				leftQueries.push_back(i);
		}
		else {
			for (int i : curNode->queries)
				rightQueries.push_back(i);
		}
	}
	else {
		getQueries(curNode->left, leftQueries, rightQueries, true);
		getQueries(curNode->right, leftQueries, rightQueries, false);
	}
}

void createLeafs(node *curNode) {
	if (curNode->left == nullptr && curNode->right == nullptr) {
		if (curNode->kept.size() == 1) return;
		curNode->left = new node();
		curNode->right = new node();

		int sz = curNode->queries.size();
		int leftSz = (sz/2);
		int rightSz = leftSz;
		if (sz&1) rightSz++;

		for (int i = 0; i < leftSz; i++)
			curNode->left->queries.push_back(curNode->queries[i]);
		for (int i = leftSz; i < leftSz+rightSz; i++)
			curNode->right->queries.push_back(curNode->queries[i]);


		curNode->left->parent = curNode;
		curNode->right->parent = curNode;
	}
	else {
		createLeafs(curNode->left);
		createLeafs(curNode->right);
	}
}

void pruneLeaves(node *curNode, vector<int> &leftRes, vector<int> &rightRes, bool isLeft) {
	if (curNode->left == nullptr && curNode->right == nullptr) {
		if (curNode->complete) return;
		if (isLeft)
			curNode->pruneResults(leftRes);
		else
			curNode->pruneResults(rightRes);

		if (curNode->kept.size() == 1)
			curNode->complete = true;
	}
	else {
		pruneLeaves(curNode->left, leftRes, rightRes, true);
		pruneLeaves(curNode->right, leftRes, rightRes, false);
	}
}

bool smallChildren(node *curNode) {
	if (curNode->left == nullptr && curNode->right == nullptr)
		return curNode->kept.size() == 1;
	return smallChildren(curNode->left) && smallChildren(curNode->right);
}

void getAns(node *curNode, vector<int> &ans) {
	if (curNode == nullptr) return;
	if (curNode->left == nullptr && curNode->right == nullptr)
		ans.push_back(*(curNode->kept.begin()));
	getAns(curNode->left, ans);
	getAns(curNode->right, ans);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n; cin >> n;
	node *head = new node();
	for (int i = 1; i <= n; i++) {
		head->queries.push_back(i);
		head->kept.insert(i);
	}
	
	// get all left queries together into one query
	createLeafs(head);
	//map<int, vector<vector<int>>> levels;
	while (true) {
		vector<int> leftQuery, rightQuery;
		getQueries(head, leftQuery, rightQuery, true);


		// make queries
		cout << "ASK ";
		cout << leftQuery.size() << ' ';
		for (int i : leftQuery) cout << i << ' ';
		cout << endl;

		vector<int> leftRes(leftQuery.size());
		for (auto &x : leftRes) cin >> x;

		cout << "ASK ";
		cout << rightQuery.size() << ' ';
		for (int i : rightQuery) cout << i << ' ';
		cout << endl;

		vector<int> rightRes(rightQuery.size());
		for (auto &x : rightRes) cin >> x;

		// go through each leaf, prune results
		pruneLeaves(head, leftRes, rightRes, true);

		if (smallChildren(head)) break;

		// create new leafs
		createLeafs(head);
	}

	vector<int> ans;
	getAns(head, ans);
	cout << "ANSWER ";
	for (int i : ans) cout << i << ' ';
	cout << endl;


    return 0;
}
