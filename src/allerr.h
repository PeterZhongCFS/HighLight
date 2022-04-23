//op1.0
#ifndef ALLERR_H
#define ALLERR_H
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "token.h"
void post_error(int ERRORLEVEL)
{
	switch(ERRORLEVEL)
	{
		case 0:
			break;
		case -1:
			exit(-1);
		case -2:
			while(getchar()!=10);
			break;
		default:
			exit(ERRORLEVEL);
	}
}
void range_error(const char*iclass,size_t size,int ERRORLEVEL)
{
	printf("[ERROR] range error. Class:%s Max size:%u\n",iclass,size);
	post_error(ERRORLEVEL);
}
void postErr(const char*Title,const char*Body,int model)
{
	if(model==0)
	{
		MessageBox(NULL,Body,Title,MB_ICONERROR);
		exit(0);
	}	
	printf("%s:%s\n",Title,Body);
	exit(0);
}
#endif
