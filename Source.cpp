// Cpt S 422 HW2

#include <iostream>
#include "Stream.hpp"
#include "MemoryStream.hpp"
#include "FileStream.hpp"
#include "IndexedNumberStream.hpp"
using namespace CS422;

int main(int argc, const char* argv[])
{
	// In other files you will implement the classes that inherit from stream.
	// Create instances of such objects as needed here (make sure you are creating 
	// each type of stream that you implemented).
	// Write Stream unit testing functions and kick off the tests from here in main.
	MemoryStream i;
	FileStream f("test.txt", "rw");
	IndexedNumberStream ins(56);

	//This section is for testing MemoryStream 
	char *str = "hello";
	char *str1 = "world";
	i.Write(str, 6);
	i.Write(str1, 6);
	char read[30];
	i.SetPosition(5);
	i.Read(read, 7);
	for (int i = 0; i < 7; i++)
	{
	printf("%c", *((char*)read + i));
	}
	cout << endl;
	//End of MemStream

	system("pause");
	return 0;
}