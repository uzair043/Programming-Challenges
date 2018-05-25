#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main() {

	int W, N, size, value;
	cin >> W >> N;

	vector<int> Knapsack(W+1, 0);
	for (int i = 0; i<N; i++) {
		
		cin >> size >> value;

		for (int j = W; j >= size; j--)
			Knapsack[j] = max(Knapsack[j], Knapsack[j - size] + value);
	}

	cout << Knapsack[W] << endl;
	system("pause");
	return 0;
}

