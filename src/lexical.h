#ifndef LEXICAL_H
#define LEXICAL_H
#include "token.h"
#include <ctype.h>
#include "buffer.h"
FILE*InputStream=stdin;
FILE*OutputStream=stdout;
int Model;
void RegistI(FILE*fp)
{
	InputStream=fp;
}
void RegistO(FILE*fp)
{
	OutputStream=fp;
}
void RegistModel(int Mod)
{
	Model=Mod;
}
token lexical()
{
	int c;
	clear_buffer();
	if(feof(InputStream))
		return SCANEOF;
	while((c=getc(InputStream))!=EOF)
	{
		if(isspace(c))
		{
			push_buffer(c);
			return SPACE;
		}
		if(isalpha(c))
		{
			push_buffer(c);
			for(c=fgetc(InputStream);isalnum(c)||(c=='_');c=fgetc(InputStream))
				push_buffer(c);
			ungetc(c,InputStream);
			if(Model==1)
				return check_keywordC();
			return check_keywordD();
		}
		if(isdigit(c))
		{
			push_buffer(c);
			for(c=fgetc(InputStream);isdigit(c)||(c=='x')||(c=='X')||(c=='.');c=fgetc(InputStream))
				push_buffer(c);
			ungetc(c,InputStream);
			return DIGIT;
		}
		if(c=='\'')
		{
			push_buffer(c);
			c=fgetc(InputStream);
			do{
				push_buffer(c);
				if(c=='\\')
				{
					c=fgetc(InputStream);
					push_buffer(c);
				}
				c=fgetc(InputStream);
			}
			while(c!='\'');
			push_buffer(c);
			return ALPHA;
		}
		if(c=='\"')
		{
			push_buffer(c);
			c=fgetc(InputStream);
			while(c!='\"')
			{
				push_buffer(c);
				if(c=='\\')
				{
					c=fgetc(InputStream);
					push_buffer(c);
				}
				c=fgetc(InputStream);
			}
			push_buffer(c);
			return STRING;
		}
		if(c=='#')
		{
			push_buffer(c);
			while(!feof(InputStream))
			{
				c=fgetc(InputStream);
				if(c=='\n')break;
				push_buffer(c);
			}
			ungetc(c,InputStream);
			return PRE;
		}
		switch(c)
		{
			case '(':
			case ')':
			case '<':
			case '>':
			case '[':
			case ']':	
			case '{':
			case '}':
			case '=':
			case '!':
			case ';':
			case ':':
			case '+':
			case '-':
			case '*':
				buffer[0]=c;
				return SYMBOL;
			case '/':
				c=fgetc(InputStream);
				if(c=='/')
				{
					push_buffer(c);
					push_buffer(c);
					while(!feof(InputStream)&&((c=fgetc(InputStream))!='\n'))
					{
						push_buffer(c);
					}
					ungetc(c,InputStream);
					return COMMANT;
				}
				if(c=='*')
				{
					push_buffer('/');
					push_buffer('*');
					while(!feof(InputStream))
					{
						c=fgetc(InputStream);
						if(c=='*')
						{
							push_buffer(c);
							c=fgetc(InputStream);
							if(c=='/')
							{
								push_buffer(c);
								return COMMANT;
							}
						}
						push_buffer(c);
					}
					return COMMANT;
				}
				ungetc(c,InputStream);
				buffer[0]='/';
				return SYMBOL;
			case '%':
			case '&':
			case '|':
			case '^':
			case '.':
			case '?':
			case ',':
				buffer[0]=c;
				return SYMBOL;
			default:
				buffer[0]=c;
				return ILL;
		}
	}
	return SCANEOF;
}
#endif
