#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Note.h"
using namespace std;

class Storyboard
{
	private:
		map<string, Note> *Notes;
	public:
		Storyboard();
		~Storyboard();
		void addNote(Note note);
		void deleteNote(Note note);
		vector<Note> searchByTitle(string title);
		vector<Note> searchByText(string text);
		vector<Note> searchByTag(vector<string> v);
};

