#include "Media.h"

#include<iostream>
#include<string>

void Media::display() const
{
}



 void Photo::display() const
{
	 std::cout << " Image  " << std::endl;
}



void Audio::display() const
{
	std::cout << "Audio" << std::endl;
}




void Video::display() const
{
		std::cout << " Video" << std::endl;		
}