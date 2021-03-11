#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
int sum(int** a, const int n, int s, int i, int j);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -10;
	int High = 10;
	int n;

	cout << "rowCount = "; cin >> n;

	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];

	Create(a, n, n, Low, High, 0, 0);
	Print(a, n, n, 0, 0);

	cout << "sum = " << sum(a, n, 0, 0, 1) << endl;


	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);

	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

int sum(int** a, const int n, int s, int i, int j)
{
	if (i < n)
	{
		if (j < n)
		{
			s += abs(a[i][j]);
			sum(a, n, s, i, j + 1);
		}
		else
			sum(a, n, s, i + 1, i + 2);
	}

	else
		return s;

}