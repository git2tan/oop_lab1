#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class Book
{
	//Пергерузка операторов (через дружественные ф-ии)
	friend std::ostream &operator<<(std::ostream &, const Book &);
	friend std::istream &operator >> (std::istream &, Book &);
	//friend std::
public:
	//Пергерузка операторов
	bool operator!();
	Book * operator+(Book &);
	//Book Book::operator++()
	//конструкторы:
	Book();
	Book(std::string, std::string, bool);
	Book(const Book &);
	
	//сеттеры:
	Book &setBook(std::string Title, std::string Author, bool inLib);
	Book &setInLib(bool inLib);
	Book &setTitle(std::string);
	Book &setAuthor(std::string);
	
	//прочие методы:
	int giveOut();//выдать книгу
	void changeInLibStatus();
	void printBook() const;
	
	//геттеры:
	static int GetObjCount();
	const bool getInLib() const;
	const std::string getTitle() const;
	const std::string getAuthor() const;
	
	//деструктор:
	~Book();
	

private:
	std::string Title;
	std::string Author;
	bool inLib;

	static int objCount;
};
