//op1.0
#ifndef BUFFER_H
#define BUFFER_H
#include <string.h>
#include "token.h"
#include "allerr.h"
string buffer;
int buff_tot;
void clear_buffer()
{
	buff_tot=0;
	memset(buffer,0,33);
	return;
}
void push_buffer(int c)
{
	if(buff_tot==1024)range_error("buffer",33,-2);
	buffer[buff_tot++]=c;
}
int GetNumber()
{
	int n=0;
	char*p=buffer;
	while(*p!=0)
	{
		n=(n<<3)+(n<<1)+*p-0x30;
		p++;
	}
	return n;
}
token check_keywordC()
{
	int i;
	for(i=0;KeywordsC[i][0]!='#';i++)
	{
		if(strcmp(buffer,KeywordsC[i])==0)
			return KEYWORD;
	}
	for(i=0;TypeWordsC[i][0]!='#';i++)
	{
		if(strcmp(buffer,TypeWordsC[i])==0)
			return TYPEINC;
	}
	return ID;
}
token check_keywordD()
{
	int i;
	for(i=0;KeywordsD[i][0]!='#';i++)
	{
		if(strcmp(buffer,KeywordsD[i])==0)
			return KEYWORD;
	}
	return ID;
}
#endif
