#ifndef SYNTAX_H
#define SYNTAX_H
#include <stdio.h>
#include "lexical.h"
#include "buffer.h"
#define OPEN 0
#define CLOSE 1
#define ONLY 2
void putTag(int model,string tag)
{
	fprintf(OutputStream,"<");
	if(model==CLOSE)
	fputc('/',OutputStream);
	fprintf(OutputStream,"%s",tag);
	if(model==ONLY)
		fprintf(OutputStream," /");
	fputc('>',OutputStream);
	
}
void writeWord(char* ptr)
{
	fprintf(OutputStream,"%s",ptr);
}
token last_token=UDF;
void WriteBuffer()
{
	char*ptr=buffer;
	while(*ptr!=0)
	{
		switch(*ptr)
		{
			case '<':
				fprintf(OutputStream,"&lt;");
				break;
			case '>':
				fprintf(OutputStream,"&gt;");
				break;
			case '&':
				fprintf(OutputStream,"&amp;");
				break;
			case '\"':
				fprintf(OutputStream,"&quot;");
				break;
			default:
				fputc(*ptr,OutputStream);
		}
		ptr++;
	}
}
#endif
