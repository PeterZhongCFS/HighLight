#ifndef SYNTAX_C
#define SYNTAX_C
#include <stdio.h>
#include "lexical.h"
#include "syntaxHead.h"
void headC(string cppname)
{
	putTag(OPEN,"head");
	writeWord("\n");
	putTag(OPEN,"title");
	writeWord(cppname);
	putTag(CLOSE,"title");
	writeWord("\n");
	putTag(CLOSE,"head");
	writeWord("\n");
}
void WordC()
{
	while(1)
	{
		token tok=lexical();
		if(tok==SCANEOF)break; ;
		if(tok==SPACE)
		{
			fputc(buffer[0],OutputStream);
			continue;
		}
		if(tok==ID)
		{
			string idname;
			strcpy(idname,buffer);
			token tok2=lexical();
			if(tok2==SYMBOL)
			{
				if(strcmp(buffer,"(")==0)
				{
					tok=FUNCINC;
				}
			}
			if(last_token!=UDF)
				putTag(CLOSE,"font");
			string Tag;
			sprintf(Tag,"font color=%s",info[tok]);
			putTag(OPEN,Tag);
			fprintf(OutputStream,idname);
			if(tok!=tok2)
			{
				putTag(CLOSE,"font");
				sprintf(Tag,"font color=%s",info[tok2]);
				putTag(OPEN,Tag);
			}
			WriteBuffer();
			last_token=tok2;
			continue;
		}
		if(tok!=last_token)
		{
			if(last_token!=UDF)
				putTag(CLOSE,"font");
			string Tag;
			sprintf(Tag,"font color=%s",info[tok]);
			putTag(OPEN,Tag);
		}
		last_token=tok;
		WriteBuffer();
	}
	if(last_token!=UDF)
		putTag(CLOSE,"font");
}
void bodyC(string cppname)
{
	putTag(OPEN,"body text=\"#000000\" bgcolor=\"#CCE8CF\"");
	writeWord("\n");
	putTag(OPEN,"pre");
	putTag(OPEN,"code");
	putTag(OPEN,"font style=font-size:20pt face=\"Courier New\"");
	printf("Writer:");
	string Writer;
	gets(Writer);
	putTag(OPEN,"font color=#008000");
	writeWord("/*\n");
	writeWord(" *Written by:");
	writeWord(Writer);
	writeWord("\n");
	writeWord(" *Developed by synEdit@Cfree5.0\n");
	writeWord("*/\n");
	putTag(CLOSE,"span");
	WordC();
	writeWord("\n");
	putTag(CLOSE,"font");
	putTag(CLOSE,"code");
	putTag(CLOSE,"pre");
	writeWord("\n");
	putTag(CLOSE,"body");
	writeWord("\n");
}
void RegistStyleC()
{
	strcpy(info[STRING],"#808080");
	strcpy(info[ALPHA],"#808080");
	strcpy(info[COMMANT],"#008000");
	strcpy(info[KEYWORD],"#FF0000");
	strcpy(info[DIGIT],"#FF0000");
	strcpy(info[ID],"#808080");
	strcpy(info[ILL],"#FF00FF");
	strcpy(info[SYMBOL],"#000000");
	strcpy(info[PRE],"#008000");
	strcpy(info[SPACE],"#000000");
	strcpy(info[TYPEINC],"#0000FF");
	strcpy(info[FUNCINC],"#880000");
}
void system_goal_Cfree(string cppname)
{
	RegistStyleC();
	putTag(OPEN,"html");
	writeWord("\n");
	headC(cppname);
	putTag(OPEN,"!-- Exported by C-Free C/C++ IDE --");
	writeWord("\n");
	bodyC(cppname);
	putTag(CLOSE,"html");
	writeWord("\n");
}
#endif
