/* Here is the Point class. It is almost similar same that in the program memleakharj.cpp.
    The difference is that it now has a member function distance, that calculates 
    distance between two points.
*/

#include <cmath>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
	int x = 1000000;
	int foundNumber = 1000000;
	int streak = 1;
	int largestStreak = 1;

	while (x < 2000000) {
		if (x % streak == 0)
		{
			//cout << x << " is divisible by " << streak << endl;
			x++;
			streak++;
		}
		else
		{
			//cout << x << " is not divisible by " << streak << "\n" <<endl;
			if (largestStreak < streak)
			{
				largestStreak = streak - 1;
				foundNumber = x - largestStreak;
			}
			x = x - streak + 2;
			streak = 1;
		}
	}
	cout << foundNumber << " " << largestStreak << endl;
	system("PAUSE");
	return EXIT_SUCCESS;
}
