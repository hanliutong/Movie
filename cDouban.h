#pragma once
#ifndef CBOUBAN_H
#define CBOUBAN_H
#include "lnkList.h"
#include <iostream>
class DB_Node {
public: float DB;
		int ID;
		DB_Node(float Douban, int IDcode) {
			DB = Douban;
			ID = IDcode;
		}
		DB_Node() {
			ID = -1;
			DB = -1;
		};
};
class cDouban
{
public:
	cDouban() {};
	void push(int IDcode, float Douban);
	void get(int Douban, int* &IDcodeList);
	//void get(int Douban_d, int Douban_u, int* &IDcodeList);
	int  length(int Douban);     //Çó±í³¤

private:
	lnkList<DB_Node> DB_9;
	lnkList<DB_Node> DB_8;
	lnkList<DB_Node> DB_7;
	lnkList<DB_Node> DB_6;
	lnkList<DB_Node> DB_5;
	lnkList<DB_Node> DB_4;
	lnkList<DB_Node> DB_3;
	lnkList<DB_Node> DB_2;
	lnkList<DB_Node> DB_1;
	int position(lnkList<DB_Node>* DB_n, float Douban);
};
void cDouban::push(int IDcode, float Douban) {
	if (Douban >= 9)
		DB_9.Insert(position(&DB_9, Douban), DB_Node(Douban,IDcode));
	else if (Douban >= 8) {
		DB_8.Insert(position(&DB_8, Douban), DB_Node(Douban, IDcode));
		
	}
	else if (Douban >= 7)
		DB_7.Insert(position(&DB_7, Douban), DB_Node(Douban, IDcode));
	else if (Douban >= 6)
		DB_6.Insert(position(&DB_6, Douban), DB_Node(Douban, IDcode));
	else if (Douban >= 5)
		DB_5.Insert(position(&DB_5, Douban), DB_Node(Douban, IDcode));
	else if (Douban >= 4)
		DB_4.Insert(position(&DB_4, Douban), DB_Node(Douban, IDcode));
	else if (Douban >= 3)
		DB_3.Insert(position(&DB_3, Douban), DB_Node(Douban, IDcode));
	else if (Douban >= 2)
		DB_2.Insert(position(&DB_2, Douban), DB_Node(Douban, IDcode));
	else
		DB_1.Insert(position(&DB_1, Douban), DB_Node(Douban, IDcode));

}

void cDouban::get(int Douban, int* &IDcodeList) {
	DB_Node *DB_Node_LIST = new DB_Node[100];
	if (Douban >= 9)
		DB_9.travel(DB_Node_LIST);
	else if (Douban >= 8)
		DB_8.travel(DB_Node_LIST);
	else if (Douban >= 7)
		DB_7.travel(DB_Node_LIST);
	else if (Douban >= 6)
		DB_6.travel(DB_Node_LIST);
	else if (Douban >= 5)
		DB_5.travel(DB_Node_LIST);
	else if (Douban >= 4)
		DB_4.travel(DB_Node_LIST);
	else if (Douban >= 3)
		DB_3.travel(DB_Node_LIST);
	else if (Douban >= 2)
		DB_2.travel(DB_Node_LIST);
	else
		DB_1.travel(DB_Node_LIST);
	for (int i = 0; i < 100; i++)
	{
		if (DB_Node_LIST[i].ID == -1)
			break;
		IDcodeList[i] = DB_Node_LIST[i].ID;
	}
	delete DB_Node_LIST;
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

int cDouban::position(lnkList<DB_Node> *DB_n, float Douban) {
	Link<DB_Node> *current = DB_n->Head();
	int pos = 1;
	while (current->next) {
		std::cout << "data = " << current->next->data.DB << "Douban = " << Douban << endl;
		if (current->next->data.DB < Douban)
			break;
		pos++;
		current = current->next;
	}
	std::cout << "pos = " << pos << endl;
	return pos;
}
#endif//CBOUBAN_H