// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Stores the edges of the tree
vector<vector<int> > edges;

// Function to add edges
void add_edge(int x, int y)
{
	edges.push_back({ x, y });
}

// Function to merge two sorted vectors
vector<int> merge(vector<int>& a,
				vector<int>& b)
{
	// To store the result
	vector<int> res;

	int i = 0, j = 0;
	int n = a.size(), m = b.size();

	// Iterating both vectors
	while (i < n && j < m) {
		if (a[i] < b[j])
			res.push_back(a[i++]);
		else if (b[j] < a[i])
			res.push_back(b[j++]);
	}

	// Pushing remaining elements of
	// vector a
	while (i < n)
		res.push_back(a[i++]);

	// Pushing remaining elements of
	// vector b
	while (j < m)
		res.push_back(b[j++]);

	return res;
}

// Function to perform the DFS Traversal
// that returns the subtree of node
// in sorted manner
vector<int> help(vector<int> tree[], int x,
				int p, vector<int>& c,
				vector<int>& sol)
{
	vector<int> res;
	res.push_back(c[x]);

	// Iterate the childrens
	for (auto i : tree[x]) {

		// All values of subtree
		// i in sorted manner
		if (i != p) {
			vector<int> tmp
				= help(tree, i, x, c, sol);
			res = merge(res, tmp);
		}
	}

	int l = 0, r = res.size() - 1;
	int ans = res.size();

	// Binary search to find MEX
	while (l <= r) {
		// Find the mid
		int mid = (l + r) / 2;

		// Update the ranges
		if (res[mid] > mid)
			r = mid - 1;
		else {
			ans = mid + 1;
			l = mid + 1;
		}
	}
	if (res[0] != 0)
		ans = 0;

	// Update the MEX for the current
	// tree node
	sol[x] = ans;

	return res;
}

// Function to find MEX of each
// subtree of tree
void solve(int A, vector<int> C)
{
	int n = A;
	vector<int> tree[n + 1];
	for (auto i : edges) {
		tree[i[0]].push_back(i[1]);
		tree[i[1]].push_back(i[0]);
	}
	vector<int> sol(n, 0);

	// Function Call
	help(tree, 0, -1, C, sol);

	// Printe the ans for each nodes
	for (auto i : sol)
		cout << i << " ";
}

// Driver Code
int main()
{
	int N = 6;
	add_edge(0, 1);
	add_edge(1, 2);
	add_edge(0, 3);
	add_edge(3, 4);
	add_edge(3, 5);

	vector<int> val = { 4, 3, 5, 1, 0, 2 };
	solve(N, val);

	return 0;
}
