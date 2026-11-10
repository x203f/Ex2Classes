#include "UserList.h"

#include "Page.h"
class Profile {
public:
	void init(User owner);
	void clear();
	User getOwner() const;
	void setStatus(std::string new_status);
	void addPostToProfilePage(std::string post);
	void addFriend(User friend_to_add);
	std::string getPage() const;
	std::string getFriends();
	std::string getFriendsWithSameNameLength();

private:
	User owner;
	Page page;
	UserList friends;
};