#include <iostream>
using namespace std;
#include "SocialNetwork.h"

int main()
{
	User user1(23, 170, {"listen to music", "play football"}, "hung");
	User user2 = User(23, 169, { "play football" });
	User user3 = User(18, 190);
	User user4 = User();
	user1.makeFriend(user2);
	user1.makeFriend(user3);

	SocialNetwork sn;
	sn.addUser(user1);
	sn.addUser(user2);
	sn.addUser(user3);
	sn.addUser(user4);
	sn.searchUserByName("hung");
	sn.searchUserByAge(23);
	sn.serchUserById(3);
	sn.searchUserByHobbies({ "play football" });
	sn.getFriendsOfUser(user1);
	sn.deleteUser(user1);
	sn.getFriendsOfUser(user1);

	cin.get();
	return 0;
}