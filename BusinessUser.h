#pragma once
#include"User.h"
#include"USocial.h"

class BusinessUser : public User
{
public:
	BusinessUser(const std::string, unsigned long, USocial*) ;
	
	virtual void sendMessage(User* buser, Message* msg);
	
};

