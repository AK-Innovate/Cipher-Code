#include<stdio.h>
#include<conio.h>
int main()
{
unsigned int i,z=0,c=0xabcde123;
unsigned int s[16]={3,0xf,0xe,1,0,0xa,5,8,0xc,4,0xb,2,9,7,6,0xd};
scanf("%x",&c);
for(i=0;i<=64;i=i+4)
{
z|=s[((c>>(60-i))&0xf)]<<(60-i);
}
printf("output is %llx",z);
return 0;
getch();

}