#include "book.h"
#include <Windows.h>
/*
Вариант расчитывается по формуле MD5(Фамилия Имя)%16%9+1
Для меня это (4238fb56a816ea54b74611ec151630b0)%16%9+1=1
Так как первый вариант рассмотривали на лекции то беру 2.
Вариант № 2. Библиотечная карточка.
Класс должен отражать состояние книги из библиотечного каталога, и включать в себя сведения: 
название книги, автор, выдана ли книга или находится в библиотеке.
*/
void printHeader(const int);
int printMenu1();
int printMenu2(int, Book **, int);
void printMenu3(const int, Book**, const int);
void menu21(int, Book **, const int);
int choiseFrom(int);
void printData(Book **, int);
void addByIndx(Book **, int, const int);
void addByIndxEmpty(Book**, int, const int);
void addToEmpty(Book**, const int);
void delByIndx(Book **, int,const int);

void giveOutBook(Book*);
void inputTheTitle(Book*);
void inputTheAuthor(Book*);
void inputTheStatus(Book*);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void main()
{
	bool isExit = 0;
	int sizeOfDB;
	std::cout << "Please, enter the size of the DB" << std::endl;
	std::cout << ">>>";
	std::cin >> sizeOfDB;
	Book **booksData = new Book*[sizeOfDB];
	for (int i = 0; i < sizeOfDB; i++)
		booksData[i] = NULL;
		
	while (!isExit)
	{
		system("cls");
		printHeader(sizeOfDB);
		
		printData(booksData, sizeOfDB);

		if (printMenu2(printMenu1(), booksData, sizeOfDB) == -1)
			isExit = 1;		
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void printHeader(const int sizeOfData)
{
	std::cout << "INFORMATION: sizeOfDataBase = " << sizeOfData << "   objCount = " << Book::GetObjCount() << std::endl;
	std::cout << std::setw(3) << std::left <<" ##"<< std::setw(20) << std::left << "|   TITLE" << std::setw(20) << std::left << "|  AUTHOR" << "| IN LIBRARY" <<"|"<< std::endl;
	std::cout << std::setw(56) << std::setfill('-') <<"-"<<std::setfill(' ')<< std::endl;
}
int printMenu1()
{
	std::cout << std::endl;
	std::cout << std::setw(56) << std::setfill('+') << "+" << std::setfill(' ') << std::endl;
	std::cout << std::setw(8)<< " 1.Add " <<std::setw(20)<< " 2.Del by indx" <<std::setw(20)<< "3.Change by indx" <<std::setw(10)<<"4.Exit"<< std::endl;
	int ch;
	ch = choiseFrom(4);
	return ch;
}
int printMenu2(int ch, Book **Data, int sizeOfData)
{
	
	if (ch == -1)
		return -1;
	switch (ch)
	{
	case 1:																//add
			std::cout << "1.Add in empty slot   2.Add by indx    3.Add by indx (<empty>)   4.To Main" << std::endl;
			menu21(choiseFrom(4), Data, sizeOfData);
			break; 
	case 2:																//del by index
			std::cout << "Please, input indx" << std::endl; 
			std::cout << ">>>";
			int indx;
			std::cin >> indx;
			delByIndx(Data, indx, sizeOfData);
			break; 
	case 3:																//change by index
			std::cout << "Please, input indx" << std::endl; 
			int tmpIndx;
			std::cin >> tmpIndx;
			printMenu3(tmpIndx, Data, sizeOfData);
			return 1;
			break;												
	case 4:																// exit
			return -1;											
	}
	return 1;
}
void printMenu3(const int indx, Book**Data, const int sizeOfData)
{
	if (indx < 0 || indx >= sizeOfData)
	{
		std::cout << "You out of DataBase" << std::endl;
		system("pause");
		return;
	}
	else
	{
		if (Data[indx] == NULL) //если слот не проинициализирован
		{
			std::cout << "Error! Slot is not inicialize! Do you want INICIALIZE AND CHANGE? Yes(1) or no (0)?" << std::endl;
			std::cout << ">>>";
			
			int tmpAnswer;
			std::cin >> tmpAnswer;
			
			if (tmpAnswer == 1)
			{
				addByIndx(Data, indx, sizeOfData);
				return;
			}
			if (tmpAnswer == 0)
				return;
				
		}
		if (Data[indx] != NULL)
		{
			std::cout << "1.Change Title  2.Change Author  3.Change the status (In Lib) 4.Give out the book  5.To Main" << std::endl;
			int tmpAnswer = choiseFrom(5);
			switch (tmpAnswer)
			{
			case -1: 
				break;
			case 1:									//1.Change the Title
				inputTheTitle(Data[indx]);
				break;	
			case 2:									//2.Change the Author
				inputTheAuthor(Data[indx]);
				break;	
			case 3:									//3.Change the status (In Lib)
				Data[indx]->changeStatus();
				break;	
			case 4:									//4.Give out the book
				giveOutBook(Data[indx]);
				break;	
			}
		}
	}
}
int choiseFrom(int counOfChoise)
{
	int ch;
	while (true)
	{
		while (true)
		{
			std::cout << ">>>";
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cin >> ch;
			if (std::cin.peek() == '\n') 
			{
				std::cin.get();
				break;
			}
			else {
				std::cout << "you input not a number!!! Carefully..." << std::endl;
				std::cin.clear();
				while (std::cin.get() != '\n') {}
			}
		}
		
		if (ch == counOfChoise)
			return -1;
		if (ch < 1 || ch>counOfChoise)
		{
			std::cout << "Sorry, not valid menu item, try again" << std::endl;
		}
		else
			return ch;
	}
}
void printData(Book **booksData, int sizeOfData)
{
	int count = Book::GetObjCount();
	
	for (int i = 0; i < sizeOfData&&count>0; i++)
	{
		
		if (booksData[i] != NULL)
		{
			std::cout << " " << std::setw(3) << i;
			booksData[i]->printBook();
			count--;
		}
		
	}
	
}
void menu21(int choise, Book **Data, const int sizeOfData)
{
	if (choise == -1)
		return;
	switch (choise)
	{
	case 1:
	{
		addToEmpty(Data, sizeOfData);
	}; break; //add in empty slot
	case 2:
	{
		std::cout << "Please, input indx" << std::endl;
		std::cout << ">>>";
		int choise1;
		std::cin >> choise1;
		addByIndx(Data, choise1, sizeOfData);
	}; break;//Add by indx
	case 3:
	{
		std::cout << "Please, input indx" << std::endl;
		std::cout << ">>>";
		int choise1;
		std::cin >> choise1;
		addByIndxEmpty(Data, choise1, sizeOfData);
	}; break;
	}


}
void addByIndx(Book ** Data, int indx, const int sizeOfData)
{
	if (indx < sizeOfData && indx >= 0 && Data[indx] == NULL)
	{
		Data[indx] = new Book();
		inputTheTitle(Data[indx]);
		
		inputTheAuthor(Data[indx]);
		
		inputTheStatus(Data[indx]);
		
	}
	else
		std::cout << "uncorrect index" << std::endl;
	system("pause");
}
void addByIndxEmpty(Book ** Data, int indx, const int sizeOfData)
{
	if (indx < sizeOfData && indx >= 0 && Data[indx] == NULL)
	{
		Data[indx] = new Book();
		

	}
	else
		std::cout << "uncorrect index" << std::endl;
	//system("pause");
}
void addToEmpty(Book**Data, const int sizeOfData)
{
	int i;
	for (i = 0; i < sizeOfData; i++)
	{
		if (Data[i] == NULL)
			break;
	}
	if (i >= sizeOfData)
		std::cout << "Data is FULL!!!" << std::endl;
	else
		addByIndx(Data, i, sizeOfData);
}
void delByIndx(Book ** Data, int indx,const int sizeOfData)
{
	if ((indx >= 0) && (indx < sizeOfData))
	{
		if (Data[indx] != NULL)
		{
			delete(Data[indx]);
			Data[indx] = NULL;
		}
		else
		{
			std::cout << "already was empty!" << std::endl;
			system("pause");
		}
	}
	else
	{
		std::cout << "Error! Uncorrect index!"<<std::endl;
	}
	
}

void giveOutBook(Book* srcBook)
{
	if (srcBook->getInLib())
		srcBook->giveOut();
	else
	{
		std::cout << "It is already give out!" << std::endl;
		system("pause");
	}
}
void inputTheTitle(Book* srcBook)
{
	std::cout << "Please, input the new Title" << std::endl;
	std::cout << ">>>";
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::string s;
	std::getline(std::cin, s);
	srcBook->setTitle(s);
}
void inputTheAuthor(Book*srcBook)
{
	std::cout << "Please, input the new Author" << std::endl;
	std::cout << ">>>";
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	std::string s;
	std::getline(std::cin, s);
	srcBook->setAuthor(s);
}
void inputTheStatus(Book*srcBook)
{
	std::cout << "Is book in Library? Yes(1) or no(0)" << std::endl;
	std::cout << ">>>";
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	int tmp;
	std::cin >> tmp;
	while (true)
	{
		if (tmp == 1)
		{
			srcBook->setInLib(true);
			break;
		}
		if (tmp == 0)
		{
			srcBook->setInLib(false);
			break;
		}
		std::cout << "Sorry, uncorect input. Try again! Is book in Library? Yes(1) or no(0)" << std::endl;
		std::cout << ">>>";
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> tmp;
	}
}