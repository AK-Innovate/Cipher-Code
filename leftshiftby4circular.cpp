#include<stdio.h>
#include<conio.h>
int main()
{
unsigned int i,z=0,a=0xab;
z=(((a<<4)|(a>>(8-4))))&0xff;
printf("output is %x",z);
return 0;
getch();

}
