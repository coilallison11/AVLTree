//****************************************************************************************************
//
//         File:                        AVLDriver.cpp
//
//         Student:                     Allison Coil
//
//         Assignment:                  Assignment #8
//
//         Course Name:                 Data Structures   II
//
//         Course Number:               COSC 3100 - 01
//
//         Due:                         Nov 5, 2021
//
//
//         This program acts as a driver to test the AVLTree class
//	       
//
//****************************************************************************************************

#include "AVLTree.h"
#include "Stock.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//****************************************************************************************************

int main ()
{
	AVLTree <int> intTree;
	const int MAX = 5000;
	const int MIN = 1;
	unsigned seed = time (0);
	srand (seed);
	int temp;

	AVLTree <Stock> stockTree;
	fstream file ("Stock.txt");
	string name;
	string symbol;
	double price;
	Stock tempStock;
	char choice = 'A';
	Stock * sPtr;

	for ( int i = 0; i < 10; i ++ )
	{
		temp = ( rand () % ( MAX - MIN + 1 ) ) + MIN;
		intTree.insert (temp);
	}

	intTree.preorder ();
	cout << endl;
	intTree.inorder ();
	cout << endl;
	intTree.postorder ();
	cout << endl << "Height: " << intTree.height () << endl << endl;
	intTree.destroy ();

	for ( int i = 0; i < 8; i ++ )
	{
		if ( i > 0 )
		{
			file.ignore ();
		}

		getline (file, name);
		tempStock.setName (name);
		file >> symbol;
		tempStock.setSymbol (symbol);
		file >> price;
		tempStock.setPrice (price);
		stockTree.insert (tempStock);
	}

	while ( ( choice != 'E' ) && ( choice != 'e' ) )
	{
		cout << "A) Display a stock's name given its symbol" << endl;
		cout << "B) Display a stock's price given its symbol" << endl;
		cout << "C) Insert a new stock" << endl;
		cout << "D) Display all stocks" << endl;
		cout << "E) Quit" << endl << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch ( choice )
		{
			case 'A':
			case 'a':
				cout << endl << "Enter the stock symbol: ";
				cin >> symbol;
				tempStock.setSymbol (symbol);
				sPtr = stockTree.search (tempStock);

				if ( sPtr )
				{
					cout << sPtr -> getName () << endl << endl;
				}
				else
				{
					cout << symbol << " is not in the tree." << endl << endl;
				}
				break;
			case 'B':
			case 'b':
				cout << endl << "Enter the stock symbol: ";
				cin >> symbol;
				tempStock.setSymbol (symbol);
				sPtr = stockTree.search (tempStock);

				if ( sPtr )
				{
					cout << "$" << sPtr -> getPrice () << endl << endl;
				}
				else
				{
					cout << symbol << " is not in the tree." << endl << endl;
				}
				break;
			case 'C':
			case 'c':
				cin.ignore ();
				cout << "Enter the stock name: ";
				getline (cin, name);
				tempStock.setName (name);
				cout << "Enter the stock symbol: ";
				cin >> symbol;
				tempStock.setSymbol (symbol);
				cout << "Enter the stock price: ";
				cin >> price;
				tempStock.setPrice (price);
				stockTree.insert (tempStock);
				cout << symbol << " added." << endl << endl;
				break;
			case 'D':
			case 'd':
				stockTree.inorder ();
				cout << endl;
				break;
			case 'E':
			case 'e':
				file << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				stockTree.inorder (file);
				break;
			default:
				cout << "Please enter a valid choice." << endl << endl;
		}
	}

	file.close ();
	return 0;
}

//****************************************************************************************************

/*
393  BF: -1
26  BF: 0
2  BF: 0
122  BF: 0
1792  BF: 0
1516  BF: 1
1119  BF: 0
2478  BF: 0
1910  BF: 0
3552  BF: 0

2  BF: 0
26  BF: 0
122  BF: 0
393  BF: -1
1119  BF: 0
1516  BF: 1
1792  BF: 0
1910  BF: 0
2478  BF: 0
3552  BF: 0

2  BF: 0
122  BF: 0
26  BF: 0
1119  BF: 0
1516  BF: 1
1910  BF: 0
3552  BF: 0
2478  BF: 0
1792  BF: 0
393  BF: -1

Height: 4

A) Display a stock's name given its symbol
B) Display a stock's price given its symbol
C) Insert a new stock
D) Display all stocks
E) Quit

Enter your choice: d
Apple                    AAPL      $121.73
  BF: 0
Advanced Micro Devices   AMD       $84.51
  BF: 1
Intel                    INTC      $60.78
  BF: 1
Motorola Inc.            MOT       $17.49
  BF: 0
Microsoft Corp.          MSFT      $28.11
  BF: 1
NVIDIA                   NVDA      $548.58
  BF: 0
Sony                     SNE       $105.81
  BF: 0
Tesla                    TSLA      $564.33
  BF: 0

A) Display a stock's name given its symbol
B) Display a stock's price given its symbol
C) Insert a new stock
D) Display all stocks
E) Quit

Enter your choice: c
Enter the stock name: Emerson
Enter the stock symbol: EMR
Enter the stock price: 12.34
EMR added.

A) Display a stock's name given its symbol
B) Display a stock's price given its symbol
C) Insert a new stock
D) Display all stocks
E) Quit

Enter your choice: d
Apple                    AAPL      $121.73
  BF: 0
Advanced Micro Devices   AMD       $84.51
  BF: 0
Emerson                  EMR       $12.34
  BF: 0
Intel                    INTC      $60.78
  BF: 1
Motorola Inc.            MOT       $17.49
  BF: 0
Microsoft Corp.          MSFT      $28.11
  BF: 1
NVIDIA                   NVDA      $548.58
  BF: 0
Sony                     SNE       $105.81
  BF: 0
Tesla                    TSLA      $564.33
  BF: 0

A) Display a stock's name given its symbol
B) Display a stock's price given its symbol
C) Insert a new stock
D) Display all stocks
E) Quit

Enter your choice: e
*/