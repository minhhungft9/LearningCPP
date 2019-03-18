#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Note
{
	private:
		string m_title;
		string m_text;
		vector<string> m_tags;
	public:
		Note(string title = "", string text = "", vector<string> tags = {});
		Note(const Note& n);
		~Note();
		string getTitle();
		string getText();
		vector<string> getTags();
		void printNote();
};

