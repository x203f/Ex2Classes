#include "SocialNetwork.h"

void SocialNetwork::init(std::string networkName, int minAge) {
	this->networkName = networkName;
	this->minAge = minAge;
	this->availableProfiles.init();
}
void SocialNetwork::clear() {
	this->networkName = "";
	this->minAge = 0;
	this->availableProfiles.clear();
}
std::string SocialNetwork::getNetworkName() {
	return this->networkName;
}

int SocialNetwork::getMinAge() {
	return this->minAge;
}
bool SocialNetwork::addProfile(Profile profile_to_add) {

	if (profile_to_add.getOwner().getAge() < this->minAge) return false;
	this->availableProfiles.add(profile_to_add);

	return true;
}
bool isWindows(Device device) {
	std::string deviceName = device.getOS();
	return deviceName == WINDOWS10 || deviceName == WINDOWS11 || deviceName == WINDOWS7;
}

std::string SocialNetwork::getWindowsDevices() {
	std::string result = "";

	ProfileNode* node = this->availableProfiles.get_first();

	while (node != nullptr) {
		Profile profile = node->get_data();
		User owner = profile.getOwner();
		DevicesList deviceList = owner.getDevices();
		
		DeviceNode* deviceNode = deviceList.get_first();


		while (deviceNode != nullptr && !isWindows(deviceNode->get_data())) {

			deviceNode = deviceNode->get_next();
		}

		Device device = deviceNode->get_data();

		if (isWindows(device)) {
			result += "[" + std::to_string(device.getID()) + ", " + device.getOS() + "]";

			if (node->get_next() != nullptr) {
				result += ", ";
			}

		}


		node = node->get_next();
	}

	return result;
}