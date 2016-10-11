
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
void printHeader();
int printMenu1();
int printMenu2(int, Book **);
void menu21(int, Book **);
int choiseFrom(int);
void printData(Book **, int);
void addByIndx(Book **, int);
void addToEmpty(Book**);
void delByIndx(Book **, int);
const int N = 15;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void main()
{
	bool isExit = 0;
	
	Book **booksData = new Book*[N];
	for (int i = 0; i < N; i++)
		booksData[i] = NULL;
	/*for (int i = 0; i < 5; i++)
		booksData[i] = new Book();
	booksData[10] = new Book();
	addByIndx(booksData, 7);*/
	
	while (!isExit)
	{
		system("cls");
		printHeader();
		
		printData(booksData, N);

		if (printMenu2(printMenu1(), booksData) == -1)
			isExit = 1;
		
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void printHeader()
{
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
int printMenu2(int ch, Book **Data)
{
	
	if (ch == -1)
		return -1;
	switch (ch)
	{
	case 1: {
			std::cout << "1.Add in empty slot" << "2.Add by indx"<<"3.Exit" << std::endl;
			menu21(choiseFrom(3), Data);
															};	break; //add
	case 2: {
			std::cout << "Please, input indx" << std::endl; 
			std::cout << ">>>";
			int indx;
			std::cin >> indx;
			delByIndx(Data, indx);
															};		break; //del by index
	case 3: std::cout << "Please, input indx" << std::endl;		break; //change by index
	case 4: return -1; break;											// exit
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
void printData(Book **booksData, int countOfBook)
{
	for (int i = 0; i < countOfBook; i++)
	{
		std::cout<<" "<<std::setw(3) << i;
		if (booksData[i] != NULL)
		{
			booksData[i]->printBook();
		}
		else
			std::cout << std::endl;
	}
}
void menu21(int choise, Book **Data)
{
	if (choise == -1)
		return;
	switch (choise)
	{
	case 1:
	{
		addToEmpty(Data);
	}; break; //add in empty slot
	case 2:
	{
		std::cout << "Please, input indx" << std::endl;
		std::cout << ">>>";
		int choise1;
		std::cin >> choise1;
		addByIndx(Data, choise1);
	}; break;//Add by indx
	case 3:return;
	}


}
void addByIndx(Book ** Data, int indx)
{
	if (indx < N && indx >= 0)
		Data[indx] = new Book();
	else
		std::cout << "uncorrect index" << std::endl;
}
void addToEmpty(Book**Data)
{
	int i;
	for (i = 0; i < N; i++)
	{
		if (Data[i] == NULL)
			break;
	}
	if (i >= N)
		std::cout << "Data is FULL!!!" << std::endl;
	else
		addByIndx(Data, i);
}
void delByIndx(Book ** Data, int indx)
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
