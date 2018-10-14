#include<stdio.h>
#include<conio.h>
unsigned long long int p_layer(unsigned long long int b);
int main()
{
unsigned long long int x,m,z=0,c=0x1234567890abcdef;
int i;
unsigned int s[16]={6,3,0xa,5,0xc,8,1,0xb,0xd,9,0xe,0xf,2,7,4};
unsigned long long int p[64]={0,16,32,48,1,17,33,49,2,18,34,50,3,19,35,51,4,20,36,52,5,21,37,53,6,22,38,54,7,23,39,55,8,24,40,56,9,25,41,57,10,26,42,58,11,27,43,59,12,28,44,60,13,29,45,61,14,30,46,62,15,31,47,63};
x=p_layer(c);
printf("%x",x);

for(i=0;i<=64;i=i+4)
{
z|=s[((c>>(60-i))&0xf)]<<(60-i);
}
printf("%llx",z);
for(i=0;i<64;i=i+1)
{
	m|=((z>>i)&0x01)<<p[i];
}
printf("output is %llx",m);
return 0;
getch();

}
