// Cpt S 422 HW2

#include <iostream>
#include "Stream.hpp"
#include "MemoryStream.hpp"
#include "FileStream.hpp"
#include "IndexedNumberStream.hpp"
using namespace CS422;



void Write_Validation_Tests(Stream & S)
{
	char s_buf[10000];
	char r_buf[10000];



	for (int i = 0; i < 10000; i++)
	{
		s_buf[i] = 'a';
	}
	cout << s_buf << endl;
	if (S.CanWrite())
	{
		cout << "Can write" << endl;
	}
	else
	{
		cout << "Can't write Unit test passed Yeyeye" << endl;

		return;
	}

	S.Write(s_buf, 10000);
	S.Read(r_buf, 10000);
	if (memcmp(r_buf, s_buf, 10000))
	{
		cout << "T1). PASS: Write all in one write works" << endl;
	}
	else
	{
		cout << "T1). FAILED: Write all in one write does not match" << endl;
	}

	char k_buf[1024];
	char o_buf[1801];
	for (int i = 0; i < 10000 / 1024; i++)
	{
		for (int j = 0; j < 1024; j++)
		{
			k_buf[j] = s_buf[i * 1024 + j];
		}
		
	}

	//This section is for testing MemoryStream 
	//char *str = "hello";
	//char *str1 = "world";
	//i.Write(str, 6);
	//i.Write(str1, 6);
	//char read[30];
	//i.SetPosition(5);
	//i.Read(read, 7);
	//for (int i = 0; i < 7; i++)
	//{
	//	printf("%c", *((char*)read + i));
	//}
	//cout << endl;

	//End of MemStream

	system("pause");
	return;
}






int main(int argc, const char* argv[])
{
	MemoryStream i;
	FileStream f("test.txt", "w");

	Write_Validation_Tests(i);
	return 0;
}
