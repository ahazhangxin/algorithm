#pragma once
#include"HuffmanFile.hpp"
#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef unsigned char UCH;

struct CharInfo{
	CharInfo(size_t charCount = 0)
	:_charCount(charCount)
	{}

	CharInfo operator+(const CharInfo&  info)
	{
		return CharInfo(_charCount + info._charCount);
	}
	bool operator>(const CharInfo& info)
	{
		return _charCount > info._charCount;
	}
	bool operator != (const CharInfo& info)const
	{
		return _charCount != info._charCount;
	}
	bool operator == (const CharInfo& info)const
	{
		return _charCount == info._charCount;
	}

	UCH _ch;  //字符
	size_t _charCount;//当前字符出现次数
	string _strCode;//字符得编码
};


class FileCompressHuffM
{
public:
	 FileCompressHuffM();
	void CompressFile(const string& strFilePath);
	void UNCompressFile(const string& strFilePath);
	void WriteHead(FILE* fOut, const string& strFilePath); //文件头部信息
private:
	void HuffmanCode(HuffmanTreeNode<CharInfo>* proot);
	void GetLine(FILE* fIn, string& strContent); 
private:
	vector<CharInfo>_charInfo;
};