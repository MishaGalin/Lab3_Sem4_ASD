#include <iostream>
#include "generator.h"
#include "dinamic.h"
#include "optimal.h"
#include <fstream>
using namespace std;

int main()
{
	vector<int> input{ -2,5,-1,3,4,0,-3,-4,2,1,0 };
	Generator a;
	a.Read(input);
	a.Find();
	a.print();
	cout << endl;

	Dinamic b;
	b.Read(input);
	b.Find();
	b.print();
	cout << endl;
	vector<double> input2{ 0.8, 1, 0, 5, 2.5, 20, 0.05 };

	Optimal c;
	c.Read(input2);
	c.print();
	cout << endl;

	return 0;
}