#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N;
vector<pair<char, char>> tree(27);

void preorder(char x) {
	if (x != '.') {
		cout << x;
		preorder(tree[x - 'A'].first);
		preorder(tree[x - 'A'].second);
	}
}

void inorder(char x) {
	if (x != '.') {
		inorder(tree[x - 'A'].first);
		cout << x;
		inorder(tree[x - 'A'].second);
	}
}

void postorder(char x) {
	if (x != '.') {
		postorder(tree[x - 'A'].first);
		postorder(tree[x - 'A'].second);
		cout << x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		char parent, left, right;
		cin >> parent >> left >> right;

		tree[(parent - 'A')].first = left;
		tree[(parent - 'A')].second = right;
	}
	
	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	cout << "\n";

	return 0;
}