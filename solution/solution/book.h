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
	bool isExist;

	static int count;
public:
	Book();
	//Book(char *, char *,bool);
	void printBook();
	
	//void insertBook();
	~Book();
	static int GetCount();
};

