#include "BusinessUser.h"
#include"User.h"
#include"Message.h"
#include<string>

//constructor - the Base constructor is called
BusinessUser::BusinessUser(const std::string name, unsigned long id, USocial* us) : User(name, id, us)
{
}

//Business user can send a message to any user
 void BusinessUser::sendMessage(User* buser, Message* msg)
{
	buser->receiveMessage(msg);
}
