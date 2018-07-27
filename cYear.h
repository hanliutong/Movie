#pragma once
#ifndef CYEAR_H
#define CYEAR_H
#include "lnkList.h"
class cYear
{
public:
	cYear() {};
	void push(int IDcode, int Year);
	void get(int Year, int* &IDcodeList);
	int  length(int Year);     //Çó±í³¤

private:
	lnkList<int> Y_2019;
	lnkList<int> Y_2018;
	lnkList<int> Y_2017;
	lnkList<int> Y_2000p;
	lnkList<int> Y_1990p;
	lnkList<int> Y_others;

};
void cYear::push(int IDcode, int Year) {
	if (Year == 2019)
		Y_2019.append(IDcode);
	else if (Year == 2018)
		Y_2018.append(IDcode);
	else if (Year == 2017)
		Y_2017.append(IDcode);
	else if (Year >= 2000)
		Y_2000p.append(IDcode);
	else if (Year >= 1990)
		Y_1990p.append(IDcode);
	else
		Y_others.append(IDcode);
}

void cYear::get(int Year, int* &IDcodeList) {
	if (Year == 2019)
		Y_2019.travel(IDcodeList);
	else if (Year == 2018)
		Y_2018.travel(IDcodeList);
	else if (Year == 2017)
		Y_2017.travel(IDcodeList);
	else if (Year >= 2000)
		Y_2000p.travel(IDcodeList);
	else if (Year >= 1990)
		Y_1990p.travel(IDcodeList);
	else
		Y_others.travel(IDcodeList);
}

int cYear::length(int Year) {
	if (Year == 2019)
		return Y_2019.length();
	else if (Year == 2018)
		return Y_2018.length();
	else if (Year == 2017)
		return Y_2017.length();
	else if (Year >= 2000)
		return Y_2000p.length();
	else if (Year >= 1990)
		return Y_1990p.length();
	else
		return Y_others.length();
}
#endif//CYEAR_H