#include<iostream>

using namespace std;


int main() {

	bool coin[100001] = { 0 };
	coin[0] = 1;
	int N, Q, dVal, query;

	cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		cin >> dVal;
		for (size_t i = dVal; i < 100001; i++)
		{
			if (coin[i - dVal] == 1) {
				coin[i] = 1;
			}
		}
	}

	cin >> Q;

	for (size_t i = 0; i < Q; i++)
	{
		cin >> query;

		if (coin[query] == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	system("pause");

	return 0;

}