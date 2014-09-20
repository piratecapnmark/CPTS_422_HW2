
#include "Stream.hpp"
#include <iostream>
using namespace std;
using namespace CS422;




void Write_Validation_Tests(Stream & S)
{
	char s_buf[4000];
	char r_buf[4000];



	for (int i = 0; i < 4000; i++)
	{
		s_buf[i] = 'a';
	}
	s_buf[3999] = '\0';

	//cout << s_buf << endl;
	if (S.CanWrite())
	{
		cout << "Can write" << endl;
	}
	else
	{
		cout << "Can't write Unit test passed Yeyeye" << endl;

		return;
	}

	S.Write(s_buf, 4000);
	S.Read(r_buf, 4000);
	if (memcmp(r_buf, s_buf, 4000) == 0)
	{
		cout << "T1). PASS: Write all in one write works" << endl;
	}
	else
	{
		cout << "T1). FAILED: Write all in one write does not match" << endl;
	}

	char k_buf[1024];
	char o_buf[1801];
	for (int i = 0; i < 4000; i++)
	{
		s_buf[i] = 'b';
	}
	s_buf[3999] = '\0';
	S.SetPosition(S.GetLength());

	int k = 4000;
	for (int i = 0; i <= 3; i++)
	{
		int l;
		if ((k - 1024) >= 0)
		{
			l = 1024;
			k = k - 1024;
		}
		else
		{
			l = k;
		}
		for (int j = 0; j <= l; j++)
		{
			k_buf[j] = s_buf[i * 1024 + j];
		}
		S.Write(k_buf, l);
		S.SetPosition(S.GetLength());
	}
	S.Read(r_buf, 4000);

	if (memcmp(r_buf, s_buf, 4000) == 0)
	{
		cout << "T1). PASS: Write by block works" << endl;
	}
	else
	{
		cout << "T1). FAILED: Write all in one write does not match" << endl;
	}





	system("pause");
	return;
}



