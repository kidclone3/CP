#include<stdio.h>
#include<string.h>
int main(){
	char a[18],b[20];
	scanf("%s",&a);
	for (int i = 0,j=0; i < strlen(a); i++)
	{
		if(a[i]=='5'||a[i]=='2'||a[i]=='3'||a[i]=='7'){
			b[j]=a[i];j++;
		}
	}
	for (int i = 0; i < strlen(b); i++)
	{
		int dem=0;
		for (int j = 0; j < strlen(a); j++)
		{
			if(b[i]==a[j]) dem++;
		}
		printf("%d ",b[i]-'0');
		printf("%d\n",dem);
	}
	
}