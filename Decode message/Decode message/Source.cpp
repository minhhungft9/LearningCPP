#include <iostream>

using namespace std;

int main() {
	char input[] = "KVCY, SP IYE RKFO K COXDOXMO DRKD IYE VYFO PBYW K ZKBDSMEVKB KEDRYB, KXN IYE DRSXU SD'C K LODDOB COXDOXMO DRKX DRO YXO S'FO AEYDON, ZVOKCO, LI KVV WOKXC, VOD'C RKFO DRO COXDOXMOC NY LKDDVO! ZYCD SD KXN GO'VV COO GRODROB SD'C LODDOB.";
	cout << sizeof(input);
	char result[250];
	int i = 0;					//start at beginning of the string
	int shift = 1;
	cout << "Message: \n" << input << endl;

	while (shift < 26)
	{
		while (true)
		{
			if (input[i] == '\0')
			{
				result[i] = '\0';
				break;
			}
			if (int(input[i]) >= 65 && int(input[i]) <= 90)
			{
				if (int(input[i]) - shift >= 65) {
					result[i] = static_cast<char>(int(input[i]) - shift);
				}
				else
				{
					result[i] = static_cast<char>(int(input[i]) - shift + 26);
				}

			}
			else
			{
				result[i] = input[i];
			}
			i++; 
		}
		cout << "Shift " << shift << ":\n" << result << endl;
		result[0] = '\0';
		i = 0;
		shift++;
	}
	
	cin.get();
	return 0;
}