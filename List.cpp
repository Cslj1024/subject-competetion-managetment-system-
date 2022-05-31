#include "stdafx.h"
#include "List.h"


List::List()
{
}


List::~List()
{
}

void List::InitList(List *L)
{
	L->next = NULL;
}

void List::DestroyList(List * L)
{
	List *p;
	while (L) {
		p = L->next;
		free(L);
		L = p;
	}
}

void List::ClearList(List * L)
{
	List *p, *q;
	p = L->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}

Status List::ListEmpty(List * L)
{
	if (L->next)
		return TRUE;
	else
		return FALSE;
}

int List::ListLength(List * L)
{
	int i = 0;
	List *p = L->next;
	while (p) {
		i++;
		p = p->next;
	}
	return i;

}

Status List::GetMatch(List * L, int i, MatchInfo & m)
{
	cout << "当前是比赛信息查找界面: " << endl << endl;
	int j = 1;
	List *p = L->next;
	while (p&&j < i) {
		p = p->next;
		j++;
	}
	if (!p || j>i)
		return ERROR;
	m = p->data;
	return OK;
	return Status();
}

int List::LocateMatch(List * L, MatchInfo m, Status(*Compare)(List *L, MatchInfo m))
{
	int i = 0;
	List *p = L->next;
	while (p) {
		i++;
		if (Compare(p, m))
			return i;
		p = p->next;
	}
	return 0;
}

void List::ListInsert(List * L, int n)
{
	cout << "当前是比赛信息添加界面: " << endl << endl;
	List *p = NULL, *q = L;
	cout << "待输入信息条数—— "; cin >> n;
	cout << endl;
	cout << "编号\t\t" << "项目\t\t\t\t" << "时间\t\t" << "地点\t" << "内容\t" << "负责人\t\t" << endl << endl;

	while (q->next)
		q = q->next;

	for (int i = 0; i < n; i++) {
		p = new List();
		cin >> p->data.matchID
			>> p->data.matchTitle
			>> p->data.matchTime
			>> p->data.matchAddress
			>> p->data.matchContent
			>> p->data.matchPrincipal;
		q->next = p;
		q = q->next;
	}
	p->next = NULL;
	cout << endl;
}

Status List::ListDelete(List *L, MatchInfo & m)
{
	int find = 0;
	string id;
	cout << "当前是比赛信息删除界面: " << endl << endl;
	cout << "输入比赛编号:";
	cin >> id;

	List *p = L;
	List *q = p->next;
	while (q != NULL)
	{
		if (q->data.matchID == id)
		{
			find = 1;
			p->next = q->next;
			free(q);
			q = p->next;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}

	if (find == 0)
		cout << "比赛编号" << id << "不存在" << endl << endl;

	return Status();
}

void List::ListTraverse(List * L)
{
	List *p = L->next;
	while (p) {
		cout << p->data.matchID << "\t"
			<< p->data.matchTitle << "\t"
			<< p->data.matchTime << "\t"
			<< p->data.matchAddress << "\t"
			<< p->data.matchContent << "\t"
			<< p->data.matchPrincipal << endl << endl;
		p = p->next;
	}
}

Status List::UpdateList(List * L, MatchInfo & m)
{
	int find = 0;
	string id;
	cout << "当前是比赛信息修改界面: " << endl << endl;
	cout << "输入比赛编号:";
	cin >> id;
	List *p = L;
	List *q = p->next;
	while (q != NULL)
	{
		if (q->data.matchID == id)
		{
			find = 1;
			cout << "输入比赛编号:";
			cin >> q->data.matchID;
			cout << "输入比赛标题:";
			cin >> q->data.matchTitle;
			cout << "输入比赛时间:";
			cin >> q->data.matchTime;
			cout << "输入比赛地点:";
			cin >> q->data.matchAddress;
			cout << "输入比赛内容:";
			cin >> q->data.matchContent;
			cout << "输入比赛负责人:";
			cin >> q->data.matchPrincipal;
			break;
		}

		q = q->next;
	}

	if (find == 0)
		cout << "比赛编号" << id << "不存在" << endl << endl;

	return Status();
}

Status List::Equal(List * L, MatchInfo m)
{
	int find = 0;
	string id;
	cout << "当前是比赛信息查找界面: " << endl << endl;
	cout << "输入比赛编号:";
	cin >> id;
	List *p = L;
	List *q = p->next;
	while (q != NULL)
	{
		if (q->data.matchID == id)
		{
			find = 1;
			cout << "编号\t\t" << "项目\t\t\t\t" << "时间\t\t" << "地点\t" << "内容\t" << "负责人\t\t" << endl << endl;
			cout << q->data.matchID	<< "\t";
			cout << q->data.matchTitle << "\t";
			cout << q->data.matchTime << "\t";
			cout << q->data.matchAddress << "\t";
			cout << q->data.matchContent << "\t";
			cout << q->data.matchPrincipal << endl << endl;
			break;
		}

		q = q->next;
	}

	if (find == 0)
		cout << "比赛编号" << id << "不存在" << endl << endl;

	return Status();
}

