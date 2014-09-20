// Cpt S 422 HW2

#include <iostream>
#include "Stream.hpp"
#include "MemoryStream.hpp"
#include "FileStream.hpp"
#include "IndexedNumberStream.hpp"
#include "ConsistencyTests.hpp"
#include "WriteTests.hpp"
using namespace CS422;






int main(int argc, const char* argv[])
{
	MemoryStream i;
	FileStream f("test.txt", "w");
	consistencyTesting(i);
	//Write_Validation_Tests(i);
	return 0;
}
