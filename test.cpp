#include<iostream>
//#include"lnkList.h"
using namespace std;
int ELFhash(const char *key)
{
    unsigned long h = 0;
    unsigned long g;
    while( *key )
    {
        h =( h<< 4) + *key++;
        g = h & 0xf0000000L;
        if( g ) h ^= g >> 24;
        h &= ~g;
    }
    return h%10000;
}

int main(){
	while(1){
	char temp[64];
	cin >> temp;
	cout << ELFhash(temp) <<endl;
	}
	system("pause");
	return 0;
} 
