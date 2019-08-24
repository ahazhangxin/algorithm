#include "CompressFileH.h"

int main()
{
	FileCompressHuffM fc;
	fc.CompressFile("C++.pdf");

	fc.UNCompressFile("1.hzp");
	return 0;
}
