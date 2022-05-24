#include "Generator.h"

template <class T>
void Print(T someList) {
	for (auto& x : someList) cout << " " << x;
	cout << endl;
}

void Generator::Read(vector<int> input)
{
	if (input.size() == 0)
	{
		cout << "Vector don't input" << endl;
		exit(0);
	}
	else ReadInput = input;
}

bool Generator::Recursive(vector<int> combination, int max, int index)
{
	// последний элемент
	if (index == ReadInput.size())
	{
		if (combination.size() > Result.size())
			Result = combination;
		return false;
	}

	// если элемент нам подходит, т.е. последовательность убывающая, т.е. первый элемент не больше найденного максимума и он первый,
	// либо данный элемент меньше максимума на 2
	if (ReadInput[index] <= max && combination.size() == 0 || max - ReadInput[index] == 2)
	{
		vector<int> temp = combination;
		temp.push_back(ReadInput[index]);
		int tempMax = ReadInput[index]; // новый максимум теперь этот элемент
		if (index < ReadInput.size())
			Recursive(temp, tempMax, index + 1);
	}

	// рассматриваем следующий элемент
	if (index < ReadInput.size())
		Recursive(combination, max, index + 1);
}

void Generator::Find()
{
	int Max = ReadInput[0];
	for (int i : ReadInput) { // поиск максимального элемента
		if (i > Max)
			Max = i;
	}
	Recursive(Result, Max);
}

void Generator::print()
{
	cout << "Primitive recursive algorithm of full iteration: ";
	Print(Result);
}