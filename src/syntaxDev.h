#ifndef SYNTAX_D
#define SYNTAX_D
#include <stdio.h>
#include "buffer.h"
#include "lexical.h"
#include "syntaxHead.h"
void headD(string cppname)
{
	putTag(OPEN,"head");
	writeWord("\n");
	putTag(OPEN,"title");
	writeWord(cppname);
	putTag(CLOSE,"title");
	writeWord("\n");
	putTag(ONLY,"meta http-equiv=\"Content-Type\" content=\"text/html\"");
	writeWord("\n");
	putTag(ONLY,"meta name=\"generator\" content=\"SynEdit HTML exporter\"");
	writeWord("\n");
	putTag(OPEN,"style type=\"text/css\"");
	writeWord("\n");
	writeWord("<!--\n");
	writeWord("body { color: #000000; background-color: #FFFFFF; }\n");
	writeWord(".cpp1-character { background-color: #FFFFFF; color: #000000; }\n");
	writeWord(".cpp1-comment { color: #0078D7; font-style: italic; }\n");
	writeWord(".cpp1-identifier { color: #000000; }\n");
	writeWord(".cpp1-illegalchar { color: #000000; }\n");
	writeWord(".cpp1-number { color: #800080; }\n");
	writeWord(".cpp1-preprocessor { color: #008000; }\n");
	writeWord(".cpp1-reservedword { background-color: #FFFFFF; color: #000000; font-weight: bold; }\n");
	writeWord(".cpp1-space { background-color: #FFFFFF; color: #000000; }\n");
	writeWord(".cpp1-string { background-color: #FFFFFF; color: #0000FF; font-weight: bold; }\n");
	writeWord(".cpp1-symbol { color: #FF0000; font-weight: bold; }\n");
	writeWord("-->\n");
	writeWord("\n");
	putTag(CLOSE,"style");
	writeWord("\n");
	putTag(CLOSE,"head");
	writeWord("\n");
}
void RegistStyleD()
{
	strcpy(info[STRING],"cpp1-string");
	strcpy(info[ALPHA],"cpp1-character");
	strcpy(info[COMMANT],"cpp1-comment");
	strcpy(info[KEYWORD],"cpp1-reservedword");
	strcpy(info[DIGIT],"cpp1-number");
	strcpy(info[ID],"cpp1-identifier");
	strcpy(info[ILL],"cpp1-illegalchar");
	strcpy(info[SYMBOL],"cpp1-symbol");
	strcpy(info[PRE],"cpp1-preprocessor");
	strcpy(info[SPACE],"cpp1-space");
}
void WordD()
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
		if(tok!=last_token)
		{
			if(last_token!=UDF)
				putTag(CLOSE,"span");
			string Tag;
			sprintf(Tag,"span class=%s",info[tok]);
			putTag(OPEN,Tag);
		}
		last_token=tok;
		WriteBuffer();
	}
	if(last_token!=UDF)
		putTag(CLOSE,"span");
}
void bodyD(string cppname)
{
	putTag(OPEN,"body");
	writeWord("\n");
	putTag(OPEN,"pre");
	writeWord("\n");
	putTag(OPEN,"code");
	putTag(OPEN,"span style=\"font: 20pt Consolas;\"");
	printf("Writer:");
	string Writer;
	gets(Writer);
	putTag(OPEN,"span class=cpp1-comment");
	writeWord("/*\n");
	writeWord(" *Written by:");
	writeWord(Writer);
	writeWord("\n");
	writeWord(" *Developed by synEdit@Dev C++\n");
	writeWord("*/\n");
	putTag(CLOSE,"span");
	WordD();
	putTag(CLOSE,"span");
	writeWord("\n");
	putTag(CLOSE,"span");
	putTag(CLOSE,"code");
	writeWord("\n");
	putTag(CLOSE,"pre");
	writeWord("\n");
	putTag(CLOSE,"body");
	writeWord("\n");
}
void system_goal_Dev(string cppname)
{
	RegistStyleD();
	putTag(OPEN,"?xml version=\"1.0\" encoding=\"iso-8859-1\"?");
	putTag(OPEN,"!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\" \"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\"");
	putTag(OPEN,"html xmlns=\"http://www.w3.org/1999/xhtml\"");
	writeWord("\n");
	headD(cppname);
	bodyD(cppname);
	putTag(CLOSE,"html");
	writeWord("\n");
}
#endif
