#include "ECTextDocument.h"
#include <iostream>
#include <cctype>

using namespace std;

// **********************************************************
// Commands
void InsertTextCmd ::Execute()
{
	for (auto charToInsert : listCharsToIns)
	{
		doc->InsertCharAt(pos, charToInsert);
		pos += 1;
	}
}

void InsertTextCmd ::UnExecute()
{
	for (int i = 0; i < listCharsToIns.size(); i++)
	{
		doc->RemoveCharAt(pos);
	}
}

void RemoveTextCmd ::Execute()
{
	for (int i = 0; i < lenToRemove; i++)
	{
		doc->RemoveCharAt(pos);
	}
}

void RemoveTextCmd ::UnExecute()
{
	for (int i = 0; i < lenToRemove; i++)
	{
		doc->InsertCharAt(pos, doc->GetCharAt(pos));
		pos += 1;
	}
}

void CapTextCmd ::Execute()
{
	for (int i = 0; i < lenToCap; i++)
	{
		doc->CapCharAt(pos);
		pos += 1;
	}
}

void CapTextCmd ::UnExecute()
{
	cout << "CapTextCmd::UnExecute() not implemented" << endl;
}

void LowerTextCmd ::Execute()
{
	for (int i = 0; i < lenToLower; i++)
	{
		doc->LowerCharAt(pos);
		pos += 1;
	}
}

void LowerTextCmd ::UnExecute()
{
	for(int i = 0; i < lenToLower; ++i){
		doc->CapCharAt(pos + i);
	}
}
// your code goes here

// **********************************************************
// Controller for text document

ECTextDocumentCtrl ::ECTextDocumentCtrl(ECTextDocument &docIn) : doc(&docIn), cmdHistory()
{
}

ECTextDocumentCtrl ::~ECTextDocumentCtrl()
{
}

void ECTextDocumentCtrl ::InsertTextAt(int pos, const std::vector<char> &listCharsToIns)
{
	InsertTextCmd *pCmd = new InsertTextCmd(*doc, pos, listCharsToIns);
	cmdHistory.ExecuteCmd(pCmd);
}

void ECTextDocumentCtrl ::RemoveTextAt(int pos, int lenToRemove)
{
	RemoveTextCmd *pCmd = new RemoveTextCmd(*doc, pos, lenToRemove);
	cmdHistory.ExecuteCmd(pCmd);
}

void ECTextDocumentCtrl ::CapTextAt(int pos, int lenToCap)
{
	CapTextCmd *pCmd = new CapTextCmd(*doc, pos, lenToCap);
	cmdHistory.ExecuteCmd(pCmd);
}

void ECTextDocumentCtrl ::LowerTextAt(int pos, int lenToLower)
{
	LowerTextCmd *pCmd = new LowerTextCmd(*doc, pos, lenToLower);
	cmdHistory.ExecuteCmd(pCmd);
}

bool ECTextDocumentCtrl ::Undo()
{
	return cmdHistory.Undo();
}

bool ECTextDocumentCtrl ::Redo()
{
	return cmdHistory.Redo();
}

// **********************************************************
// Document for text document

ECTextDocument ::ECTextDocument() : docCtrl(new ECTextDocumentCtrl(*this))
{
}

ECTextDocument ::~ECTextDocument()
{
}

ECTextDocumentCtrl &ECTextDocument ::GetCtrl()
{
	return *docCtrl;
}

char ECTextDocument ::GetCharAt(int pos) const
{
	return doc[pos];
}

void ECTextDocument ::InsertCharAt(int pos, char ch)
{
	doc.insert(doc.begin() + pos, ch);
}

void ECTextDocument ::RemoveCharAt(int pos)
{
	doc.erase(doc.begin() + pos);
}

void ECTextDocument ::CapCharAt(int pos)
{
	if (!isupper(doc[pos]) && isalpha(doc[pos]))
	{
		doc[pos] = toupper(doc[pos]);
	}
}

void ECTextDocument ::LowerCharAt(int pos)
{
	if (!islower(doc[pos]) && isalpha(doc[pos]))
	{
		doc[pos] = tolower(doc[pos]);
	}
}
