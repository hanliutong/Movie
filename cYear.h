#pragma once
#ifndef CYEAR_H
#define CYEAR_H
#include "lnkList.h"
class Year_Node {
public: float DATE;
		int ID;
		Year_Node(int date, int IDcode) {
			DATE = date;
			ID = IDcode;
		}
		Year_Node() {
			ID = -1;
			DATE = -1;
		};
};;

class cYear
{
public:
	cYear() {};
	void push(int IDcode, int Year, int date);
	void get(int Year, int* &IDcodeList);
	int  length(int Year);     //Çó±í³¤

private:
	lnkList<Year_Node> Y_2019;
	lnkList<Year_Node> Y_2018;
	lnkList<Year_Node> Y_2017;
	lnkList<Year_Node> Y_2000p;
	lnkList<Year_Node> Y_1990p;
	lnkList<Year_Node> Y_others;
	int position(lnkList<Year_Node> *Year_n, int date);

};
void cYear::push(int IDcode, int Year, int date) {
	if (Year == 2019)
		Y_2019.Insert(position(&Y_2019, date), Year_Node(date, IDcode));
	else if (Year == 2018)
		Y_2018.Insert(position(&Y_2018, date), Year_Node(date, IDcode));
	else if (Year == 2017)
		Y_2017.Insert(position(&Y_2017, date), Year_Node(date, IDcode));
	else if (Year >= 2000)
		Y_2000p.Insert(position(&Y_2000p, date), Year_Node(date, IDcode));
	else if (Year >= 1990)
		Y_1990p.Insert(position(&Y_1990p, date), Year_Node(date, IDcode));
	else
		Y_others.Insert(position(&Y_others, date), Year_Node(date, IDcode));
}

void cYear::get(int Year, int* &IDcodeList) {
	Year_Node *Year_Node_LIST = new Year_Node[100];
	if (Year == 2019)
		Y_2019.travel(Year_Node_LIST);
	else if (Year == 2018)
		Y_2018.travel(Year_Node_LIST);
	else if (Year == 2017)
		Y_2017.travel(Year_Node_LIST);
	else if (Year >= 2000)
		Y_2000p.travel(Year_Node_LIST);
	else if (Year >= 1990)
		Y_1990p.travel(Year_Node_LIST);
	else
		Y_others.travel(Year_Node_LIST);
	for (int i = 0; i < 100; i++)
	{
		if (Year_Node_LIST[i].ID == -1)
			break;
		IDcodeList[i] = Year_Node_LIST[i].ID;
	}
	delete Year_Node_LIST;

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

int cYear::position(lnkList<Year_Node> *Year_n, int date) {
	Link<Year_Node> *current = Year_n->Head();
	int pos = 1;
	while (current->next) {
		if (current->next->data.DATE < date)
			break;
		pos++;
		current = current->next;
	}
	return pos;
}
#endif//CYEAR_H