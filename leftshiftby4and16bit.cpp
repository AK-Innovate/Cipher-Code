#include<stdio.h>
#include<conio.h>
int main()
{
unsigned int i,z=0,a=0xabcd;
z=(((a<<4)|(a>>(16-4))))&0xffff;
printf("output is %x",z);
return 0;
getch();

}
