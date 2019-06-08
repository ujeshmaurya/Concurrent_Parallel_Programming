#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<math.h>
int main(int argc,char *argv[])
{
	FILE *fp;
	if(argc==1)
	{
		perror("ERROR: No filename given ");
		return 0;
	}
	else if(argc>2)
	{
		perror("ERROR: More than one filename given ");
		return 0;
	}
	else
	{
		fp=fopen(argv[1],"r");
		if(!fp)
		{
			perror("ERROR ");
			return -1;
		}
		if(fp)
		{
			perror("FILE FOUND ");
			printf("Do you want the content of file to be printed here: YES: 1\t NO: 0\n");
			int c;
			scanf("%d",&c);
			if(c==1)
			{
				char s;
				while((s=fgetc(fp))!=EOF)
					printf("%c",s);
			}
			return 0;
		}
		fclose(fp);
	}
	return 0;
}
