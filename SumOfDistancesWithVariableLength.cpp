#include<iostream>
#include<vector>
#include<deque>
#include<tuple>
#include<queue>
using namespace std;


struct Graph {
	struct Node;
	struct Arc {
		Node* dest;
		int l;
	};
	struct Node {
		vector<Arc> arc;
		bool explr = false;
		long long dist;
	};
	deque<Node> nodes;

	Node* addNode() {
		nodes.push_back(Node());
		return &nodes.back();
	}
	void addEdge(Node* u, Node* v, int l) {
		u->arc.push_back({ v, l });
		v->arc.push_back({ u, l });
	}

	long long Dijkstra(Node* start) {
		priority_queue<pair<long long, Node*> > frontier;
		frontier.push({ 0, start });
		long long result = 0;

		while (frontier.size() > 0) {
			long long potential; Node* cur;
			tie(potential, cur) = frontier.top();
			frontier.pop();

			if (cur->explr)
				continue;
			cur->explr = true;
			cur->dist = -potential;
			result += cur->dist;

			for (Arc curArc : cur->arc)
				frontier.push({ potential - curArc.l, curArc.dest });
		}
		return result;
	}
};


int main() {


	Graph g;
	vector<Graph::Node*> nodes;

	int n, m, s;
	cin >> n >> m >> s;
	for (int i = 0; i<n; i++)
		nodes.push_back(g.addNode());

	for (int i = 0; i<m; i++) {
		int u, v, l;
		cin >> u >> v >> l;
		g.addEdge(nodes[u - 1], nodes[v - 1], l);
	}

	cout << g.Dijkstra(nodes[s - 1]) << '\n';
	return 0;
}

