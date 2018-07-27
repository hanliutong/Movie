//��ͷ�ڵ�
#pragma once
#ifndef DS_LNKLIST_H
#define DS_LNKLIST_H

#include "Link.h"
//#include <iostream>
//using namespace std;
template <class T>
class lnkList {
private:  Link<T> *head, *tail;//ͷָ���βָ��
		  Link<T> *setPos(const int p); //�ҵ�p�����
public: lnkList();     //���캯��
		lnkList(T value);		//����ͷ�ڵ�Ĺ��캯��
		~lnkList();     //��������
		bool  isEmpty();   //�п�
		void  clear();     //���
		int  length();     //���
		bool  append(T value); //׷��ֵΪvalue��Ԫ��
		bool  Insert(const int p, const T value);   //����
		bool  del(const int p);         //ɾ��
		bool  getValue(int p, T& value);
		bool  getPos(int &p, T value);
		void  travel();
		void  travel(T* &List);
		void  travel_p(T  **List);
		T getHead();
};

template <class T>
void  lnkList<T>::travel(T* &List) {
	Link<T> *current = head->next;
	int temp_index = 0;
	while (current)
	{
		List[temp_index] = current->data;
		temp_index++;
		current = current->next;
	}
}
template <class T>
void  lnkList<T>::travel_p(T** List){
	Link<T> *current = head->next;
	int temp_index = 0;
	while (current)
	{
		List[temp_index] = &(current->data);
		temp_index++;
		current = current->next;
	}
}

template <class T>
lnkList<T>::lnkList() {    //���캯��
						   // Link<T>* p;
	head = tail = new Link<T>;
}

template <class T>
lnkList<T>::~lnkList() {     //��������
	Link<T> *tmp;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

template <class T>
lnkList<T>::lnkList(T value) {    //����ͷ�ڵ�Ĺ��캯��
						   // Link<T>* p;
	head = tail = new Link<T>(value,NULL);
}

template<class T>
Link<T>* lnkList<T> ::setPos(int i) {
	int count = 0;
	if (i <= -1) return head; //����ͷ���ָ��
	Link<T> *p = head->next;  //pָ���һ�����ݽ��
	while (p != NULL && count < i) {      //T(n)=O(n)
		p = p->next;
		count++;
	}
	return p;
}//p��ָ���/����

template<class T>  // �����½��(ֵΪvalue)Ϊ��i�����
bool lnkList<T> ::Insert(const int i, const T value) {
	Link<T> *p, *q;
	if ((p = setPos(i - 1)) == NULL) { //ѭ��O(n)�ҵ�i-1�����
		//cout << "�Ƿ������" << endl;      
		return false;
	}
	q = new Link<T>(value, p->next);  //�����½��q,�����
	p->next = q;       //��i-1�����p�ĺ��Ϊq
	if (p == tail)    tail = q;//������׷��,q����β
	return true;
}

template<class T>       //ɾ���ɲ���i��ָ���Ľ��
bool lnkList<T> ::del(const int i) {
	Link<T>     *p, *q;
	if ((p = setPos(i - 1)) == NULL || p == tail) { //��λO(n)
		//cout << "�Ƿ�ɾ����" << endl; //��[i-1]���[i]��Ϊ��
		return false;
	}
	q = p->next;        //qָ��ɾ��; pָ��q��ǰ��
	p->next = q->next;
	if (q == tail) tail = p;
	delete q;

	return true;
}

template<class T>  //
bool lnkList<T> ::isEmpty() {
	if (head == tail)//ͷָ��=βָ��
	{
		return true;
	}
	return false;
}

template<class T>
void lnkList<T> ::clear() {
	tail = head;
}

template<class T>
int lnkList<T> ::length() {
	if (head == tail)
	{
		return 0;
	}
	int count = 0;
	Link<T> *p = head->next;
	while (p != NULL) {
		p = p->next;
		count++;
	}
	return count;
}
template<class T>
bool lnkList<T> ::append(T value) {
	Link<T> * q;
	q = new Link<T>(value, NULL);
	tail->next = q;
	tail = q;

	return 1;
}

template<class T>
bool lnkList<T> ::getValue(int p, T& value) {
	int count = 0;
	Link<T> *l = head->next;
	while (l != NULL) {
		l = l->next;
		count++;
	}
	if (p < 0 || p >(count - 1))
	{
		//cout << "illgeal 'p':";
		return 0;
	}
	Link<T> *point = setPos(p);
	value = point->data;

	return 1;

}
template<class T>
bool lnkList<T> ::getPos(int &p, T value) {
	Link<T> *current = head->next;
	int index = 0; // current������
	while (current && current->data != value)
	{
		current = current->next;
		++index;
	}
	if (current)
	{
		p = index;
		return 1;
	}
	p = -1;
	return 0;
}

template <class T>
void lnkList<T> ::travel() {
	Link<T> *current = head->next;
	while (current)
	{
		cout << current->data << "\t";
		current = current->next;
	}
	cout << endl;
}
template <class T>
T lnkList<T> ::getHead() {
	return head->data;
}

#endif //DS_LNKLIST_H

// UTF-8
// Created by Hanliutong on 2018/3/21.
// All rights reserved

// int main()
// {   
//     //��ģ��:����(lnkList)�Ĳ��Գ���
//     int x = 2;
//     lnkList<int> link_1;
//     link_1.append(1);
//     link_1.Insert(1,2);
//     link_1.append(3);
//     link_1.Insert(3,4);
//     link_1.append(5);
//     cout << "length = "<< link_1.length() << endl;
//     link_1.del(1);
//     cout << "1:p = "<< link_1.getPos(x,1) << x << endl
//          << "2:p = "<< link_1.getPos(x,2) << x << endl
//          << "5:p = "<< link_1.getPos(x,5) << x << endl;
//     cout << "'0' :" << link_1.getValue(0,x) << x << endl;
//     cout << "'1' : "<< link_1.getValue(1,x) << x << endl;
//     cout << "'2' : "<< link_1.getValue(2,x) << x << endl;
//     cout << "'4' : "<< link_1.getValue(4,x) << x << endl;
//     cout << "length = "<< link_1.length() << endl;
//     cout << "isEmpty = "<< link_1.isEmpty() << endl;
//     cout << "link_1 : ";
//     link_1.travle();


//     return 0;
// }