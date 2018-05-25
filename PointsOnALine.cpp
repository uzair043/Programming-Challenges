#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	int N, M, query;
	long result;

	vector<long> points;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long val;
		cin >> val;

		points.push_back(val);
	}

	sort(points.begin(), points.end());

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> query;
		result = 2000000000;
		
		vector<long>::iterator it = lower_bound(points.begin(), points.end(), query);

		if(it != points.end())
			result = min(result, *it-query);
		if (it != points.begin())
			result = min(result, query - *(it - 1));

		cout << result << endl;
	}


	system("pause");
	return 0;
}