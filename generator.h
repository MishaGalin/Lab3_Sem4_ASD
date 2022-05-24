#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Generator {
	bool Recursive(vector<int>, int max, int index = 0);
public:
	vector<int> ReadInput;
	vector<int> Result;
	Generator() {};
	void Read(vector<int>);
	void Find();
	void print();
};