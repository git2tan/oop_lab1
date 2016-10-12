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
int printMenu3(const int, Book**, const int);
void menu21(int, Book **, const int);
int choiseFrom(int);
void printData(Book **, int);
void addByIndx(Book **, int, const int);
void addByIndxEmpty(Book**, int, const int);
void addToEmpty(Book**, const int);
void delByIndx(Book **, int,const int);
void inputTheTitle(Book*);
void inputTheAuthor(Book*);
void inputTheStatus(Book*);
//const int N = 15;
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
	std::cout << "INFORMATION: sizeOfDataBase = " << sizeOfData << "   Book->count = " << Book::GetCount() << std::endl;
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
	case 1: {
			std::cout << "1.Add in empty slot   2.Add by indx    3.Add by indx (<empty>)   4.Exit" << std::endl;
			menu21(choiseFrom(4), Data, sizeOfData);
															};	break; //add
	case 2: {
			std::cout << "Please, input indx" << std::endl; 
			std::cout << ">>>";
			int indx;
			std::cin >> indx;
			delByIndx(Data, indx, sizeOfData);
															};		break; //del by index
	case 3: {
			std::cout << "Please, input indx" << std::endl; 
			int tmpIndx;
			std::cin >> tmpIndx;
			printMenu3(tmpIndx, Data, sizeOfData);
			return 1;
			};		break; //change by index
	case 4: return -1; break;											// exit
	}
}
int printMenu3(const int indx, Book**Data, const int sizeOfData)
{
	if(indx<0||indx>=sizeOfData)
		return -1;
	else
	{
		if (Data[indx] == NULL)
		{
			std::cout << "Error! Slot is not inicialize! Do you want inicialize? Yes(1) or no (0)?" << std::endl;
			std::cout << ">>>";
			int tmpAnswer;
			std::cin >> tmpAnswer;
			if (tmpAnswer == 1)
				addByIndxEmpty(Data, indx, sizeOfData);
			if (tmpAnswer == 0)
				return -1;
				
		}
		if (Data[indx] != NULL)
		{
			std::cout << "1.Change the Title  2.Change the Author  3.Change the status (In Lib) 4. Exit" << std::endl;
			int tmpAnswer = choiseFrom(4);
			switch (tmpAnswer)
			{
			case -1: return -1; break;
			case 1:inputTheTitle(Data[indx]); break;//1.Change the Title
			case 2:inputTheAuthor(Data[indx]); break;//2.Change the Author
			case 3:Data[indx]->changeStatus(); break;//3.Change the status (In Lib)
			}
		}
	}
}
int choiseFrom(int counOfChoise)
{
	int ch;
	while (true)
	{
		std::cout << ">>>";
		std::cin >> ch;
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
	int count = Book::GetCount();
	
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
	system("pause");
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
void inputTheTitle(Book*srcBook)
{
	std::cout << "Please, input the new Title" << std::endl;
	std::cout << ">>>";
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	char s[40];
	std::cin.getline(s, 40);
	srcBook->setTitle(s);
}
void inputTheAuthor(Book*srcBook)
{
	std::cout << "Please, input the new Author" << std::endl;
	std::cout << ">>>";
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	char s[40];
	std::cin.getline(s, 40);
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