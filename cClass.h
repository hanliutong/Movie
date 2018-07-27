#pragma once
#ifndef CCLASS_H
#define CCLASS_H
#include "lnkList.h"
#include "function.h"

class cClass
{
public:
	cClass() {};
	void push(int IDcode, char* Name);
	void get(char* Name, int* &IDcodeList);
	int  length(char* Name);     //Çó±í³¤
private:
	lnkList<lnkList<int>*> MainList;
	lnkList<int>* Find(int tempClass);
};

void cClass::push(int IDcode, char* Name) {
	lnkList<char*> tempList;
	char_split(Name, tempList);
	int len = tempList.length();
	if (len)
		for (int i = 0; i < len; i++)
		{
			char *tempNode = new char[32];
			tempList.getValue(i, tempNode);
			int tempClass = ELFhash(tempNode);
			int pos = 0;
			lnkList<int>* Name = Find(tempClass);
			if (Name) {
				Name->append(IDcode);
			}
			else {
				lnkList<int>* temp_lnkList = new lnkList<int>(tempClass);
				temp_lnkList->append(IDcode);
				MainList.append(temp_lnkList);
			}
		}
}

lnkList<int>* cClass::Find(int tempClass) {
	int len = MainList.length();
	lnkList<int>** tempList = new lnkList<int>*[len];
	MainList.travel(tempList);
	for (int i = 0; i < len; i++)
	{
		if (tempList[i]->getHead() == tempClass)
			return tempList[i];
	}
	return NULL;
}

void cClass::get(char* Name, int* &IDcodeList) {
	int iName = ELFhash(Name);
	lnkList<int>* cName = Find(iName);
	if (cName) {
		cName->travel(IDcodeList);
	}

}

int cClass::length(char* Name) {
	int iName = ELFhash(Name);
	lnkList<int>* cName = Find(iName);
	if (cName) {
		return cName->length();
	}
	return 0;
}

#endif//CCLASS_H
