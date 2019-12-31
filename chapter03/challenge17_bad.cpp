// Project: chap 03 challenge 17

// > Write a program that receives the size of an array and then
// > allocates memory for it dynamically. Further, receive numbers
// > into this array and print them on screen. The program should use
// > C and C++ styles to accomplish these tasks.

// My note: the author is expecting us to use old-fashined arrays
// allocated with 'new' and pointers to access the array, and even
// malloc for the C-part (he does that in the solution). The goal was
// probably to make the students use something like myPointer++ to
// navigate through the array and *myPointer to access the array. In a
// modern-C++ perspective, it's better to use std::array and the
// initialisation is done by the constructor. Problem is, std::array
// cannot have its size set during runtime. It has to be known during
// compilation. So I did here as the author intended. Anyway, I find
// that the author's code is outdated (like the whole book in fact).

// To compile and launch, using the cygwin g++ compiler:
// g++ -std=c++14 challenge17_bad.cpp && ./a.exe

// I did not write the C-style part (malloc), it's absolutely useless.

// Output:
// Warning:
// This program is bugged (the delete produces a coredump if delete is used)
// Reason:
// Instead of using the array as if it were a pointer, I should have defined
// one old-fashined array whose memory is reserved with a new, and a pointer
// aside it to go through it. This is what the author did in its book.
// Here, I'm using the array itself, and it's a bad thing to do, hence the bug.

// Key points to remember:
// make sure to use the delete[] as it is an array allocated with new [].
// See Scott Meyers Effective C++, second edition:
// "Item 5:  Use the same form in corresponding uses of new and delete." 
// See also:
// https://stackoverflow.com/questions/1641957/is-an-array-name-a-pointer

#include <iostream>

int main()
{
  std::cout << "101 C++ challenges - chapter 03, challenge 17 bugged version" << std::endl;
  int size{0};

  std::cout << "Please enter a size for the array:" << std::endl;
  std::cin >> size;
  int* myArrayPtr = new int[size]; // declare pointer to int and allocate memory. The pointer points to this memory
  if (myArrayPtr != nullptr)
    {
      for (int i = 0; i < size; ++i)
	{
	  std::cout << "Write element number " << i << " of the array (whose size is " << size << ")" << std::endl;
	  std::cin >> myArrayPtr[i]; // access the value with the [] notation
	}
    }
  // Now we're going to display it. To browse the value we will use a different way than for the init.
  std::cout << "Thanks, the array is filled. I'm going to display it:" << std::endl;
  std::cout << "myArray = [";
  myArrayPtr = &myArrayPtr[0]; // makes the pointer points to the very first value...
  for (int i = 0; i < size; ++i)
    {
      std::cout << *myArrayPtr;
      if (i != size - 1)
	{
	  myArrayPtr++; // ... and increase the pointer so it will points to the new value in the array
	  std::cout << ", ";
	}
    }
  std::cout << "]" << std::endl;
  // coredump if these 3 lines are deleted. I should not mix the array and use it like a pointer.
  //myArrayPtr = &myArrayPtr[0];
  //delete [] myArrayPtr;
  //myArrayPtr = nullptr;
  return 0;
}

