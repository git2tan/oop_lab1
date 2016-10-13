#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class Book
{
	std::string Title;
	std::string Author;
	bool inLib;
	
	static int objCount;
public:
	//������������:
	Book();
	Book(std::string, std::string, bool);
	
	//�������:
	
	void setInLib(bool inLib);
	void setTitle(std::string);
	void setAuthor(std::string);
	
	//������ ������:
	int giveOut();//������ �����
	void changeInLibStatus();
	void printBook();
	
	//�������:
	static int GetObjCount();
	bool getInLib();
	
	//����������:
	~Book();
};

