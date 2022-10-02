#pragma once
#include<exception>

class Media
{
public:
	virtual void display() const = 0;
};

class Photo : public Media
{
public:
	virtual void display() const;
};

class Audio : public Media
{
public:
	virtual void display() const;
};

class Video : public Media
{
public:
	virtual void display() const;
};

