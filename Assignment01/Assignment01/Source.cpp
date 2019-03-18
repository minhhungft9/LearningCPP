#include <iostream>
#include "Storyboard.h"
using namespace std;

int main()
{
	Note note1("test1", "this is test 1", { "abc", "def" });
	Note note2("test2", "another test", { "abc" , "123", "456" });
	Note note3 = Note();

	Storyboard board;
	board.addNote(note1);
	board.addNote(note2);
	board.addNote(note3);

	board.searchByTitle("test");
	board.searchByText("another");
	board.searchByTag({ "abc" });
	board.searchByTag({ "123" });
	
	board.deleteNote(note1);
	board.searchByTitle("test1");

	cin.get();
	return 0;
}
