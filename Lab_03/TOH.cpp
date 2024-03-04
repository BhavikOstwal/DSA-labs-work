#include <iostream>
using namespace std;

int count = 0;
void towerOfHanoi(int n, char from_rod, char aux_rod, char to_rod)
{
	if (n == 0)
	{
		return;
	}
	towerOfHanoi(n - 1, from_rod, to_rod, aux_rod);
	cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
	::count++;
	towerOfHanoi(n - 1, aux_rod, from_rod, to_rod);
}

int main()
{
	int N = 2;

	towerOfHanoi(N, 'A', 'B', 'C');
	// cout << ::count << endl;
	return 0;
}
