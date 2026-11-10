#include "User.h"

void User::init(unsigned int id, std::string username, unsigned int age) {
	this->Id = id;
	this->Username = username;
	this->Age = age;
	this->devices.init();
}

void User::clear() {
	this->Id = 0;
	this->Username = "";
	this->Age = 0;
	if (this->devices.get_first() != nullptr)
		this->devices.clear();
}
unsigned int User::getID() const {
	return this->Id;
}
std::string User::getUserName() const {
	return this->Username;
}
unsigned int User::getAge() const
{
	return this->Age;
}
DevicesList User::getDevices() {
	return this->devices;
}
void User::addDevice(Device newDevice) {
	this->devices.add(newDevice);
}
bool User::checkIfDevicesAreOn() const {
	DeviceNode* deviceNode = this->devices.get_first();

	while (deviceNode != nullptr) {

		if (!deviceNode->get_data().isActive())
		{
			return false;
		}

		deviceNode = deviceNode->get_next();
	}

	return true;
}