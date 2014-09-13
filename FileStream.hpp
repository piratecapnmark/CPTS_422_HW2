/* By: Josh L. Woldstad*/


#include "Stream.hpp"
#include <fstream>
using namespace std;
using namespace CS422;

	class FileStream : public Stream
	{

	private:
		int streamsize = 0;
		int current = 0;
		bool bread = false;
		bool bwrite = false;
		fstream file;

	public:
		FileStream(string newpath, string perm)
		{
			if (perm == "r")
			{
				bread = true;
				file.open(newpath, fstream::in);
			}
			else if (perm == "w")
			{
				bwrite = true;
				file.open(newpath, fstream::out);
			}
			else if ((perm == "wr") || (perm == "rw"))
			{
				bread = true;
				bwrite = true;
				file.open(newpath, fstream::in | fstream::out);
			}
		};

		bool CanRead()
		{
			return bread;
		};

		bool CanSeek()
		{
			return false;
		};

		bool CanWrite()
		{
			return bwrite;
		};

		void Flush()
		{
			file.flush();
		};

		i64 GetLength() const
		{
			return streamsize;
		};

		i64 GetPosition() const
		{
			return current;
		};

		i64 SetPosition(i64 position)
		{
			current = position;
			return (i64)current;
		};

		int Read(void* buf, int byteCount)
		{
			if (!file)
			{
				return -1;
			}
			file.read((char *)buf, byteCount);
			return 0;
		};

		int Write(const void* buf, int byteCount)
		{
			if (!file)
			{
				return -1;
			}
			file.write((char *)buf, byteCount);
			return 0;
		};

	};

