#pragma once
#include"Media.h"
#include<string>

class Post
{
	std::string text;
	Media* media;

public:
	Post(std::string);

	Post(std::string, Media*);
	
	~Post();
	
	std::string getText();
	

	Media* getMedia();
	
};