#pragma once
#include"User.h"
#include<map>

class USocial
{
private:
	std::map<unsigned long, User*> users;

public:
	 unsigned long id;

	USocial();

	~USocial();
	

	User* registerUser(const std::string name, bool type);

	User* registerUser(const std::string name);

	void removeUser(User* user);
	

	User* getUserById(unsigned long id);
	
	friend class User;
};


