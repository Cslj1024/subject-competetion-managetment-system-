#pragma once

#include "stdafx.h"

class Role
{
public:
	string account;
	string password;
	int role;
	Role();
	~Role();

	void Register(string username, string password);//×¢²á
	Status Login(string username, string password);//µÇÂ¼
	void Display();//ÏÔÊ¾ÕËºÅ¼°ÆäÃÜÂë
	void AfterLogin();
};

