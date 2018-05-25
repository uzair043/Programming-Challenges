#include<iostream>
#include<vector>
#include<algorithm>


#define f first
#define s second
#define mp make_pair
#define INF 2000000000
using namespace std;



//--------------------------------------------------------------------------------------
//Segment tree structure

struct SegmentTree {
	vector<int> data;
	vector<pair<int, int> > segment;

	//Initialize segment tree
	void init(int size) {
		int tpow = 1;
		while (tpow < size) tpow *= 2;

		data.resize(tpow * 2, -INF);
		segment.resize(tpow * 2);

		//Initialize the segments
		for (int i = 0; i<tpow; i++)
			segment[tpow + i] = mp(i, i + 1);

		for (int i = tpow - 1; i>0; i--)
			segment[i] = mp(segment[2 * i].f, segment[2 * i + 1].s);

	}


	//-----------------------------------------------------
	//Setting operation
	void set(int pos, int nval, int treePos = 1) {
		int &curData = data[treePos];
		pair<int, int> &curSegment = segment[treePos];

		if (pos + 1 <= curSegment.f || curSegment.s <= pos)
			return;

		if (pos == curSegment.f && pos + 1 == curSegment.s) {
			curData = nval;
			return;
		}


		//Recursion here
		set(pos, nval, treePos * 2);
		set(pos, nval, treePos * 2 + 1);

		curData = max(data[treePos * 2], data[treePos * 2 + 1]);
	}

	//---------------------------------------------------
	//Query operation
	int get(int l, int r, int treePos = 1) {
		int &curData = data[treePos];
		pair<int, int> &curSegment = segment[treePos];

		if (r <= curSegment.f || curSegment.s <= l)
			return -INF;

		if (l <= curSegment.f && curSegment.s <= r)
			return curData;

		//Perform recursion
		int ret = max(get(l, r, treePos * 2),
			get(l, r, treePos * 2 + 1));

		//Update
		data[treePos] = max(data[treePos * 2], data[treePos * 2 + 1]);
		return ret;
	}




};








int main() {
	int n, m, o, p1, p2;

	cin >> n >> m;
	SegmentTree stree;
	stree.init(n);

	for (int i = 0; i<n; i++) {
		cin >> p1;
		stree.set(i, p1);
	}


	for (int OPERATION = 0; OPERATION < m; OPERATION++) {
		cin >> o >> p1 >> p2;

		if (o == 1)
			stree.set(p1 - 1, stree.get(p1 - 1, p1) + p2);

		if (o == 2)
			stree.set(p1 - 1, p2);

		if (o == 3)
			cout << stree.get(p1 - 1, p2) << '\n';
	}


	return 0;
}