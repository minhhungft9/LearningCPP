#include "Storyboard.h"
#include <algorithm>

bool isSubset(vector<string> v1, vector<string> v2) {
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	return includes(v1.begin(), v1.end(), v2.begin(), v2.end());
}

Storyboard::Storyboard()
{
	Notes = new map<string, Note>();
}


Storyboard::~Storyboard()
{
}

void Storyboard::addNote(Note note) {
	map<string, Note>::iterator find;
	find = Notes->find(note.getTitle());
	if (find != Notes->end()) {
		cout << "Stock already has the item." << endl;
	}
	else
	{
		(*Notes)[note.getTitle()] = note;
	}
}

void Storyboard::deleteNote(Note note) {
	map<string, Note>::iterator find;
	find = Notes->find(note.getTitle());
	if (find != Notes->end()) {
		Notes->erase(find->second.getTitle());
	}
	else
	{
		cout << "Not found!" << endl;
	}
}

vector<Note> Storyboard::searchByTitle(string title) {
	int result = 0;
	vector<Note> found;
	cout << "Searching for title: " << title << " ....." << endl;
	for (map<string, Note>::iterator i = Notes->begin(); i != Notes->end(); i++) {
		if (i->second.getTitle().find(title) != string::npos) {
			result++;
			found.push_back(i->second);
			i->second.printNote();
		}
	}
	if (result == 0)
	{
		cout << "Not found!" << endl;
	}
	return found;
}

vector<Note> Storyboard::searchByText(string text) {
	int result = 0;
	vector<Note> found;
	cout << "Searching for text: " << text << " ....." << endl;
	for (map<string, Note>::iterator i = Notes->begin(); i != Notes->end(); i++) {
		if (i->second.getText().find(text) != string::npos) {
			result++;
			found.push_back(i->second);
			i->second.printNote();
		}
	}
	if (result == 0)
	{
		cout << "Not found!" << endl;
	}
	return found;
}

vector<Note> Storyboard::searchByTag(vector<string> v) {
	int result = 0;
	vector<Note> found;
	cout << "Searching for tags: ";
	for (vector<string>::const_iterator i = v.begin(); i != v.end(); i++) {
		cout << *i << " ";
	}
	cout << " .....\n" << endl;
	for (map<string, Note>::iterator i = Notes->begin(); i != Notes->end(); i++) {
		if (isSubset(i->second.getTags(), v)) {
			result++;
			found.push_back(i->second);
			i->second.printNote();
		}
	}
	if (result == 0)
	{
		cout << "Not found!" << endl;
	}
	return found;
}


