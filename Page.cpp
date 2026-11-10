#include "Page.h"

// this function will initialize the page
void Page::init() {
	this->status = "";
	this->posts = "";
}

// this function will get posts
std::string Page::getPosts() const {
	return this->posts;
}
// this function will get status
std::string Page::getStatus() const {
	return this->status;
}

// this function will clear page


void Page::clearPage() {
	this->posts = "";
}

// this function will set status. status: string of status
void Page::setStatus(std::string status) {
	this->status = status;
}

// this function will add a new line to posts
void Page::addLineToPosts(std::string new_line) {
	this->posts = "\n" + new_line;
}