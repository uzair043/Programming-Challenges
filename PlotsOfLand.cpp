#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct Plot {
	int w, h;

	bool operator < (Plot r) const {

		if (1LL * w*h != 1LL * r.w*r.h)
			return 1LL * w*h < 1LL  * r.w*r.h;
		return w < r.w;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int N, w, h, query;
	priority_queue<Plot> plots; 
	Plot p;

	cin >> N; 
	for (int i = 0; i < N; i++)
	{
		cin >> query;
		if (query == 1) {
			cin >> p.w;
			cin >> p.h;
			plots.push(p);
		}
		if (query == 2) {
			Plot p2 = plots.top();
			plots.pop();

			cout << p2.w << " " << p2.h << endl;
		}
		
	}



	system("pause");
	return 0;
}