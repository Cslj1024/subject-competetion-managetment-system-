#include "stdafx.h"
#include "Role.h"


Role::Role()
{
	this->account = "Admin";
	this->password = "123";
	this->role = 1;
}


Role::~Role()
{
}

void Role::Register(string username, string password)
{
}

Status Role::Login(string username, string password)
{
	return Status();
}

void Role::Display()
{
}

void Role::AfterLogin()
{
}


