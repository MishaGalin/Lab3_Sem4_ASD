#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Optimal {
public:
	int N;
	vector<double> ReadInput;
	vector<vector<double>> Minimum;
	vector<vector<double>> Maximum;
	void Read(vector<double>);
	void Find(int);
	void print();
};