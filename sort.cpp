#include <iostream>
using namespace std;

int main()
{
	const int N = 5;
	int a[N] = { 1, 25, 6, -32, 43 };

	int min = 0;	

	for (int i = 0; i < N; i++)
	{
		min = i; 
		for (int j = i + 1; j < N; j++)
			min = (a[j] < a[min]) ? j : min;
		if (i != min)
		{
			int buf = a[i];
			a[i] = a[min];
			a[min] = buf;
		}
	}

	for (int i = 0; i < N; i++)
		cout << a[i] << endl;
}
