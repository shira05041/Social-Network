#include"Post.h"
#include"Media.h"
#include<string>
#include<iostream>

//constructor for posts that contain only text
Post::Post(std::string post)
{
	text = post;
}

//constructor for posts that contain text and media
Post::Post(std::string post, Media* med)
{
	text = post;
	media = med;
}

//destructor
Post::~Post()
{	
}

//this method returns the post text
std::string Post::getText()
{
	return text;
}

//this method returns the post media
Media* Post::getMedia()
{
	return media;
}
