#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>      // std::stringstream
#include <math.h>
#include<conio.h>

using namespace std;

bool isNumber(string s)
{
	for (int i = 0; i < s.length(); i++)
		if (isdigit(s[i]) == false && s[i] != '.')
			return false;

	return true;
}

double findAverage(vector<double> readNumber) {
	vector<double>::size_type tokensSize = readNumber.size();
	double sum = 0;

	for (unsigned i = 0; i < tokensSize; i++) {
		sum = sum + readNumber[i];
	}

	double average = sum / tokensSize;
	cout << "Average: " << average << endl;
	return average;
}

double standardDeviation(vector<double> readNumber, double average) {
	vector<double>::size_type size = readNumber.size();
	double sd = 0;
	for (unsigned i = 0; i < size; i++) {
		sd = sd + pow((readNumber[i] - average), 2);
	}
	sd = sd / average;
	sd = sqrt(sd);
	cout << "Standard Deviation: " << sd << endl;
	return sd;
}

int main(int argc, char* argv[])
{
	string line;
	ifstream file("Text.txt");
	if (file.is_open()) {
		while (getline(file, line))
		{
			cout << "\n" << line << endl;

			string token;

			vector<double> tokens;
			double readNumber;

			istringstream tokenStream(line);
			while (getline(tokenStream, token, ','))
			{
				if (isNumber(token)) {
					readNumber = stof(token);
					tokens.push_back(readNumber);
				}
				else {
					cout << token << " is not a number" << endl;
				}

			}

			double average = findAverage(tokens);
			double sd = standardDeviation(tokens, average);
		}
		file.close();
	}
	else
	{
		cout << "Can not open the file." << endl;
	}

	cin.get();
	return 0;
}
