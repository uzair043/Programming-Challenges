#include<iostream>

#define MAX 8

using namespace std;


int main() {

	int N, K;
	int a[100] = {0};
	int remain[100] = {0};


	cin >> N >> K; 

	for (size_t i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	int min_days = 0;

	for (size_t i = 0; i < N; i++)
	{
		if (K > 0) {
			if (a[i] >= MAX && K > MAX) {
				K -= MAX;
				min_days++;
			}
			else if (a[i - 1] >= MAX && K > MAX) {
				K -= MAX;
				min_days++;
			}
			else {
				K -= a[i];
				min_days++;
			}
		}
	}

	if (K > 0)
		cout << -1 << endl;
	else
		cout << min_days << endl;

	system("pause");
	return 0;
}