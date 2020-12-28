#include <iostream>
using namespace std;
int main()
{
	int a[100] = {3, 2, 1, 8, 11};
	int position, number, i;
	cout << "Enter the position and number\n";
	cin >> position >> number;

	for (i = 4; i >= position; i--)
	{
		a[i + 1] = a[i];
	}
	a[position] = number;
	cout << "New Array:\n";
	for (i = 0; i < 6; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
