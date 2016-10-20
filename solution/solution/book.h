#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class Book
{
	//���������� ���������� (����� ������������� �-��)
	friend std::ostream &operator<<(std::ostream &, const Book &);
	friend std::istream &operator >> (std::istream &, Book &);
	//friend std::
public:
	//���������� ����������
	bool operator!();
	Book * operator+(Book &);
	//Book Book::operator++()
	//������������:
	Book();
	Book(std::string, std::string, bool);
	Book(const Book &);
	
	//�������:
	Book &setBook(std::string Title, std::string Author, bool inLib);
	Book &setInLib(bool inLib);
	Book &setTitle(std::string);
	Book &setAuthor(std::string);
	
	//������ ������:
	int giveOut();//������ �����
	void changeInLibStatus();
	void printBook() const;
	
	//�������:
	static int GetObjCount();
	const bool getInLib() const;
	const std::string getTitle() const;
	const std::string getAuthor() const;
	
	//����������:
	~Book();
	

private:
	std::string Title;
	std::string Author;
	bool inLib;

	static int objCount;
};
