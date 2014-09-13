// Cpt S 422 HW2

#include <iostream>
#include "Stream.hpp"

using namespace CS422;

class IndexedNumberStream : public Stream
	{
	private:
		int myVal;
		unsigned int mySize;


	public:
		bool CanRead()
		{
			return true;
		}

		bool CanWrite()
		{
			return false;
		}

		bool CanSeek()
		{
			return false;
		}

		IndexedNumberStream(unsigned int size)
		{
			mySize = size;
		}


	}
}