#include<iostream>
#include<vector>
using namespace std;


template<int N>
class SS {

private:
	
	long long values[N];

public :

	long long get(int pos) {
		if (pos == 0)
			return 0;
		
		return values[pos] + get(pos - (pos & -pos));
	}

	void add(int pos, int addVal) {
		if (pos >= N)
			return;
		
		values[pos] += addVal;
		add(pos + (pos & -pos), addVal);
	}

};

int N, M, val, operation, op1, op2;
SS<100001> ss;


int main() {
	cin.sync_with_stdio(false);



	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> val;
		ss.add(i, val);
	}
		
	for (int  a = 0; a < M; a++) {
		cin >> operation >> op1 >> op2;

		if (operation == 1)
			ss.add(op1, op2);
		else if (operation == 2)
			ss.add(op1, op2 - (ss.get(op1) - ss.get(op1 - 1)));
		else
			cout << ss.get(op2) - ss.get(op1 - 1) << endl;
	}

	system("pause");
	return 0;
}

