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
	int  length(char* Nation);     //���
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
			case 4154://�й�
			case 2493: China.append(IDcode);//�й���½
				break;
			case 5002: America.append(IDcode);//����
				break;
			case 7950: Europe.append(IDcode);//ŷ��
				break;
			case 6123://�й����
			case 1333://�й�����
			case 7125://�й�̨��
			case 5192: TW_HK_MC.append(IDcode);//�۰�̨
				break;
			case 8094://�ձ�
			case 6506://����
			case 8475:  JP_SK.append(IDcode);//�պ�
				break;
			case 2475://����
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
	case 4154://�й�
	case 2493: China.travel(IDcodeList);//�й���½
		break;
	case 5002: America.travel(IDcodeList);//����
		break;
	case 7950: Europe.travel(IDcodeList);//ŷ��
		break;
	case 6123://�й����
	case 1333://�й�����
	case 7125://�й�̨��
	case 5192: TW_HK_MC.travel(IDcodeList);//�۰�̨
		break;
	case 8094://�ձ�
	case 6506://����
	case 8475:  JP_SK.travel(IDcodeList);//�պ�
		break;
	case 2475://����
	default:	Others.travel(IDcodeList);
		break;
	}
}

int cNation::length(char* Nation) {
	int iNation = ELFhash(Nation);
	switch (iNation)
	{
	case 4154://�й�
	case 2493: return China.length();//�й���½
		break;
	case 5002: return America.length();//����
		break;
	case 7950: return Europe.length();//ŷ��
		break;
	case 6123://�й����
	case 1333://�й�����
	case 7125://�й�̨��
	case 5192: return TW_HK_MC.length();//�۰�̨
		break;
	case 8094://�ձ�
	case 6506://����
	case 8475:  return JP_SK.length();//�պ�
		break;
	case 2475://����
	default:	return Others.length();
		break;
	}
}
#endif//CNATION_H