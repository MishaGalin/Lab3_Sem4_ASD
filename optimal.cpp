#include "optimal.h"

template <class T>
void Print(T someList) {
	for (auto& x : someList) cout << "\t" << x;
	cout << endl;
}

void Optimal::Read(vector<double> input)
{
	if (input.size() == 0)
	{
		cout << "Vector don't input" << endl;
		exit(0);
	}
	else {
		ReadInput = input;
		N = input.size();
	}
}

void Optimal::Find(int n)
{
	// заполнение пустыми строками
	for (int i = 0; i < n; i++) {
		vector<double> temp;

		for (int j = 0; j < n; j++) {
			temp.push_back(0.0);
		}

		Maximum.push_back(temp);
		Minimum.push_back(temp);
	}

	// заполнение диагоналей
	for (int i = 0; i < n; i++) {
		Minimum[i][i] = ReadInput[i];
		Maximum[i][i] = ReadInput[i];
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			for (int k = i; k <= j - 1; k++) {
				if (Maximum[k + 1][j] != 0 && Minimum[k + 1][j] != 0) { // проверяем деление на ноль
					Minimum[i][j] = min(Minimum[i][k] + Minimum[k + 1][j], min(Minimum[i][k] * Minimum[k + 1][j], Minimum[i][k] / Maximum[k + 1][j]));
					Maximum[i][j] = max(Maximum[i][j],
						max(Maximum[i][k] + Maximum[k + 1][j], max(Maximum[i][k] * Maximum[k + 1][j], Maximum[i][k] / Minimum[k + 1][j])));
				}

				else {
					Minimum[i][j] = min(Minimum[i][k] + Minimum[k + 1][j], Minimum[i][k] * Minimum[k + 1][j]);
					Maximum[i][j] = max(Maximum[i][j], max(Maximum[i][k] + Maximum[k + 1][j], Maximum[i][k] * Maximum[k + 1][j]));
				}
			}
		}
	}
}

void Optimal::print()
{
	Find(N);
	cout << "Maximum optimal sub-cutting [ + * / ]: " << Maximum[0][N - 1] << "\n" << endl;
	cout << "Minimum optimal sub-cutting [ + * / ]: " << Minimum[0][N - 1] << "\n" << endl;
	for (auto i : Minimum)
		Print(i);
	cout << endl;
	for (auto i : Maximum)
		Print(i);
}