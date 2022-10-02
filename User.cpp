#include "User.h"
#include"USocial.h"

//constructor
User::User(std::string name, unsigned long id, USocial* us) : _us(us)
{
	_name = name;
	_id = id;
	_us = us;
}

//destructor
User::~User() 
{   
	//deldeteall items from lists
	for (const auto&item : posts)
	{
		delete item;
	}
	for (const auto& item : receivedMsg)
	{
		delete item;
	}
	//remove the lists
	friends.clear();
	posts.clear();
	receivedMsg.clear();
}
	
//this method returns user's ID
unsigned long User::getId() const
{
	return _id;
}

//this method returns user's name
std::string User::getName() const
{
	return _name;
}

//this method add friends to user's friends list
void User::addFriend(User* user)
{
	try {
		if (user->_id == this->_id) //if user try to add himself to his friend list
			std::cout << "You can not be yourself friend" << std::endl;
		else 
		{
			auto it = find(friends.begin(), friends.end(), user->_id); //check if user is trying to add a user that he's friends allready
			if (it != friends.end())
				std::cout << "This user is already your friend" << std::endl;
			else
				friends.push_back(user->_id); //add the user to friends list
		}
	}
	catch (const std::exception& e) {
		std::cout << "Error! " << std::endl;
	}	
}

//this method remove a friend from user's friend list
void User::removeFriend(User* user)
{
	try{
		friends.remove(user->_id);
	}
	catch (const std::exception& e) {
		std::cout << " Can't remove this user!. This user is not your friend" << std::endl;
	}
}

//this method add a post to user's posts list
void User::post(std::string newPost) 
{
	try{
		Post* post = new Post(newPost);
		posts.push_back(post);//add the post to posts list
	}
	catch (const std::exception& e) {
		std::cout << "Error! " << e.what() << std::endl;
	}
}

//this method add a post that contain media
void User::post(std::string newPost, Media* media)
{
	try{
		Post* post = new Post(newPost, media);
		posts.push_back(post); //add the post to posts list
	}
	catch (const std::exception& e) {
		std::cout << "Error! " << e.what() << std::endl;
	}
}


//this method return a copy of posts list
std::list<Post*> User::getPosts() const
{
	if (posts.empty()) //if there are no posts 
		std::cout << "There are no posts to view" << std::endl;

	std::list<Post*> copyPosts(posts);// creating a copy of posts list	
	return copyPosts;
}

// this method prints only user's friends posts 
void User::viewFriendsPosts() const
{ 
	try {
		for (auto& ff : friends) //iterate throw all user friends
		{
			std::cout << "Th are the posts your friend " << _us->getUserById(ff)->getName() << " posted:" << std::endl;
			std::cout << "These are the posts your friend " << _us->getUserById(ff)->getName() << " posted:" << std::endl;
			for (auto& pp : _us->getUserById(ff)->getPosts()) //iterate throw all user friend  posts
			{
				printPost(pp); //print the post
			}
		}
	}
		catch (const std::exception& e) {
			std::cout << "Error! " << std::endl;
		}
}

//print  posts
void User::printPost(Post* post) const
{
	try {
		std::cout << post->getText() << "  ";
		if (post->getMedia() != NULL) //if post contain media
			post->getMedia()->display(); //display the media
	}
	catch (const std::exception& e) {
		std::cout << "Error! " << e.what() << std::endl;
	}
}

//this method recive message by adding the message to user(how gets the message) receivedMsg list
void User::receiveMessage(Message* msg) 
{
	try {
		receivedMsg.push_back(msg);//add the message to receivedMsg list
	}
	catch (const std::exception& e) {
		std::cout << "Failed to recive the message! " << e.what() << std::endl;
	}
}

//this method send a message to one of the user friends
 void  User::sendMessage(User* user, Message* msg) 
{
	auto it = find(friends.begin(), friends.end(), user->_id); //check if this user is one of my friends
	if (it != friends.end())
	{
		user->receiveMessage(msg);
	}
	else
		std::cout << "You can not send a mmessage to user that is not your friend!" << std::endl;
}

 //this method display the messages user had recieved
void User::viewReceivedMessages() const
{
	if(receivedMsg.empty())
		std::cout << "You have no recevid message!" << std::endl;
	else
	{
		std::cout << "This are the messages you received:" << std::endl;
		for (auto& msg : receivedMsg) //iterate throw all the recieved messages
		{
			std::cout << msg->getText() << std::endl;;
		}
	}
		
}



