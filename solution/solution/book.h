#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Book
{
	//Пергерузка операторов (через дружественные ф-ии)
	friend std::ostream &operator << (std::ostream &, const Book &);	//1
	friend std::istream &operator >> (std::istream &, Book &);			//2
	
public:
	//Пергерузка операторов
	//bool operator!();
	Book * operator+(const Book &) const;	//3
	bool operator==(const Book &) const;	//4
	bool operator!=(const Book &) const;	//5
	const Book &operator = (const Book &);	//6
	operator char*() const;					//7
	operator bool() const;					//8

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
