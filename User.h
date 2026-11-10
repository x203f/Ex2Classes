#include <string>

#include "DeviceList.h"

class User {
public:

	void init(unsigned int id, std::string username, unsigned int age);
	void clear();
	unsigned int getID() const;
	std::string getUserName() const;
	unsigned int getAge() const;
	DevicesList getDevices();
	void addDevice(Device newDevice);
	bool checkIfDevicesAreOn() const;


private:
	DevicesList devices;
	unsigned int Id;
	std::string Username;
	unsigned int Age;

};