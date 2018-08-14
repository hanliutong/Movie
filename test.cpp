#include<stdio.h>
//#include"lnkList.h"
//using namespace std;
void fct(int x ){
	printf("in fct : x = %d\n",x );

}

int main(){
	int x = 10;
	printf("x = %i\n",x );
	fct(x+++5);
	printf("x = %i\n",x );
	return 0;
} 
