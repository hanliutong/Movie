#pragma once
#ifndef DS_LINK_H
#define DS_LINK_H
#include <iostream>
using namespace std;

template <class T>      //��㶨�塢2�����캯��
class Link {             //���Link
public:
	T   data;   //������
	Link<T> *next;  //ָ����������������

	Link(T info, Link<T> *nextValue = NULL) {
		data = info;
		next = nextValue;
	}

	Link(Link<T> *nextValue) {
		next = nextValue;
	}
	Link() {
		next = NULL;
	}

};
#endif //DS_LINK_H

// UTF-8
// Created by Hanliutong on 2018/3/21.
// All rights reserved
