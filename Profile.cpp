#include "Profile.h"
#include "UserList.h"
void Profile::init(User owner) {
	this->owner.init(owner.getID(), owner.getUserName(), owner.getAge());
	this->owner.getDevices().init();

	DevicesList lst = owner.getDevices();
	DeviceNode* node = lst.get_first();

	while (node != nullptr){
		
		this->owner.addDevice(node->get_data());

		node = node->get_next();
	}

	this->page.init();
	this->friends.init();
}
void Profile::clear() {
	this->page.clearPage();
	this->owner.clear();
	this->friends.clear();

}
User Profile::getOwner() const{
	return this->owner;
}
void Profile::setStatus(std::string new_status) {
	this->page.setStatus(new_status);
}
void Profile::addPostToProfilePage(std::string post) {
	this->page.addLineToPosts(post);
}
void Profile::addFriend(User friend_to_add) {
	this->friends.add(friend_to_add);
}
std::string Profile::getPage() const {
	std::string pages = "Status: " + this->page.getStatus() + "\n";

	pages += "*******************\n";
	pages += "*******************\n";

	pages += this->page.getPosts();

	//pages += "***";

	return pages;
}
std::string Profile::getFriends() {
	UserNode* current = this->friends.get_first();

	std::string str = "";

	while (current->get_next() != nullptr) {
		str += current->get_data().getUserName() + ",";

		current = current->get_next();
	}

	str += current->get_data().getUserName();

	return str;
}
std::string Profile::getFriendsWithSameNameLength() {
	UserNode* orig = this->friends.get_first();
	UserNode* pos = orig;
	std::string result1 = "";
	std::string result2 = "";

	while (orig != nullptr && result2 == "") {
		std::string data = orig->get_data().getUserName();

		result1 = data;

		while (pos != nullptr && result2 == "") {
			std::string dataSecondary = pos->get_data().getUserName();

			if (data.length() == dataSecondary.length())
			{
				result2 = dataSecondary;
			}
			pos = pos->get_next();
		}

		pos = orig;
		orig = orig->get_next();
	}

	return result1 + "," + result2;
}