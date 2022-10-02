#include "USocial.h"
#include"User.h"
#include "Message.h"
#include "BusinessUser.h"
#include<iostream>
#include<string>
#include<map>
#include<list>
#include<exception>

//constructor
USocial::USocial()
{
	id = 0; 
}

//destrucror
USocial::~USocial()
{
}

//this methode called registerUser with type = false
User* USocial::registerUser(const std::string name)
{
	try{
		return registerUser(name, false);
	}
	catch (const std::exception& e) {
		std::cout << "Error! " << e.what() << std::endl;
	}
	return NULL;
}

//this methode create a user according to the type. and inser the details to users
User* USocial::registerUser(const std::string name, bool type)
{
	User* user;
	if (name == "")
		std::cout << "User`s name is missing" << std::endl;
	if (type)
		user = new BusinessUser(name, ++id, this);//create a businuess user
	else
		user = new User(name, ++id, this);//create a regular user
	users.insert({ id, user });//insert detailes to the users map
	return user;
}



//this method remove a user from the users map
void USocial::removeUser(User* user)
{
	try{
		users.erase(user->getId());
	}
	catch (const std::exception& e) {
		std::cout << "User was not found" << std::endl;
	}
}

//get pointer to user by ID
User* USocial::getUserById(unsigned long id)
{
	try{
		return users[id];
	}
	catch (const std::exception& e){
		std::cout << "User was not found" << e.what() << std::endl;
		return NULL;
	}
}
