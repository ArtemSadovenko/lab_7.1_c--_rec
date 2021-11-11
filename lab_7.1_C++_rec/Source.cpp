#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;
void create(int** a, int col, int row, int l, int h, int i, int j);
void print(int** a, int row, int col, int i, int j);
void sort(int** a, int row, int col, int i1, int i2);
void change(int** a, int i1, int i2, int col, int i);
int sum(int** a, int row, int col, int& k, int i, int j, int s);

void main() {
	srand((unsigned)time(NULL));

	int row = 7;
	int col = 6;

	int l = -12;
	int h = 23;

	int k = 0;

	int** X = new int* [row];
	for (int i = 0; i < row; i++)
		X[i] = new int[col];

	create(X, col, row, l, h, 0, 0);

	print(X, row, col, 0, 0);


	sort(X, row, col, 0, 0);

	print(X, row, col, 0, 0);

	int s = sum(X, row, col, k, 0, 0, 0);

	print(X, row, col, 0, 0);

	cout << "sum = " << s << "\t" << "amount = " << k << endl;

}

void create(int** a, int col, int row, int l, int h, int i, int j) {
	a[i][j] = l + rand() % (h - l + 1);
	if (j < col-1) {
		create(a, col, row, l, h, i, j + 1);
	}
	else if (i < row-1) {
		create(a, col, row, l, h, i + 1, 0);
	}
	else {
		cout << endl;
	}
}



void print(int** a, int row, int col, int i, int j) {
	
	if (j == 0) {
		cout << "|";
	}

	cout << setw(3) << a[i][j] << " ";

	if (j == col-1) {
		cout << "|\n";
	}

	if (j < col-1) {
		print(a, row, col, i, j + 1);
	}
	else if (i < row-1) {
		print(a, row, col, i + 1, 0);
	}
	else {
		cout << endl;
	}
}

void sort(int** a, int row, int col, int i1, int i2) {

	if ((a[i1][0] > a[i1 + 1][0])
		||
		(a[i1][0] == a[i1 + 1][0] &&
			a[i1][1] > a[i1 + 1][1])
		||
		(a[i1][0] == a[i1 + 1][0] &&
			a[i1][1] == a[i1 + 1][1] &&
			a[i1][3] < a[i1 + 1][3]))
		change(a, i1, i1 + 1, col, 0);
	if (i1 < row - i2 - 2) {
		sort(a, row, col, i1 + 1, i2);
	}
	else if (i2 < row - 2) {
		sort(a, row, col, 0, i2+1);
	}

		
}

void change(int** a, int i1, int i2, int col,int i) {
	int k;

	k = a[i1][i];
	a[i1][i] = a[i2][i];
	a[i2][i] = k;

	if (i < col - 1) {
		change(a, i1, i2, col, i + 1);
	}
}

int sum(int** a, int row, int col, int& k, int i, int j, int s) {

	if (!(a[i][j] % 2 == 0) || !(a[i][j] < 0)) {
		s += a[i][j];
		k++;
		a[i][j] = 0;
	}
	if (j < col - 1) {
		sum(a, row, col, k, i, j + 1, s);
	}
	else if (i < row - 1) {
		sum(a, row, col,k,  i + 1, 0, s);
	}
	return s;
}
