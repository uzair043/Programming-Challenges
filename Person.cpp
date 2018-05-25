#include <iostream>
#include <string>                                             
#include <fstream>
using namespace std;
class Person {
private:
	int ID;
	string Name;
	short Age;
public:
	Person()
	{
		ID = 0;
		Name = " ";
		Age = 0;
	}
	void Show()
	{
		cout << "ID : " << ID << endl;
		cout << "Age : " << Age << endl;
		cout << "Name : " << Name << endl;

	}
	friend istream& operator >> (istream& in, Person& P);
};
istream& operator >> (istream& in, Person& P)
{
	in >> P.ID >> P.Age >> P.Name;
	return in;
}

int main()
{
	Person *p;
	p = new Person[3];
	int size = 0, i = 0;
	ifstream infile("Temp.txt");
	if (!infile) {
		cout << "File does not exist.";
		exit(-1);
	}
	else
	{
		while (!infile.eof())
		{
			infile >> p[i];
			i++;
		}
	}
	
	for (int i = 0; i<3; i++)
	{
		p[i].Show();
	}
	infile.close();

	return 0;
}

