#pragma once
#ifndef CNATION_H
#define CNATION_H
#include "lnkList.h"
#include"function.h"
class cNation
{
private:
	lnkList<int> China;
	lnkList<int> America;
	lnkList<int> Europe;
	lnkList<int> TW_HK_MC;
	lnkList<int> JP_SK;
	lnkList<int> Others;
public:
	cNation() {};
	void push(int IDcode, char* Nation);
	void get(char* Nation, int* &IDcodeList);
	int  length(char* Nation);     //求表长
};

void cNation::push(int IDcode, char* Nation) {
	lnkList<char*> tempList;
	char_split(Nation, tempList);
	int len = tempList.length();
	if (len)
		for (int i = 0; i < len; i++)
		{
			char *tempNode = new char[32];
			tempList.getValue(i, tempNode);
			int tempType = ELFhash(tempNode);
			switch (tempType)
			{
			case 4154://中国
			case 2493: China.append(IDcode);//中国大陆
				break;
			case 5002: America.append(IDcode);//美国
				break;
			case 7950: Europe.append(IDcode);//欧洲
				break;
			case 6123://中国香港
			case 1333://中国澳门
			case 7125://中国台湾
			case 5192: TW_HK_MC.append(IDcode);//港澳台
				break;
			case 8094://日本
			case 6506://韩国
			case 8475:  JP_SK.append(IDcode);//日韩
				break;
			case 2475://其他
			default:	Others.append(IDcode);
				break;
			}
			delete tempNode;
		}
}


void cNation::get(char* Nation, int* &IDcodeList) {
	int iNation = ELFhash(Nation);
	switch (iNation)
	{
	case 4154://中国
	case 2493: China.travel(IDcodeList);//中国大陆
		break;
	case 5002: America.travel(IDcodeList);//美国
		break;
	case 7950: Europe.travel(IDcodeList);//欧洲
		break;
	case 6123://中国香港
	case 1333://中国澳门
	case 7125://中国台湾
	case 5192: TW_HK_MC.travel(IDcodeList);//港澳台
		break;
	case 8094://日本
	case 6506://韩国
	case 8475:  JP_SK.travel(IDcodeList);//日韩
		break;
	case 2475://其他
	default:	Others.travel(IDcodeList);
		break;
	}
}

int cNation::length(char* Nation) {
	int iNation = ELFhash(Nation);
	switch (iNation)
	{
	case 4154://中国
	case 2493: return China.length();//中国大陆
		break;
	case 5002: return America.length();//美国
		break;
	case 7950: return Europe.length();//欧洲
		break;
	case 6123://中国香港
	case 1333://中国澳门
	case 7125://中国台湾
	case 5192: return TW_HK_MC.length();//港澳台
		break;
	case 8094://日本
	case 6506://韩国
	case 8475:  return JP_SK.length();//日韩
		break;
	case 2475://其他
	default:	return Others.length();
		break;
	}
}
#endif//CNATION_H