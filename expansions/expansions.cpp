#include <iostream>

using namespace std;

int main()
{
	int k;
	unsigned long long value = 0;
	unsigned long long element = 1;
	unsigned long long power;

	cin >> k;
	power = k;

	while (power >= value)
	{
		value = value + element;

		if (power == value)
		{
			power = power * k;
			element++;
		}
	}
	cout << power;
}