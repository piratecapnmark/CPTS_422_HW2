// Cpt S 422 HW2

#include <iostream>
#include "Stream.hpp"
#include "MemoryStream.hpp"
using namespace CS422;

int main(int argc, const char* argv[])
{
	MemoryStream i;
	char * str = "what the fuck is this shit";
	char * str1 = "Please work";
	i.Write(str, 27);
	i.Write(str1, 12);
	char read[30];
	i.SetPosition(5);
	i.Read(read, 30);
	cout << read << endl;
	system("pause");
	
	// In other files you will implement the classes that inherit from stream.
	// Create instances of such objects as needed here (make sure you are creating 
	// each type of stream that you implemented).
	// Write Stream unit testing functions and kick off the tests from here in main.
	return 0;
}