#include<stdio.h>
#include<conio.h>
unsigned long long int p_layer(unsigned long long int b)
{
	unsigned ling long int c=0;
	for(i=0;i<64;i=i+1)
{
	c|=((b>>i)&0x01)<<p[i];
}
return(c);
}
