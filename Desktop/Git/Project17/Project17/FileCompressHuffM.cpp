#define _CRT_SECURE_NO_WARNINGS
#include"CompressFileH.h"
#include"HuffmanFile.hpp"
#include<vector>
#include<assert.h>

using namespace std;

FileCompressHuffM::FileCompressHuffM()
{
	_charInfo.resize(256); //申请空间
	for (size_t i = 0; i < 256; ++i)
		_charInfo[i]._ch = i;
}

void FileCompressHuffM::CompressFile(const string& strFilePath){
	//1.获取源文件中每个字符出现的次数
	FILE* fIn = fopen(strFilePath.c_str(), "rb");
	if (fIn == nullptr)
	{
		cout << "failed" << endl;
		return;
	}
	UCH* pReadBuff = new UCH[1024];

	while (1)
	{
		size_t rdsize = fread(pReadBuff, 1, 1024, fIn);
		if (0 == rdsize)
		{
			break;
		}
		for (size_t i = 0; i < rdsize; ++i){
			_charInfo[pReadBuff[i]]._charCount++;
		}
	}
	//2.以每个字符出现的的次数为权值创建Huffman树
	HuffmanTree<CharInfo> ht;
	ht.CreateHuffmanTree(_charInfo,CharInfo(0));
	
	//3.根据Huffman树获取每个字符得编码
	HuffmanCode(ht.GetRoot());

	//4.根据每个字符得编码重写改写源文件
	FILE* fOut = fopen("1.hzp","w");
	assert(fOut);
	WriteHead(fOut, strFilePath);
	char ch = 0;
	size_t bitCount = 0;
	fseek(fIn, 0, SEEK_SET);   
	while (true)
	{
		size_t rdsize = fread(pReadBuff, 1, 1024, fIn);
		if (rdsize == 0)
			break;
		for (size_t i = 0; i < rdsize; ++i)
		{
			string& strCode = _charInfo[pReadBuff[i]]._strCode;
			for (size_t j = 0; j < strCode.size(); ++j)
			{
				ch <<= 1;//向左移1位
				if (strCode[j] == '1')
					ch |= 1;
				bitCount++;
				if (bitCount == 8)
				{
					fputc(ch, fOut);
					bitCount = 0;
				}	
			}
		}
	}	
	if (bitCount < 8&& bitCount>0)
	{
		ch <<= (8 - bitCount); //手动填充到8个字节
			fputc(ch, fOut);
	}
	delete[] pReadBuff;
	fclose(fIn);
	fclose(fOut);
}

void  FileCompressHuffM::UNCompressFile(const string& strFilePath)
{
	//检测压缩文件得后缀格式
	string strPostFix = strFilePath.substr(strFilePath.rfind('.'));
	if (".hzp" != strPostFix)
	{
		cout << "压缩格式有问题" << endl;
		return;
	}
	//获取解压缩信息
	FILE* fIn = fopen(strFilePath.c_str(), "rb");
	if (fIn == nullptr)
	{
		cout << "压缩文件打开失败" << endl;
		return;
	}
	//获取文件后缀
	strPostFix = " ";
	GetLine(fIn, strPostFix);
	//获取行数
	string strContent;
	GetLine(fIn, strContent);
	size_t lineCount = atoi(strContent.c_str());

	//字符信息
	for (size_t i = 0; i < lineCount; ++i)
	{
		strContent = " ";
		GetLine(fIn, strContent);
		if (strContent.empty())
		{
			strContent += "\n";
			GetLine(fIn, strContent);
		}
		_charInfo[(UCH)strContent[0]]._charCount = atoi(strContent.c_str()+2);
	}
	//创建Huffman树
	HuffmanTree<CharInfo> ht;
	ht.CreateHuffmanTree(_charInfo, CharInfo(0));

	//解压缩
	string strUNCompFile = "2";
	strUNCompFile += strPostFix;
	FILE* fOut = fopen(strUNCompFile.c_str(), "w");
	assert(fOut);
	char* pReadBuff = new char[1024];
	char pos = 7; 
	HuffmanTreeNode<CharInfo>* pCur = ht.GetRoot();
	size_t fileSize = pCur->_weight._charCount;  //文件字符大小
	while (true)
	{
		pos = 7;
		size_t rdsize = fread(pReadBuff, 1, 1024, fOut);
		if (0 == rdsize)
		{
			break;
		}
		for (size_t i = 0; i < rdsize; ++i)
		{
			for (size_t j = 0; j < 8; ++j)
			{
				if (pReadBuff[i] & (1 << pos)) //让1向左移动七位，检测最高位是否为1
					pCur=pCur->_pRight;
				else
					pCur = pCur->_pLeft;
				if (nullptr == pCur->_pLeft&&nullptr == pCur->_pRight)
				{
					fputc(pCur->_weight._ch, fOut);
					pCur = ht.GetRoot();
					fileSize--;
					if (fileSize == 0)
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

void FileCompressHuffM::HuffmanCode(HuffmanTreeNode<CharInfo>* proot)
{
	if (proot==nullptr)
	{
		return;
	}
	HuffmanCode(proot->_pLeft);
	HuffmanCode(proot->_pRight);
	if (proot->_pLeft == nullptr && proot->_pRight == nullptr)
	{
		HuffmanTreeNode<CharInfo>* pCur = proot;
		HuffmanTreeNode<CharInfo>* pParent = pCur->_pParent;
		string& strCode = _charInfo[pCur->_weight._ch]._strCode;
		while (pParent)
		{

			if (pCur == pParent->_pLeft)
				strCode += "0";
			else
				strCode += "1";
			pCur = pParent;
			pParent = pCur->_pParent;
		}
		reverse(strCode.begin(), strCode.end());//将编码逆置
	}
		
}
void FileCompressHuffM::WriteHead(FILE* fOut, const string& strFilePath)
{
	string strHeadInfo; 
	strHeadInfo = strFilePath.substr(strFilePath.rfind('.'));//从后面截取文件后缀
	strHeadInfo += '\n';
	string strCharInfo;
	char szCount[32];
	size_t lineCount = 0;
	for (size_t i = 0; i < 256; ++i)
	{
		if (_charInfo[i]._charCount)
		{
			strCharInfo += _charInfo[i]._charCount;
			strCharInfo += ',';
			_itoa(_charInfo[i]._charCount, szCount, 10);
			strCharInfo += szCount;
			strCharInfo += '\n';	//插入每个字符出现次数
			lineCount++;
		}
	}
	_itoa(lineCount, szCount, 10); //插入行数
	strHeadInfo += szCount;
	strHeadInfo += '\n';
	strHeadInfo += strCharInfo;
	fwrite(strHeadInfo.c_str(), 1,strHeadInfo.size(),fOut );
}

void FileCompressHuffM::GetLine(FILE* fIn, string& strContent) //获取每行信息
{
	while (!feof(fIn))
	{
		char ch = fgetc(fIn);
		if (ch == '\n')
		{
			return;
		}
		strContent += ch;
	}
}