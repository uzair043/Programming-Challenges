#include<iostream>
#include<vector>
#include<deque>
using namespace std;


struct Graph {
	struct Node {
		vector<Node*> arc;
		bool explored = false;
		int dist;
	};
	deque<Node> nodes;

	Node* newNode() {
		nodes.push_back(Node());
		return &nodes.back();
	}
	void addArc(Node* u, Node* v) {
		u->arc.push_back(v);
		v->arc.push_back(u);
	}
	long long BFS(Node* start) {
		deque<Node*> que(1, start);
		start->explored = true;
		start->dist = 0;
		long long result = 0;

		while (que.size() > 0) {
			Node* cur = que.front();
			que.pop_front();
			result += cur->dist;

			for (Node* next : cur->arc)
				if (!next->explored) {
					next->explored = true;
					next->dist = cur->dist + 1;
					que.push_back(next);
				}
		}
		return result;
	}
};


int main() {

	Graph g;
	vector<Graph::Node*> v;

	int n, m, s;
	cin >> n >> m >> s;

	for (int i = 0; i<n; i++)
		v.push_back(g.newNode());

	for (int i = 0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		g.addArc(v[a - 1], v[b - 1]);
	}

	cout << g.BFS(v[s - 1]) << '\n';

	return 0;
}

