#include <iostream>
#include <string.h>

class Page {
public:
	void init();
	std::string getPosts() const;
	std::string getStatus() const;
	void clearPage();
	void setStatus(std::string status);
	void addLineToPosts(std::string new_line);

private:
	std::string status;
	std::string posts;
};