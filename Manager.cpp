#include "stdafx.h"
#include "Manager.h"


Status Manager::Login(string account, string password)
{
	
	cout << "当前是管理员登录页面 : " << endl << endl;
	cout << "请输入登录账号 : "; cin >> account;
	cout << endl;
	cout << "请输入登录密码 : "; cin >> password;
	cout << endl;
	
	if (account.compare(this->account) == 0 && password.compare(this->password) == 0)
		return TRUE;
	else
		return FALSE;	
}
	
	



void Manager::AfterLogin(List * L)
{
	int flag = 0;
	int n = 0, i = 0;
	int operation;
	MatchInfo m;
	

	while (true) {
		cout << "1.添加比赛信息\t2.删除比赛信息\t3.修改比赛信息\t4.查找比赛信息\t5.退出登陆界面" << endl << endl;
		cout << "请选择相关操作数—— "; cin >> operation;
		cout << endl;
		switch (operation) {
		case 1:
			system("cls");
			L->ListInsert(L,n);
			system("pause");
			system("cls");
			SaveMatch(L);
			break;
		case 2:
			system("cls");
			L->ListDelete(L, m);
			system("pause");
			system("cls");
			SaveMatch(L);
			break;
		case 3:
			system("cls");
			L->UpdateList(L, m);
			system("pause");
			system("cls");
			SaveMatch(L);
			break;
		case 4:
			system("cls");
			L->Equal(L, m);
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "是否退出当前界面 [1:是 0:否]\t"; cin >> flag;
			cout << endl;
			if (flag) {
				cout << "成功退出当前界面!" << endl << endl;
				system("pause");
				return;
			}
			continue;
		default:
			cout << "输入有误,请按规定操作数输入!" << endl << endl;
			break;
		}
	}
}

void Manager::QuerryMatch()
{
	fstream file;
	string line;
	file.open("MatchInfo.txt", ios::in);

	cout << "编号\t\t" << "项目\t\t\t\t" << "时间\t\t" << "地点\t" << "内容\t" << "负责人\t\t" << endl << endl;

	int index = 1;
	while (file.peek() != EOF) {
		getline(file, line);
		cout << line << "\t";
		if (index++ % 6 == 0) {
			cout << endl << endl;
		}
	}
	file.close();
	cout << endl;
}

void Manager::SaveMatch(List *L)
{
	fstream file;
	file.open("MatchInfo.txt", ios::out);

	List *q = L->next;
	while (q)
	{
		file << q->data.matchID			<< endl
			<< q->data.matchTitle		<< endl
			<< q->data.matchTime		<< endl
			<< q->data.matchAddress		<< endl
			<< q->data.matchContent		<< endl
			<< q->data.matchPrincipal   << endl;
		q = q->next;
	}
	file.close();
}

void Manager::Display()
{
	cout << "管理员账号 : " << this->account << endl << endl;
	cout << "管理员密码 : " << this->password << endl << endl;
}

Manager::Manager()
{
}


Manager::~Manager()
{
}


