// 学科竞赛管理系统.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "List.h"
#include "Role.h"
#include "Student.h"
#include "Manager.h"
#include "MatchInfo.h"



int operation, n;
string account, password;
Status i;


void Menu() {
	cout << "--------------------学科竞赛管理系统--------------------" << endl << endl;
	cout << " 1、学生注册 " << endl << endl;
	cout << " 2、学生登录 " << endl << endl;
	cout << " 3、管理员登录 " << endl << endl;
	cout << " 4、退出 " << endl << endl;
	cout << "------------------------------------------------------" << endl << endl;
}

void LoadMatch(List **L)
{
	fstream file;
	file.open("MatchInfo.txt", ios::in);
	List *p = *L;

	while (file.peek() != EOF) {
		List *n = new List;
		getline(file, n->data.matchID);
		getline(file, n->data.matchTitle);
		getline(file, n->data.matchTime);
		getline(file, n->data.matchAddress);
		getline(file, n->data.matchContent);
		getline(file, n->data.matchPrincipal);
		n->next = NULL;
		p->next = n;
		p = p->next;
	}
	file.close();
}

int main()
{
	
	Student *S = new Student();
	Manager *m = new Manager();
	List *L = new List();
	L->InitList(L);
	LoadMatch(&L);
	//m->Display();
	//L->ListInsert(L, n);
	//L->ListTraverse(L);
	while (true) {
		Menu();
		cout << "请选择相应操作数—— "; cin >> operation;
		switch (operation) {
		case 1:
			system("cls");
			S->Register(account, password);
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			i=S->Login(account, password);
			//i = 1;
			if (i) {
				cout << "登陆成功!" << endl << endl;
				S->AfterLogin(S,L);
			}else
				cout << "登录失败!" << endl << endl;
			system("pause");
			system("cls");
			break;
		/*case 3:
			system("cls");
			S->JoinMatch(S, L);
			system("pause");
			system("cls");
			break;*/
		case 3:
			system("cls");
			i=m->Login(account, password);
			//i = 1;
			if (i) {
				cout << "成功登陆!" << endl << endl;
				m->QuerryMatch();
				m->AfterLogin(L);
				system("cls");
			}
			else {
				cout << "登陆失败!" << endl << endl;
				system("pause");
				system("cls");
			}
			break;
		case 4:
			cout << endl;
			cout << "成功退出学科竞赛管理系统!" << endl << endl;
			exit(0);
		default:
			cout << endl << "当前输入有误,请按规定指令输入!" << endl << endl;
			system("pause");
			system("cls");

		}
}
    return 0;
}


