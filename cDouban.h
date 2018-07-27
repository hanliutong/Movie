#pragma once
#ifndef CBOUBAN_H
#define CBOUBAN_H
#include "lnkList.h"
class cDouban
{
public:
	cDouban() {};
	void push(int IDcode, int Douban);
	void get(int Douban, int* &IDcodeList);
	//void get(int Douban_d, int Douban_u, int* &IDcodeList);
	int  length(int Douban);     //Çó±í³¤

private:
	lnkList<int> DB_9;
	lnkList<int> DB_8;
	lnkList<int> DB_7;
	lnkList<int> DB_6;
	lnkList<int> DB_5;
	lnkList<int> DB_4;
	lnkList<int> DB_3;
	lnkList<int> DB_2;
	lnkList<int> DB_1;
};
void cDouban::push(int IDcode, int Douban) {
	if (Douban >= 9)
		DB_9.append(IDcode);
	else if (Douban >= 8)
		DB_8.append(IDcode);
	else if (Douban >= 7)
		DB_7.append(IDcode);
	else if (Douban >= 6)
		DB_6.append(IDcode);
	else if (Douban >= 5)
		DB_5.append(IDcode);
	else if (Douban >= 4)
		DB_4.append(IDcode);
	else if (Douban >= 3)
		DB_3.append(IDcode);
	else if (Douban >= 2)
		DB_2.append(IDcode);
	else
		DB_1.append(IDcode);

}

void cDouban::get(int Douban, int* &IDcodeList) {
	if (Douban >= 9)
		DB_9.travel(IDcodeList);
	else if (Douban >= 8)
		DB_8.travel(IDcodeList);
	else if (Douban >= 7)
		DB_7.travel(IDcodeList);
	else if (Douban >= 6)
		DB_6.travel(IDcodeList);
	else if (Douban >= 5)
		DB_5.travel(IDcodeList);
	else if (Douban >= 4)
		DB_4.travel(IDcodeList);
	else if (Douban >= 3)
		DB_3.travel(IDcodeList);
	else if (Douban >= 2)
		DB_2.travel(IDcodeList);
	else
		DB_1.travel(IDcodeList);
}


int cDouban::length(int Douban) {
	if (Douban >= 9)
		return DB_9.length();
	else if (Douban >= 8)
		return DB_8.length();
	else if (Douban >= 7)
		return DB_7.length();
	else if (Douban >= 6)
		return DB_6.length();
	else if (Douban >= 5)
		return DB_5.length();
	else if (Douban >= 4)
		return DB_4.length();
	else if (Douban >= 3)
		return DB_3.length();
	else if (Douban >= 2)
		return DB_2.length();
	else
		return DB_1.length();
}
#endif//CBOUBAN_H