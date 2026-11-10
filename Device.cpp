#include <iostream>

#include "Device.h"
// this function will initialize the device
// id: Id of the device, type: type of the device (android, pc etc) os: the name of the os.

void Device::init(unsigned int id, DeviceType type, std::string os) {
	this->Id = id;
	this->type = type;
	this->Os = os;
	this->active = 1; // activated by default
}

// this function will deactivate the current phone
void Device::deactivate() {
	this->active = 0;
}

// this function will activate the current phone
void Device::activate() {
	this->active = 1;
}

// this function will return if the current phone is active.
bool Device::isActive() const {
	return this->active;
}

// this function will return an OS

std::string Device::getOS() const {
	return this->Os;
}

// this function will return an ID

unsigned int Device::getID() const {
	return this->Id;
}


// this function will return a type

DeviceType Device::getType() const {
	return this->type;
}



