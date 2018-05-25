#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;


struct Graph {
	struct Node {
		vector<Node*> arc;
		int d;
	};
	deque<Node> nodes;
	int n;

	Node* newNode() {
		nodes.push_back(Node());
		return &nodes.back();
	}
	void addArc(Node* u, Node* v) {
		u->arc.push_back(v);
		v->arc.push_back(u);
	}
	int dfs(Node* cur, Node* prev = 0) {
		int result = 0;
		for (Node* next : cur->arc)
			if (next != prev)
				result = max(result, dfs(next, cur) + 1);

		cur->d = result;
		return result;
	}
};


int main() {

	Graph g;
	vector<Graph::Node*> v;

	int n;
	cin >> n;

	for (int i = 0; i<n; i++)
		v.push_back(g.newNode());

	for (int i = 0; i<n - 1; i++) {
		int a, b;
		cin >> a >> b;
		g.addArc(v[a - 1], v[b - 1]);
	}

	g.dfs(v[0]);

	for (int i = 0; i<n; i++)
		cout << v[i]->d << " \n"[i == n - 1];

	system("pause");
	return 0;
}

