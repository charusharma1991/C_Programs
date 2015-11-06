#include<stdio.h>
#include<stdlib.h>
int hash1(int k,int l);
int hash2(int k,int l);
void bfilter(int bloom[20],int h1,int h2,int k);
void main()
{
	int bloom[20],i,k,l=20,n,m,a[20],h1,h2,b[20];
	printf("Enter the number of terms to insert:\n");
	scanf("%d",&m);
	printf("Enter %d values to insert:\n",m);
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	for(i=0;i<l;i++)
		bloom[i]=0;
	for(i=0;i<m;i++)
	{
		k=a[i];
		h1=hash1(k,l);
		h2=hash2(k,l);
		bloom[h1]=1;
		bloom[h2]=1;
	}
	printf("Enter the number of terms to search:\n");
	scanf("%d",&n);
	printf("Enter %d values to search:\n",n); 
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(i=0;i<n;i++)
	{
		k=b[i];
		h1=hash1(k,l);
		h2=hash2(k,l);
		bfilter(bloom,h1,h2,k);
	}
}
int hash1(int k,int l)
{
	int h1;
	h1=k%l;
	return h1;
}
int hash2(int k,int l)
{
	int h2;
	h2=(k*k)%l;
	return h2;
}
void bfilter(int bloom[20],int h1,int h2,int k)
{
	if(bloom[h1]==1 && bloom[h2]==1)
		printf("Value %d may exists in the bloom filter\n",k);
	else
		printf("Value %d doesn't exist in the bloom filter\n",k);
}
