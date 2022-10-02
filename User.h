#pragma once

#include"Post.h"
#include"Media.h"
#include"Message.h"

#include <string>
#include <list>
#include<iostream>
#include<stdexcept>
#include<iterator>
#include<sstream>
#include<algorithm>

class User
{
	friend class USocial;

protected:
	USocial* _us;
	unsigned _id;
	std::string _name;
	std::list<unsigned long> friends;
	std::list<Post*> posts;
	std::list<Message*> receivedMsg;

	//constructor
	User(const std::string, unsigned long, USocial*);
	
	//destructor
	virtual ~User();

private:
	void printPost(Post*) const;
	
public:
	unsigned long getId() const;

	std::string getName() const;

	void addFriend(User*);

	void removeFriend(User*);
	
	void post(std::string);

	void post(std::string, Media*);

	std::list<Post*> getPosts() const;

	void viewFriendsPosts() const;

	void receiveMessage(Message*);

	virtual void sendMessage(User*, Message*); 

	void viewReceivedMessages() const;
	

};

