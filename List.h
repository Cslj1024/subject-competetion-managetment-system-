#pragma once

#include "stdafx.h"
#include "MatchInfo.h"
class List
{
public:
	MatchInfo data;
	List *next;


	List();
	~List();

	void InitList(List *L);//初始化
	void DestroyList(List *L);//销毁8 
	void ClearList(List *L);//清空
	Status ListEmpty(List *L);//判空
	int ListLength(List *L);//获长
	Status GetMatch(List *L,int i,MatchInfo &m);
	int LocateMatch(List *L, MatchInfo m, Status(*Compare)(List *L,MatchInfo m));
	void ListInsert(List *L, int n);//尾插
	Status ListDelete(List *L, MatchInfo &m);
	void ListTraverse(List *L);//遍历
	Status UpdateList(List *L, MatchInfo &m);
	Status Equal(List *L, MatchInfo m);
};

