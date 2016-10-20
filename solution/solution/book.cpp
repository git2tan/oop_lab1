#include "book.h"

int Book::objCount = 0;

//конструкторы:
Book::Book():Title("<empty>"), Author("<empty>"), inLib(false)
{
	std::cout << "create new!" << std::endl;
	objCount++;
}
Book::Book(std::string Title, std::string Author, bool inLib):Title(Title), Author(Author), inLib(inLib)
{
	objCount++;
}
Book::Book(const Book &book)
{
	this->Title = book.Title;
	this->Author = book.Author;
	this->inLib = book.inLib;
	objCount++;
}

//сеттеры:
void Book::setInLib(bool inLib)
{
	this->inLib = inLib;
}
void Book::setTitle(std::string Title)
{
	if (!Title.empty())
		this->Title = Title;
	else
		this->Title = "<empty(default)>" + std::to_string(objCount);
}
void Book::setAuthor(std::string Author)
{
	if (!Author.empty())
		this->Author = Author;
	else
		this->Author = "<no name>" + std::to_string(objCount);
}

//прочие методы:
void Book::printBook()
{
	std::cout << std::setw(20) << std::left << this->Title << std::setw(20) << std::left << this->Author << (inLib ? "YES" : "NO") << std::endl;
}
int Book::giveOut()
{
	if (this->inLib)
	{
		this->inLib = false;
		return 1;
	}
	else
	{
		return -1;
	}
}
void Book::changeInLibStatus()
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

//геттеры:
int Book::GetObjCount()
{
	return objCount;
}
bool Book::getInLib() const
{
	return this->inLib;
}
std::string Book::getTitle() const
{
	return this->Title;
}

std::string Book::getAuthor() const
{
	return this->Author;
}

//деструкторы:
Book::~Book()
{
	std::cout << "Destructor" << std::endl;
	objCount--;
	system("pause");
}

