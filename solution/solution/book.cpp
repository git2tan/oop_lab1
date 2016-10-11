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
void Book::printBook()
{
	//if (isExist)
		std::cout << std::setw(20) << std::left << this->Title << std::setw(20) << std::left << this->Author << (inLib ? "YES" : "NO") << std::endl;
	//else
		//std::cout << std::endl;
}

Book::~Book()
{
	count--;
}

int Book::GetCount()
{
	return count;
}