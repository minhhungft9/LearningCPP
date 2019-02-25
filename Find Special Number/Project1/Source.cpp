#include<iostream>
#include <math.h>
using namespace std;

int countDigits(int num) {
	int count = 1;
	while (num /= 10) {
		count++;
	}
	return count;
}

int main()
{
	int x = 1000;
	while (true) {
		int cubeValue = pow(x, 3);
		int NumberOfDigit = countDigits(x);
		int endOfCube = cubeValue % (int)pow(10, NumberOfDigit);

		cout << "x: " << x << endl;
		cout << "Number of digits: " << NumberOfDigit << endl;
		cout << "Cube of x: " << cubeValue << endl;
		cout << "End of cube value: " << endOfCube << endl;

		if (endOfCube == x) {
			break;
		}else{
			x++;
		}
	}
	cin.get();
	return 0;
}