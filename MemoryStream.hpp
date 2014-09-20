/* BY: Jiurong Yang*/


#include "Stream.hpp"
using namespace std;
using namespace CS422;

class MemoryStream : public Stream {

	public:
		bool CanSeek()
		{
			return true;
		}
		bool CanRead()
		{
			return true;
		}
		bool CanWrite()
		{
			return true;
		}
		void Flush()
		{
			cout << "Something";
		}
		i64 GetLength() const
		{
			return streamSize;
		}
		i64 GetPosition() const
		{
			return current;
		}
		int Read(void* buf, int byteCount)
		{
			if (streamSize - current < byteCount)
			{
				cout << "The stream is not large enough for you to read " << byteCount << " bytes" << endl;
				return 0;
			}
			else
			{
				char * temp = (char *)memStream;
				memcpy(buf, (temp + current), byteCount);
			}
			return byteCount;
		}
		i64 SetPosition(i64 position)
		{
			if (position <= streamSize)
			{
				current = (int)position;
				return current;
			}
			else
			{
				cout << "The position you are trying to set is larger than the stream size" << endl;
				return 0;
			}
		}
		int Write(const void* buf, int byteCount)
		{
			int i = 0;
		    void *pointer;
			pointer = malloc(streamSize + byteCount);
			memcpy(pointer, memStream, current);
			memcpy(((char*)pointer + current), buf, byteCount);
			memcpy(((char*)pointer + current + byteCount), memStream, streamSize - current);
			//cout << (char*)pointer << endl;

			
			//for (i = 0; i < (streamSize + byteCount); i++)
			//{
				//printf("%c", *((char*)pointer + i));
			//}

			streamSize += byteCount;
			memStream = pointer;
			return byteCount;
		}
	private:
		int streamSize = 0;
		int current = 0;
	    void *memStream;
};