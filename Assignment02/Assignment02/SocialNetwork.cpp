#include "SocialNetwork.h"
#include <algorithm>

bool isSubset(vector<string> v1, vector<string> v2) {
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	return includes(v1.begin(), v1.end(), v2.begin(), v2.end());
}

SocialNetwork::SocialNetwork()
{
	users = new map<string, User>();
}


SocialNetwork::~SocialNetwork()
{
}

void SocialNetwork::addUser(User u) {
	users->insert(pair<string, User>(u.getName(), u));
}

void SocialNetwork::deleteUser(User u) {
	map<string, User>::iterator find;
	find = users->find(u.getName());
	if (find != users->end()) {
		users->erase(find->second.getName());
	}
	else
	{
		cout << "Not found!" << endl;
	}
}

vector<User> SocialNetwork::searchUserByName(string name) {
	vector<User> result;
	int resultNumber = 0;
	cout << "Searching for name: " << name << " ....." << endl;
	for (map<string, User>::iterator i = users->begin(); i != users->end(); i++) {
		if (i->second.getName().find(name) != string::npos) {
			resultNumber++;
			result.push_back(i->second);
			i->second.printInfo();
		}
	}
	if (resultNumber == 0)
	{
		cout << "Not found!" << endl;
	}
	return result;
}

vector<User> SocialNetwork::searchUserByAge(int age) {
	vector<User> result;
	int resultNumber = 0;
	cout << "Searching for age: " << age << " ....." << endl;
	for (map<string, User>::iterator i = users->begin(); i != users->end(); i++) {
		if (i->second.getAge() == age) {
			resultNumber++;
			result.push_back(i->second);
			i->second.printInfo();
		}
	}
	if (resultNumber == 0)
	{
		cout << "Not found!" << endl;
	}
	return result;
}

vector<User> SocialNetwork::getFriendsOfUser(User u) {
	vector<User> result;
	cout << "Finding friends of user " << u.getName() << " ....." << endl;
	map<string, User>::iterator find;
	find = users->find(u.getName());
	if (find != users->end()) {
		result = u.getFriends();
		for (int i = 0; i < result.size(); i++) {
			result[i].printInfo();
		}
	}
	else
	{
		cout << "Not found!" << endl;
	}
	return result;
}

vector<User> SocialNetwork::searchUserByHobbies(vector<string> h) {
	vector<User> result;
	int resultNumber = 0;
	cout << "Searching for hobbies: ";
	for (vector<string>::const_iterator i = h.begin(); i != h.end(); i++) {
		cout << *i << ", ";
	}
	cout << " .....\n" << endl;
	for (map<string, User>::iterator i = users->begin(); i != users->end(); i++) {
		if (isSubset(i->second.getHobbies(), h)) {
			resultNumber++;
			result.push_back(i->second);
			i->second.printInfo();
		}
	}
	if (resultNumber == 0)
	{
		cout << "Not found!" << endl;
	}
	return result;
}

vector<User> SocialNetwork::serchUserById(int id) {
	vector<User> result;
	int resultNumber = 0;
	cout << "Searching for ID: " << id << " ....." << endl;
	for (map<string, User>::iterator i = users->begin(); i != users->end(); i++) {
		if (i->second.getId() == id) {
			resultNumber++;
			result.push_back(i->second);
			i->second.printInfo();
		}
	}
	if (resultNumber == 0)
	{
		cout << "Not found!" << endl;
	}
	return result;
}


