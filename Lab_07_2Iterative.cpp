#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int RowMax(int** a, const int n, const int i);
bool SearchMinOfRowMax(int** a, const int k, const int n, int& minOfMax);

int main()
{
	srand((unsigned)time(NULL));

	int Low = -20;
	int High = 50;

	int k, n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	Create(a, k, n, Low, High);
	Print(a, k, n);

	int minOfMax;
	if (SearchMinOfRowMax(a, k, n, minOfMax))
		cout << "min of row maximums (even rows) = " << minOfMax << endl;
	else
		cout << "there are no even rows" << endl;

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int RowMax(int** a, const int n, const int i)
{
	int max = a[i][0];
	for (int j = 1; j < n; j++)
		if (a[i][j] > max)
			max = a[i][j];
	return max;
}

bool SearchMinOfRowMax(int** a, const int k, const int n, int& minOfMax)
{
	if (k < 2)
		return false;

	minOfMax = RowMax(a, n, 1);
	for (int i = 3; i < k; i += 2)
	{
		int m = RowMax(a, n, i);
		if (m < minOfMax)
			minOfMax = m;
	}
	return true;
}