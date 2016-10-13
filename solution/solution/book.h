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
	//конструкторы:
	Book();
	Book(std::string, std::string, bool);
	
	//сеттеры:
	
	void setInLib(bool inLib);
	void setTitle(std::string);
	void setAuthor(std::string);
	
	//прочие методы:
	int giveOut();//выдать книгу
	void changeInLibStatus();
	void printBook();
	
	//геттеры:
	static int GetObjCount();
	bool getInLib();
	
	//деструктор:
	~Book();
};

