#include <stdio.h>
int main() 
{
	int a,temp,tempA,tempB;
    printf("Values of 'a' not allowed in the affine Caesar cipher:\n");

    for (a=1;a<26;a++) 
	{
        tempA=a;
        tempB=26;
        temp;
        while (tempB!= 0) 
		{
            temp=tempB;
            tempB=tempA%tempB;
            tempA=temp;
        }
        if (tempA!=1) 
            printf("%d ",a);
    }
    printf("\n");
    return 0;
}
