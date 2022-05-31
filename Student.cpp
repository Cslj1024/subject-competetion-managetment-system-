#include "stdafx.h"
#include "Student.h"


Student::Student()
{
	this->account = "Stu";
	this->password = "123";
	this->role = -1;
	M = new List;
	M->next = NULL;
}


Student::~Student()
{
}

void Student::Register(string account, string password)
{
	fstream file("Students.txt", ios::in | ios::app);
	
	string line1, line2;
	cout << "当前是学生注册页面 : " << endl << endl;
	cout << "请输入账号 : "; cin >> account;
	cout << endl;
	

	

	while (file.peek() != EOF) {
		getline(file, line1);
		//getline(file1, line2);
		if (line1 == account) {
			cout << "该账号已被注册!" << endl << endl;
			//cout << "密码为—— " << line2 << endl << endl;
			file.close();
			return;
		}
	}
	
	cout << "请输入密码 : "; cin >> password;
	cout << endl;
	if (file.is_open()) {
		fstream file("Students.txt", ios::out | ios::app);
		file << account << endl << password << endl;
		cout << "注册成功!" << endl << endl;
		this->account = account;
		this->password = password;
		file.close();
		this->Display();
	}
}

Status Student::Login(string account, string password)
{
	fstream file("Students.txt", ios::in);
	string line1, line2;
	int flag = 1;
	cout << "当前是学生登录页面 : " << endl << endl;
	cout << "请输入登录账号 : "; cin >> account;
	cout << endl;
	cout << "请输入登录密码 : "; cin >> password;
	cout << endl;
	if (file.is_open()) {
		while (file.peek()!=EOF) {
			getline(file, line1);
			getline(file, line2);
			if (line1 == account&&line2 == password) {
				file.close();
				ID = account;
				return TRUE;
			}
		}
		file.close();
		//return FALSE;
		return TRUE;
	}
}

void Student::Display()
{
	cout << "学生账号 : " << this->account << endl << endl;
	cout << "学生密码 : " << this->password << endl << endl;
}

void Student::AfterLogin(Student *S,List *L)
{
	int flag = 0;
	int operation;
	cout << "1.浏览比赛信息\t2.查看参赛信息\t3.报名参加比赛\t4.退出比赛\t5.退出学生登陆界面" << endl << endl;
	Load();
	while (true) {
		cout << "请选择相关操作数—— "; cin >> operation;
		cout << endl;
		switch (operation) {
		case 1:
			
			S->QuerryMatch(L);
			system("pause");
			cout << endl;
			break;
		case 2:
			ShowMatch();
			system("pause");
			cout << endl;
			break;
		case 3:
			system("cls");
			cout << "当前是学生参赛界面—— " << endl << endl;
			S->QuerryMatch(L);
			S->JoinMatch(S, L);

			break;
		case 4:
			system("sys");
			S->ExitMatch(S, L);

			break;
		case 5:
			cout << "是否退出当前界面 [1:是 0:否]\t"; cin >> flag;
			cout << endl;
			if (flag) {
				cout << "成功退出当前界面!" << endl << endl;
				return;
			}
			continue;
		default:
			cout << "输入有误,请按规定操作数输入!" << endl;
			break;
		}
	}
}

void Student::QuerryMatch(List * L)
{
	
	fstream file;
	string line;
	file.open("MatchInfo.txt", ios::in);
	
	cout <<"编号\t\t"<<"项目\t\t\t\t"<<"时间\t\t"<<"地点\t"<<"内容\t"<<"负责人\t\t" << endl << endl;
	
	int index = 1;
	while (file.peek()!=EOF) {
		getline(file, line);
		cout << line << "\t";
		if (index++ % 6 == 0) {
			cout << endl << endl;
		}
	}
	file.close();
	cout << endl;
	
	
}

Status Student::JoinMatch(Student * S, List * L)
{
	string id;
	
	//fstream file1("MatchInfo.txt", ios::in);

	string filename = "SignUp_" + this->ID + ".txt";
	fstream file2(filename, ios::out);

	string line;

	//if (file1.is_open()) {

	//	while (file1.peek() != EOF) {
	//		getline(file1, line);
	//		file2 << line << endl;
	//	}
	//	
	//}


	//cout << "编号\t\t" << "项目\t\t\t\t" << "时间\t\t" << "地点\t" << "内容\t" << "负责人\t\t" << endl << endl;
	//cout << "请输入学号—— "; cin >> S->ID;
	//cout << endl;
	cout << "请输入比赛编号—— "; 
	cin >> id;
	List *p = L;
	List *q = p->next;
	List *l = M;
	while (l->next)
		l = l->next;

	int find = 0;
	while (q != NULL)
	{
		if (q->data.matchID == id)
		{
			List *n = new List;
			n->data.matchID = q->data.matchID;
			n->data.matchTime = q->data.matchTime;
			n->data.matchAddress = q->data.matchAddress;
			n->data.matchContent = q->data.matchContent;
			n->data.matchPrincipal = q->data.matchPrincipal;
			n->data.matchTitle = q->data.matchTitle;
			n->next = NULL;
			l->next = n;
			find = 1;
			cout << "报名成功!" << endl;
			
			break;
		}

		q = q->next;
	}
	file2.close();

	if (find == 0)
		cout << "比赛编号" << id << "不存在" << endl;
	else
		Save();
	
	return Status();
}

Status Student::ExitMatch(Student * S, List * L)
{
	int find = 0;
	string id;
	cout << "当前是退出比赛界面: " << endl << endl;
	cout << "输入比赛编号:";
	cin >> id;

	List *p = M;
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
	else
		Save();
	return Status();
}

void Student::ShowMatch()
{
	fstream file;
	string line;
	string filename = "SignUp_" + this->ID + ".txt";
	file.open(filename, ios::in);

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

void Student::Load()
{
	fstream file;
	string filename = "SignUp_" + this->ID + ".txt";
	file.open(filename, ios::in);
	M = new List;
	M->next = NULL;
	List *p = M;

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

void Student::Save()
{
	string filename = "SignUp_" + this->ID + ".txt";
	fstream file;
	file.open(filename, ios::out);

	List *q = M->next;
	while (q)
	{
		file << q->data.matchID << endl
			<< q->data.matchTitle << endl
			<< q->data.matchTime << endl
			<< q->data.matchAddress << endl
			<< q->data.matchContent << endl
			<< q->data.matchPrincipal << endl;
		q = q->next;
	}
	file.close();
}
