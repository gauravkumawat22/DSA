#include<stdio.h>

void towerofhanoi(int n,char source ,char intermediate , char destination )
{
	if (n==1)
	{
		printf("Move disk 1 form %c to %c\n",source , destination);
		return;
	}
	
	towerofhanoi(n-1,source,destination,intermediate);
	printf("Move disk %d from %c to %c\n",n,source,destination);
	towerofhanoi(n-1,intermediate,source,destination);
}

int main()
{
	int n;
	printf("Enter the number of disk:");
	scanf("%d",&n);
	towerofhanoi(n,'A','B','C');
	return 0;
}