#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class Book
{
public:
	//������������:
	Book();
	Book(std::string, std::string, bool);
	Book(const Book &);
	
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
	bool getInLib() const;
	std::string getTitle() const;
	std::string getAuthor() const;
	
	//����������:
	~Book();
private:
	std::string Title;
	std::string Author;
	bool inLib;

	static int objCount;
};

