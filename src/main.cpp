#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lexical.h"
#include "syntaxCfree.h"
#include "syntaxDev.h"
#include "token.h"
int main(int argc,char*argv[])
{
	//SetConsoleTitle("C++ HighLight"); 
	string Input;
	string Output;
	string Name;
	int t=0,conmd=0;
	if(argc>=5)
	{
		conmd=1;
		if(strcmp(argv[1],"cfree")==0)
			t=1;
		else if(strcmp(argv[1],"devcpp")==0)
			t=0;
		else
		postErr("ERROR","style error(only devcpp or cfree)",conmd);
		strcpy(Input,argv[2]);
		strcpy(Output,argv[3]);
		strcpy(Name,argv[4]);
		goto here;
	}
	printf("Dev C++   \r");
	while(1)
	{
		int c=getch();	
		if(c==32)break;
		if(c==13)break;
		if(c==224)
		{
			c=getch();
			switch(c)
			{
				case 72:case 80:case 75:case 77:
				if(t==0)
				{
					t=1;
					printf("C Free5.0   \r");
				}else{
					t=0;
					printf("Dev C++   \r");
				}
			}
		}
	}
	printf("Input File(*.cpp):");
	gets(Input);
	printf("Output File(*.html):");
	gets(Output);
	puts(Input);
	puts(Output);
	puts("Name:");
	gets(Name);
	here:
	FILE *fi=fopen(Input,"r"),*fo=fopen(Output,"w");
	if((fi==NULL)||(fo==NULL))
		postErr("Warning","File io Failed.",conmd);
	RegistI(fi);
	RegistO(fo);
	RegistModel(t);
	if(t==1)
	system_goal_Cfree(Name);
	else
	system_goal_Dev(Name);
	return 0;
}
