#include<iostream>
#include<vector>
#include<deque>


using namespace std;


struct ConnectedComponent {
	struct Node {
		int size;
		Node* master;

		Node* getMaster() {
			if (master == this)
				return this;
			return master->getMaster();
		}
	};

	deque<Node> nodes;

	Node* addNode() {
		nodes.push_back({ 1, 0 });
		nodes.back().master = &nodes.back();
		return &nodes.back();
	}

	bool unite(Node* u, Node* v) {
		u = u->getMaster();
		v = v->getMaster();

		if (u == v)
			return false;
		if (u->size < v->size)
			swap(u, v);

		u->size += v->size;
		v->master = u;
		return true;
	}
};


int main() {


	int N, Q, query_type, u, v;
	cin >> N >> Q;

	ConnectedComponent cc;

	vector<ConnectedComponent::Node*> nodes;
	for (int i = 0; i<N; i++)
		nodes.push_back(cc.addNode());

	for (int i = 0; i<Q; i++) {

		cin >> query_type >> u >> v;
		u--, v--;

		if (query_type == 1)
			cc.unite(nodes[u], nodes[v]);
		else {
			if (nodes[u]->getMaster() == nodes[v]->getMaster())
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	system("pause");
	return 0;
}

