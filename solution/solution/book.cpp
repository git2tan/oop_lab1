#include "book.h"

int Book::objCount = 0;
//Пергерузка операторов
bool Book::operator !()
{
	return !this->inLib;
}
Book * Book::operator+(Book &rightObj)
{
	Book * tmp = new Book();
	tmp->Title = this->Title + rightObj.Title;
	tmp->Author = this->Author + rightObj.Author;
	tmp->inLib = true;
	return tmp;
}

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
Book &Book::setBook(std::string Title, std::string Author, bool inLib)
{
	this->Title = Title;
	this->Author = Author;
	this->inLib = inLib;
	return *this;
}
Book &Book::setInLib(bool inLib)
{
	this->inLib = inLib;
	return *this;
}
Book &Book::setTitle(std::string Title)
{
	if (!Title.empty())
		this->Title = Title;
	else
		this->Title = "<empty(default)>" + std::to_string(objCount);
	return *this;
}
Book &Book::setAuthor(std::string Author)
{
	if (!Author.empty())
		this->Author = Author;
	else
		this->Author = "<no name>" + std::to_string(objCount);
	return *this;
}

//прочие методы:
void Book::printBook() const
{
	std::cout	<< std::setw(20) << std::left << this->Title 
				<< std::setw(20) << std::left << this->Author 
				<< (inLib ? "YES" : "NO") << std::endl;
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
const bool Book::getInLib() const
{
	return this->inLib;
}
const std::string Book::getTitle() const
{
	return this->Title;
}
const std::string Book::getAuthor() const
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


//Дружественные функции
std::ostream &operator<<(std::ostream &output, const Book &obj)
{
	output	<< std::setw(20) << std::left << obj.Title 
			<< std::setw(20) << std::left << obj.Author 
			<< (obj.inLib ? "YES" : "NO") << std::endl;
	return output;
}

std::istream &operator >> (std::istream &in, Book &obj)
{
	std::cout << "Please, input the new Title" << std::endl;
	std::cout << ">>>";
	//std::cin.ignore(std::cin.rdbuf()->in_avail());
	in.ignore(in.rdbuf()->in_avail());
	std::getline(in, obj.Title);
	std::cout << "Ok.\n Now, please, input the new Author" << std::endl;
	std::cout << ">>>";
	in.ignore(in.rdbuf()->in_avail());
	std::getline(in, obj.Author);
	std::cout	<< "Ok.\nNow, please, answer the question - \nIs book in the Library? Yes(1) or no(0)" 
				<< std::endl;
		
	int ch;
	while (true)
	{
		while (true)
		{
			std::cout << ">>>";
			in.ignore(std::cin.rdbuf()->in_avail());
			in >> ch;
			if (in.peek() == '\n')
			{
				in.get();
				break;
			}
			else {
				std::cout << "you input not a number!!! Carefully..." << std::endl;
				in.clear();
				while (in.get() != '\n') {}
			}
		}

		if (ch == 1)
		{
			obj.inLib = true;
			return in;
		}
		if (ch == 0)
		{
			obj.inLib = false;
			return in;
		}
		std::cout << "Sorry, not valid menu item, try again" << std::endl;
			
	}
}
