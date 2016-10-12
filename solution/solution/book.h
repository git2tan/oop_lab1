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
	//конструкторы:
	Book();
	Book(char *Title, char *Author,bool inLib);
	
	//сеттеры:
	void setTitle(char *Title);
	void setAuthor(char *Author);
	void setInLib(bool inLib);
	
	//прочие методы:
	void giveOut();
	void changeStatus();
	void printBook();
	
	//геттеры:
	static int GetCount();
	
	//деструктор:
	~Book();
};

