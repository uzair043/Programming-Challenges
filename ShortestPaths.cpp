#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

const int INF = 1000000000;

void FloydWarshal(int N, int graph[500][500]) {

	for (int k = 0; k<N; k++)
		for (int i = 0; i<N; i++)
			for (int j = 0; j<N; j++)
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

}


int main() {
	

	int N;
	cin >> N;

	static int graph[500][500];

	for (int i = 0; i<N; i++)
		for (int j = 0; j<N; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == -1)
				graph[i][j] = INF;
		}


	FloydWarshal(N, graph);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (graph[i][j] != INF)
				cout << graph[i][j] << " \n"[j == N - 1];
			else
				cout << "-1" << " \n"[j == N - 1];
	return 0;
}


