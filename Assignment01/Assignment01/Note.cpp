#include "Note.h"

Note::Note(string title, string text, vector<string> tags)
{
	m_title = title;
	m_text = text;
	m_tags = tags;
}

Note::Note(const Note& n) {
	m_title = n.m_title;
	m_text = n.m_text;
	m_tags = n.m_tags;
}


Note::~Note()
{
}

string Note::getTitle() { return m_title; }
string Note::getText() { return m_text;  }
vector<string> Note::getTags() { return m_tags; }

void Note::printNote() {
	cout << "title: " << m_title << "\ntext: " << m_text << endl;
	cout << "tags: ";
	for (vector<string>::const_iterator i = m_tags.begin(); i != m_tags.end(); i++) {
		cout << *i << " ";
	}
	cout << "\n" << endl;
}