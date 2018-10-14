
#include <stdio.h>
#include <conio.h>
unsigned long long int sbox(unsigned long long int);
unsigned long long int pbox(unsigned long long int);
unsigned int sbox(unsigned int);
unsigned int s[16] = {6,3,0xa,5,0xc,8,1,0xb,0,0xd,9,0xe,0xf,2,7,4};
int main()
{
	unsigned long int temp1=0,temp2=0;
	unsigned long long int k[2]={1111222233334444,1111111155555555},temp=0,m=0,i,j,p[31];
	
	for(j=0;j<31;j++)
	{
		
		printf("\n-----------------Round %d----------------------",j+1);
	//__________key scheduling___________________
			temp=k[1];
		k[1]= (temp<<13)|(k[0]>>(64-13));
		k[0]= (k[0]<<13)|(temp>>(64-13));
		
		//Sbox	
		m=0;	
		for(i=0; i<2; i++)
		{
			m|=(s[(k[1]>>(i*4))&0XF]<<i*4)&0xff;
		}
		k[1] &= (0Xffffffffffffff00);  
		k[1] |= ((m&0xFF));
		
		//RC xor	
		temp = (((k[1]&0XF800000000000000)>>(64-5))^(0x1f&j));
		k[1] &= 0X07FFFFFFFFFFFFFF;
		k[1] |= temp<<(64-5);
		
		p[j] = k[1];
		printf("\n Key is : %llx %llx\n",k[0],k[1]);
		//printf("\n Key is : %llx \n",p[j]);
		
	
	}
	unsigned long long int a=0x1234567890abcdef;
	 
	for(i=0;i<31;i++)
	
	{
	a=a^k[1];
    a=sbox(a);	
    a=pbox(a);
    printf("\noutput is %llx",a);
    
    }
}
unsigned int sbox(unsigned int c)
{
	unsigned int i,z=0;
	for (i=0;i<32;i=i+4)
	{
		z |= s[((c>>(28-i))&0xf)]<<(28-i);
	 } 
	 return (z);
}
unsigned long long int sbox(unsigned long long int e)
{
	unsigned long long int z=0,i;
	unsigned long long int s[16]={6,3,0xa,5,0xc,8,1,0xb,0,0xd,9,0xe,0xf,2,7,4};
	for(i=0;i<=64;i=i+4)
	{
		z|=s[(e>>(60-i))&0xf]<<(60-i);
	}

	return (z);
}
unsigned long long int pbox(unsigned long long int k )
{
	 unsigned int p[64]={0,16,32,48,1,17,33,49,2,18,34,50,3,19,35,51,4,20,36,52,5,21,37,53,6,22,38,54,7,23,39,55,8,24,40,56,9,25,41,57,10,26,42,58,11,27,43,59,12,28,44,60,13,29,45,61,14,30,46,62,15,31,47,63};
	 unsigned long long int d=0,i;
     
    for(i=0;i<64;i++)
   {
  	d|=((k>>i)&0x1)<<p[i];
  	
    }
   
  
   return(d);
}
