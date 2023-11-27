#include<stdio.h>
int main(){
	char alpha[100]="abcdefghijklmnopqrstuvwxyz",key[100]="zyxwvutsrqponmlkjihgfedcba",pt[100],ct[100];
	int i,j,m=0,index[100];
	printf("Enter plain text :");
	scanf("%s",&pt);
	for(i=0;i<strlen(pt);i++)
	{
		for(j=0;j<strlen(alpha);j++)
		{
			if(pt[i]==alpha[j])
			{
				index[m]=j;
				m++;
			}
		}
	}
	printf("Cipher text: ");
	for(i=0;i<strlen(pt);i++)
	{
		ct[i]=key[index[i]];
		printf("%c",ct[i]);
	}
	printf("\n Plain text : ");
	for(i=0;i<strlen(pt);i++)
	{
		pt[i]=alpha[index[i]];
		printf("%c",pt[i]);
	}		
}
