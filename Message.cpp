#include "Message.h"

#include<string>

//constructor. mmessage contain text.
Message::Message(std::string txt)
{
	text = txt;
}

//this method returns the message text
std::string Message::getText()
{
	return text;
}

