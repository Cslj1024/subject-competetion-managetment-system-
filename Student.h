#pragma once
#include "Role.h"
#include "List.h"
class Student : public Role
{
public:
	string ID;//Ñ§ºÅ
	List *M;
	Student();
	~Student();

	 void Register(string username, string password);//×¢²á
	 Status Login(string username, string password);//µÇÂ¼
	 void Display();//ÏÔÊ¾ÕËºÅ¼°ÆäÃÜÂë
	 void AfterLogin(Student *S,List *L);

	 void QuerryMatch(List *L);
	 Status JoinMatch(Student *S,List *L);
	 Status ExitMatch(Student *S, List *L);
	 void ShowMatch();

	 void Load();
	 void Save();
};

