// In India the currency is made up of Rupee denominations Re. 1,
// Rs. 2, Rs. 5, Rs. 10, Rs.20, Rs. 50, Rs. 100, Rs. 500 and Rs. 2000.

// A bank is trying to find the number of notes of each denomination
// that the teller can give a customer for a certain amount of money,
// such that he has to handle minimum number of notes. Write a program
// to list out the number of notes of each denomination for an amount
// received through the keyboard.

// Project: chap 02 challenge 08
// Program that tells the denomination and number of notes required to
// tender a particular amount

// to compile with cygwin:
// g++ -std=c++14 challenge08.cpp && ./a.exe

#include <iostream>
#include <map>

int howManyNotesOf(const& amount, const& bankNoteValue)
{
  return amount / bankNoteValue;
}

int main()
{
	std::cout << "101 C++ challenges - chapter 02, challenge 08" << std::endl;
	int amount{0};
	std::map <int,int> resultMap {
				      {1,    0},
				      {2,    0},
				      {5,    0},
				      {10,   0},
				      {20,   0},
				      {50,   0},
				      {100,  0},
				      {500,  0},
				      {2000, 0}
	};
	std::cout << "How much?  ";
	std::cin >> amount;
	
	std::cout << "Results: " << std::endl;
	std::map<int,int>::reverse_iterator rit;
	int reste{amount};
	for (rit=resultMap.rbegin(); rit!=resultMap.rend(); ++rit)
	  {
	    rit->second =  howManyNotesOf(reste, rit->first);
	    reste = reste - rit->second*rit->first;
	  }
	for (rit=resultMap.rbegin(); rit!=resultMap.rend(); ++rit)
	  {
	    std::cout << rit->first << " => " << rit->second << " banknote(s), making " << rit->first*rit->second << '\n';
	  }
	
}


