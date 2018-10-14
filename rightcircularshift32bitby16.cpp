#include<stdio.h>
#include<conio.h>
int main()
{
unsigned long long int i,z=0,a=0xcccf1234;
z=(((a>>16)|(a<<(32-16))))&0xffffffff;
printf("output is %lx",z);
return 0;
getch();

}
