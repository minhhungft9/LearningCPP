#include "User.h"

int User::ID = 0;

User::User(int age, int height, vector<string> hobbies, string name)
{
	m_name = name;
	m_id = ID++;
	while (m_name.empty()) {
		cout << "ID " << m_id << ", you must privide your name!" << endl;
		getline(cin, m_name);
	}
	m_age = age;
	m_height = height;
	m_hobbies = hobbies;
	m_friends = vector<User>();
	string sex;
	cout << m_name << ", are you male or female?" << endl;
	cin >> sex;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (sex.find("male") != string::npos)
	{
		m_sex = 1;
	}
	if(sex.find("female") != string::npos){
		m_sex = 2;
	}
	else {
		m_sex = 0;
	}
}

User::~User()
{
}

void User::makeFriend(User u) {
	m_friends.push_back(u);
}

string User::getName() { return m_name; }
int User::getAge() { return m_age; }
int User::getId() { return m_id; }
vector<string> User::getHobbies() {
	return m_hobbies;
}
vector<User> User::getFriends() {
	return m_friends;
}

void User::printInfo() {
	cout << "name: " << m_name << "\nID: " << m_id << "\nage: " << m_age << "\nheight: " << m_height << "cm\n";
	cout << "hobbies: ";
	for (vector<string>::const_iterator i = m_hobbies.begin(); i != m_hobbies.end(); i++) {
		cout << *i << ", ";
	}
	cout << "\n" << endl;
}


