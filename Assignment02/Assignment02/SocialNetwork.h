#pragma once
#include "User.h"
class SocialNetwork
{
private:
	map<string, User> *users;
public:
	SocialNetwork();
	~SocialNetwork();
	void addUser(User u);
	void deleteUser(User u);
	vector<User> searchUserByName(string name);
	vector<User> serchUserById(int id);
	vector<User> searchUserByAge(int age);
	vector<User> searchUserByHobbies(vector<string> h);
	vector<User> getFriendsOfUser(User u);
};

