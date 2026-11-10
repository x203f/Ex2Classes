#include "Profile.h"
#include "UserList.h"
void Profile::init(User owner) {
	this->owner.init(owner.getID(), owner.getUserName(), owner.getAge());
	this->owner.getDevices().init();


	// to not get a memory error. we will copy all devices instead.
	DevicesList lst = owner.getDevices();
	DeviceNode* node = lst.get_first();

	while (node != nullptr){
		
		this->owner.addDevice(node->get_data());

		node = node->get_next();
	}
	// init pages
	this->page.init();

	// friends init
	this->friends.init();
}

// this function clears the page, owner and friends
void Profile::clear() {
	this->page.clearPage();
	this->owner.clear();
	this->friends.clear();

}

// this gets the owner
User Profile::getOwner() const{
	return this->owner;
}

// this sets a new status. new_status: the string to set the status of page
void Profile::setStatus(std::string new_status) { 
	this->page.setStatus(new_status);
}
// this function posts to profile page
void Profile::addPostToProfilePage(std::string post) {
	this->page.addLineToPosts(post);
}

// this functin adds a friend
void Profile::addFriend(User friend_to_add) {
	this->friends.add(friend_to_add);
}

// this function gets page string
std::string Profile::getPage() const {
	std::string pages = "Status: " + this->page.getStatus() + "\n";

	pages += "*******************\n";
	pages += "*******************\n";

	pages += this->page.getPosts();

	//pages += "***";

	return pages;
}

// this function gets the friends
std::string Profile::getFriends() {
	UserNode* current = this->friends.get_first();

	std::string str = "";

	// run thru the friends and add

	while (current->get_next() != nullptr) {
		str += current->get_data().getUserName() + ",";

		current = current->get_next();
	}

	str += current->get_data().getUserName();

	return str;
}

// get the friends with same name lengths
std::string Profile::getFriendsWithSameNameLength() {
	UserNode* orig = this->friends.get_first();
	UserNode* pos = orig;
	std::string result1 = "";
	std::string result2 = "";

	// first item
	while (orig != nullptr && result2 == "") {
		std::string data = orig->get_data().getUserName();

		result1 = data;

		// run thru the second item and try to get the same length
		while (pos != nullptr && result2 == "") {
			std::string dataSecondary = pos->get_data().getUserName();

			if (data.length() == dataSecondary.length())
				// found length
			{
				result2 = dataSecondary;
			}
			pos = pos->get_next();
		}

		// no point of rechecking 
		pos = orig;
		orig = orig->get_next();
	}

	return result1 + "," + result2;
}