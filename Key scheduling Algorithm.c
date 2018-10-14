unsigned int sbox(unsigned int);
unsigned int s[16] = {6,3,0xa,5,0xc,8,1,0xb,0,0xd,9,0xe,0xf,2,7,4};
int main()
{
	unsigned long int temp1=0,temp2=0;
	unsigned long long int k[2]={0x00,0x00},temp=0,m=0,i,j,p[31];
	
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

