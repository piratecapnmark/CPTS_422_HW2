// Cpt S 422 HW2

#include <iostream>
#include "Stream.hpp"

using namespace CS422;

class IndexedNumberStream : public Stream
	{
	private:
		int byteSize;
		int current;
		int myVal;
		void *myStream;


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

		void Flush()
		{
			printf("Sure");
		}
		i64 GetLength() const
		{
			return byteSize;
		}
		i64 GetPosition() const
		{
			return current;
		}

		int Read(void* buf, int byteCount)
		{
			if (byteSize - current < byteCount)
			{
				printf("The stream is not large enough for you to read %d bytes\n" , byteCount);
				return 0;
			}
			else
			{
				unsigned int * temp = (unsigned int *)myStream;
				current += byteCount;
				memcpy(buf, (void *)((int)(temp + current) % 256), byteCount);
			}
			return 0;
		}

		i64 SetPosition(i64 position)
		{
			if (position < byteSize)
			{
				current = (int)position;
				return current;
			}
			else
			{
				printf("The position you are trying to set is larger than the stream size\n");
				return 0;
			}
		}

		IndexedNumberStream(int size)
		{
			byteSize = size;
		}

		
	}
}