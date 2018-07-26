#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H
#include "lnkLIst.h"
int ELFhash(const char *key)//中文char*所用的哈希函数
{
	unsigned long h = 0;
	unsigned long g;
	while (*key)
	{
		h = (h << 4) + *key++;
		g = h & 0xf0000000L;
		if (g) h ^= g >> 24;
		h &= ~g;
	}
	return h % 10000;
}

void char_split(char Award[], lnkList<char*> &LnkList) {

	int index = 0;
	int count = 0;

	while (Award[index]) {
		char *temp = new char[64];
		while (Award[index] != '/' && (Award[index] != '\0')) {
			temp[count++] = Award[index++];

		}
		temp[count] = '\0';
		LnkList.append(temp);
		index++;
		count = 0;

	}
}
#endif//FUNCTION_H