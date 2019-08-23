#include"FileCompressHuff.h"

int main()
{
	FileCompressHuffM fc;
	fc.CompressFile("C++.pdf");

	fc.UNCompressFile("C++.hzp");
	return 0;
}
