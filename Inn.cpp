#include <iostream>
#include<set>
#include<algorithm>
#include<string>

using namespace std;


int main() {

	long N; int query;
	string name; 
	set<string> names;

	cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		cin >> query;

		if (query == 1) {
			cin >> name; 
			names.insert(name);
		}
		else if (query == 2) {
			cin >> name;
			names.erase(name);
		}
		else {
			cin >> name;
			if (names.count(name))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	system("pause");
	return 0;
}