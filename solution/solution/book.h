#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class Book
{
	char Title[40];
	char Author[40];
	bool inLib;
	
	static int count;
public:
	//������������:
	Book();
	Book(char *Title, char *Author,bool inLib);
	
	//�������:
	void setTitle(char *Title);
	void setAuthor(char *Author);
	void setInLib(bool inLib);
	
	//������ ������:
	void giveOut();
	void changeStatus();
	void printBook();
	
	//�������:
	static int GetCount();
	
	//����������:
	~Book();
};

