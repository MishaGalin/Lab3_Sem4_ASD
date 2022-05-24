#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Dinamic {
public:
    vector<int> ReadInput;
    vector<int> Result;
    Dinamic() {};
    void Read(vector<int>);
    void Find();
    void print();
};