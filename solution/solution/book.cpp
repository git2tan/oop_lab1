#include "book.h"

int Book::count = 0;

Book::Book()
{
	std::cout << "create new!" << std::endl;
	strcpy(Title,"<empty>");
	strcpy(Author,"<empty>");
	inLib = false;
	//isExist = false;
	count++;
}
Book::Book(char *Title, char *Author, bool inLib)
{
	setTitle(Title);
	setAuthor(Author);
	setInLib(inLib);
}
void Book::printBook()
{
	//if (isExist)
		std::cout << std::setw(20) << std::left << this->Title << std::setw(20) << std::left << this->Author << (inLib ? "YES" : "NO") << std::endl;
	//else
		//std::cout << std::endl;
}
void Book::setTitle(char *Title)
{
	strcpy(this->Title,Title);
}
void Book::setAuthor(char *Author)
{
	strcpy(this->Author,Author);
}
void Book::setInLib(bool inLib)
{
	this->inLib = inLib;
}
void Book::giveOut()
{
	if (this->inLib)
	{
		this->inLib = false;
		std::cout << "Book \"" << this->Title << "\" is give out!" << std::endl;
	}
	else
	{
		std::cout << "Book \"" << this->Title << "\" is already out of library! Fail!" << std::endl;
	}
}
void Book::changeStatus()
{
	if (this->inLib==true)
	{
		this->inLib = false;
	}
	else
	{
		this->inLib = true;
	}
}

Book::~Book()
{
	count--;
}

int Book::GetCount()
{
	return count;
}