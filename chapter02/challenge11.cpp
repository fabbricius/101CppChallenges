// Project: chap 02 challenge 11

// January 1st 1900 was a Monday. The months April, June, September and
// November have 30 days, whereas the rest have 31 days, except
// February which has 29 or 28 depending on whether the year is leap or
// not. A leap year occurs on any year evenly divisible by 4, but not
// on a century unless it is divisible by 400. Write a program to find
// out how many Sundays fell on the first of the month during the
// twentieth century (January 1st 1901 to December 31st 2000)?
  
// To compile using the cygwin g++ compiler:
// g++ -std=c++14 challenge11.cpp && ./a.exe

// Output:
// Number of Sundays on the 1st of month: 171


// Key points to remember:
// - Show how to print an enum
// - show an example on how to iterate cyclically an enum (Taken from http://www.cplusplus.com/forum/beginner/41790/)

#include <iostream>

enum class Day { Mon, Tue, Wed, Thu, Fri, Sat, Sun };
enum class Month { };

std::ostream& operator<<(std::ostream& out, Day d) {
    switch (d) {
    case Day::Mon: out << "Monday"; break;
    case Day::Tue: out << "Tuesday"; break;
    case Day::Wed: out << "Wednesday"; break;
    case Day::Thu: out << "Thursday"; break;
    case Day::Fri: out << "Friday"; break;
    case Day::Sat: out << "Saturday"; break;
    case Day::Sun: out << "Sunday"; break;
    default: out << int(d); break;
    }
    return out;
}

// DOW: day of week
inline Day& operator++(Day& eDOW, int)  // <--- note -- must be a reference
{
   const int i = static_cast<int>(eDOW);
   eDOW = static_cast<Day>((i + 1) % 7); // '% 7' because 7 entries in the enum
   return eDOW;
}

bool isLeapYear(const int& year)
{
  if (year % 4 == 0 )
    {
      // year is divisible by 4: might be a leap year...
      //std::cout << "year " << year << " is divisible by 4: might be a leap year" << std::endl;
      if (year % 100 == 0)
	{
	  //std::cout << "but year " << year << " is a century year (divisible by 100): might not be a leap year" << std::endl;
	  // not a leap year because we are on a century year. But there is an exeception:
	  if (year % 400 == 0)
	    {
	      //std::cout << "ah, in fact year " << year << " is also divisible by  400 so really a leap year" << std::endl;
	      return true;
	    }
	  //std::cout << "year " << year << " est divisible par 100" << std::endl;
	}
      else
	return true;
    }
  //std::cout << "year " << year << " is not a leap year !" << std::endl;
  return false;
}

bool isDayReal(const int& year, const int& month, const int& day)
{
  int maxDate{0};
  if (day < 1 || day > 31)
    return false;
  
  if (day > 28)
    {
      switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	  return true;
	case 4:
	case 6:
	case 9:
	case 11:
	  return (day < 31);
	case 2:
	  {
	    //   return a < b ? b:a;
	    return isLeapYear(year) ? (day <= 29) : (day <= 28);
	  }
	default:
	  return false;
	}
    }
  return true;
}

int main()
{
  std::cout << "101 C++ challenges - chapter 02, challenge 11" << std::endl;
  int numberOfSundaysOnFirst{0};
  //int numberOfSundaysOnFirst{0};
  Day currentDay = Day::Mon; // we will start on the Monday 01/01/1900
  // Go through each year, starting from 1900 (because we know that 01/01/1900 was a monday)
  for (int y=1900; y <= 2000; ++y)
    {
      // go through each month
      for (int m=01; m <= 12; ++m)
	{
	  // go through each days of the month
	  for (int d=01; d <= 31; ++d)
	    {
	      // is this day an existing one ?
	      if (isDayReal(y,m,d))
		{
		  // Are we in the 20th century?
		  if (y >= 1901 && y <= 2000)
		    {
		      // We can count the number of day required
		      if ( d == 01 && currentDay == Day::Sun)
			numberOfSundaysOnFirst++;
		    }
		  currentDay++;
		}
	    }
	}
    }
  std::cout << "Number of Sundays on the 1st of month: " << numberOfSundaysOnFirst << std::endl;

  /*
  std::cout << "isLeapYear() for year 1900: " << std::boolalpha << isLeapYear(1900) << std::endl;
  std::cout << "isLeapYear() for year 2000: " << std::boolalpha << isLeapYear(2000) << std::endl;
  std::cout << "isLeapYear() for year 1999: " << std::boolalpha << isLeapYear(1999) << std::endl;
  std::cout << "isLeapYear() for year 2016: " << std::boolalpha << isLeapYear(2016) << std::endl;
  std::cout << "isLeapYear() for year 2020: " << std::boolalpha << isLeapYear(2020) << std::endl;
  std::cout << "isLeapYear() for year 2024: " << std::boolalpha << isLeapYear(2024) << std::endl;
  std::cout << "isLeapYear() for year 2028: " << std::boolalpha << isLeapYear(2028) << std::endl;
  std::cout << "isDayReal(2019, 04, 32) : " << std::boolalpha << isDayReal(2019, 04, 32) << std::endl;
  std::cout << "isDayReal(2019, 06, 31) : " << std::boolalpha << isDayReal(2019, 06, 31) << std::endl;
  std::cout << "isDayReal(2019, 02, 28) : " << std::boolalpha << isDayReal(2019, 02, 28) << std::endl;
  std::cout << "isDayReal(2019, 02, 29) : " << std::boolalpha << isDayReal(2019, 02, 29) << std::endl;
  std::cout << "isDayReal(2020, 02, 28) : " << std::boolalpha << isDayReal(2020, 02, 28) << std::endl;
  std::cout << "isDayReal(2020, 02, 29) : " << std::boolalpha << isDayReal(2020, 02, 29) << std::endl;
  */
  return 0;
}
