#pragma once
#include "Role.h"
#include "List.h"
#include "MatchInfo.h"
class Manager : public Role
{
public:

	Status Login(string account, string password);
	void AfterLogin(List *L);
	void QuerryMatch();
	void SaveMatch(List *L);

	void Display();
	Manager();
	~Manager();
};

