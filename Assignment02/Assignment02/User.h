#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class User
{
private:
	string m_name;
	int m_id;
	int m_age;
	int m_height;
	int m_sex;
	vector<string> m_hobbies;
	vector<User> m_friends;
public:
	static int ID;
	User(int age = 0, int height = 0, vector<string> hobbies = {}, string name = "");
	~User();
	void makeFriend(User u);
	string getName();
	int getAge();
	int getId();
	vector<string> getHobbies();
	vector<User> getFriends();
	void printInfo();
};





