#include<stdio.h>
#include<conio.h>
int main()
{
unsigned int i,z=0,c=0xe;
unsigned int s[16]={3,0xf,0xe,1,0,0xa,5,8,0xc,4,0xb,2,9,7,6,0xd};
unsigned int p[8]={2,3,0,1};
for(i=0;i<=3;i=i+1)
{
	z|=((c>>i)&0x01)<<p[i];
}
printf("%x",z);
getch();
}
