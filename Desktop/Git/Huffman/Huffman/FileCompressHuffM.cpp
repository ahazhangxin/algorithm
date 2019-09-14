#include "FileCompressHuff.h"
#include <iostream>
#include <assert.h>
using namespace std;


FileCompressHuffM::FileCompressHuffM()
{
	_charInfo.resize(256);
	for (size_t i = 0; i < 256; ++i)
		_charInfo[i]._ch = i;
}

void FileCompressHuffM::CompressFile(const std::string& strFilePath)
{
	// 1. 获取源文件中每个字符出现的次数
	FILE* fIn = fopen(strFilePath.c_str(), "rb");
	if (nullptr == fIn)
	{
		cout << "文件打开失败" << endl;
		return;
	}

	UCH* pReadBuff = new UCH[1024];
	while (1)
	{
		size_t rdSize = fread(pReadBuff, 1, 1024, fIn);
		if (0 == rdSize)
			break;

		for (size_t i = 0; i < rdSize; ++i)
		{
			_charInfo[pReadBuff[i]]._charCount++;
		}
	}

	// 2. 以每个字符出现的次数为权值创建huffman树
	HuffmanTree<CharInfo> ht;
	ht.CreatHuffmanTree(_charInfo, CharInfo(0));

	// 3. 根据huffman树获取每个字符的编码
	GetHuffmanCode(ht.GetRoot());

	// 4. 根据每个字符的编码重写改写源文件
	FILE* fOut = fopen("1.hzp", "wb");
	assert(fOut);

	WriteHead(fOut, strFilePath);

	char ch = 0;
	char bitCount = 0;
	fseek(fIn, 0, SEEK_SET);

	while (true)
	{
		size_t rdSize = fread(pReadBuff, 1, 1024, fIn);
		if (0 == rdSize)
			break;

		for (size_t i = 0; i < rdSize; ++i)
		{
			string& strCode = _charInfo[pReadBuff[i]]._strCode;

			// ch: 0000 0001
			// A:100
			for (size_t j = 0; j < strCode.size(); ++j)
			{
				ch <<= 1;
				if ('1' == strCode[j])
					ch |= 1;

				bitCount++;
				if (8 == bitCount)
				{
					fputc(ch, fOut);
					bitCount = 0;
				}
			}
		}
	}

	if (bitCount > 0 && bitCount < 8)
	{
		ch <<= (8 - bitCount);
		fputc(ch, fOut);
	}

	delete[] pReadBuff;
	fclose(fIn);
	fclose(fOut);
}

void FileCompressHuffM::UNCompressFile(const std::string& strFilePath)
{
	// 检测压缩文件的后缀格式
	string strPostFix = strFilePath.substr(strFilePath.rfind('.'));
	if (".hzp" != strPostFix)
	{
		cout << "压缩文件的格式有问题" << endl;
		return;
	}

	// 获取解压缩的信息
	FILE* fIn = fopen(strFilePath.c_str(), "rb");
	if (nullptr == fIn)
	{
		cout << "压缩文件打开失败" << endl;
		return;
	}

	// 获取源文件的后缀
	strPostFix = "";
	GetLine(fIn, strPostFix);

	// 总行数
	string strContent;
	GetLine(fIn, strContent);
	size_t lineCount = atoi(strContent.c_str());

	// 字符信息
	for (size_t i = 0; i < lineCount; ++i)
	{
		strContent = "";
		GetLine(fIn, strContent);
		if (strContent.empty())
		{
			strContent += '\n';
			GetLine(fIn, strContent);
		}

		_charInfo[(UCH)strContent[0]]._charCount = atoi(strContent.c_str() + 2);
	}

	// 创建huffman树
	HuffmanTree<CharInfo> ht;
	ht.CreatHuffmanTree(_charInfo, CharInfo(0));

	// 解压缩
	string strUNComFile = "2";
	strUNComFile += strPostFix;
	FILE* fOut = fopen(strUNComFile.c_str(), "wb");
	assert(fOut);
	char* pReadBuff = new char[1024];
	HuffmanTreeNode<CharInfo>* pCur = ht.GetRoot();
	char pos = 7;
	ULL fileSize = pCur->_weight._charCount;

	while (true)
	{
		size_t rdSize = fread(pReadBuff, 1, 1024, fIn);
		if (0 == rdSize)
			break;

		for (size_t i = 0; i < rdSize; ++i)
		{
			pos = 7;
			for (size_t j = 0; j < 8; ++j)
			{
				// 1001 0110
				// 1000 0000
				if (pReadBuff[i] & (1 << pos))
					pCur = pCur->_pRight;
				else
					pCur = pCur->_pLeft;

				if (nullptr == pCur->_pLeft && nullptr == pCur->_pRight)
				{
					fputc(pCur->_weight._ch, fOut);
					pCur = ht.GetRoot();

					fileSize--;
					if (0 == fileSize)
						break;
				}

				pos--;
			}
		}
	}

	delete[] pReadBuff;
	fclose(fIn);
	fclose(fOut);
}

void FileCompressHuffM::GetHuffmanCode(HuffmanTreeNode<CharInfo>* pRoot)
{
	if (nullptr == pRoot)
		return;

	GetHuffmanCode(pRoot->_pLeft);
	GetHuffmanCode(pRoot->_pRight);

	if (nullptr == pRoot->_pLeft && nullptr == pRoot->_pRight)
	{
		HuffmanTreeNode<CharInfo>* pCur = pRoot;
		HuffmanTreeNode<CharInfo>* pParent = pCur->_pParent;

		string& strCode = _charInfo[pCur->_weight._ch]._strCode;
		while (pParent)
		{
			if (pCur == pParent->_pLeft)
				strCode += '0';
			else
				strCode += '1';

			pCur = pParent;
			pParent = pCur->_pParent;
		}

		reverse(strCode.begin(), strCode.end());
	}
}

void FileCompressHuffM::WriteHead(FILE* fOut, const std::string& strFilePath)
{
	string strHeadInfo;
	strHeadInfo = strFilePath.substr(strFilePath.rfind('.'));
	strHeadInfo += '\n';

	string strCharInfo;
	char szCount[32];
	size_t lineCount = 0;
	for (size_t i = 0; i < 256; ++i)
	{
		if (_charInfo[i]._charCount)
		{
			strCharInfo += _charInfo[i]._ch;
			strCharInfo += ',';
			_itoa(_charInfo[i]._charCount, szCount, 10);
			strCharInfo += szCount;
			strCharInfo += '\n';
			lineCount++;
		}
	}

	_itoa(lineCount, szCount, 10);
	strHeadInfo += szCount;
	strHeadInfo += '\n';

	strHeadInfo += strCharInfo;
	fwrite(strHeadInfo.c_str(), 1, strHeadInfo.size(), fOut);
}

void FileCompressHuffM::GetLine(FILE* fIn, std::string& strContent)
{
	while (!feof(fIn))
	{
		char ch = fgetc(fIn);
		if ('\n' == ch)
			return;

		strContent += ch;
	}
}