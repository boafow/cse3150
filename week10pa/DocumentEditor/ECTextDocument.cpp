#include "ECTextDocument.h"
#include <iostream>
#include <cctype>

using namespace std;

// **********************************************************
// Commands

ECCommand command;


// your code goes here

// **********************************************************
// Controller for text document

ECTextDocumentCtrl ::ECTextDocumentCtrl(ECTextDocument &docIn) : doc(&docIn)
{
	// your code goes here
}

ECTextDocumentCtrl ::~ECTextDocumentCtrl()
{
}

void ECTextDocumentCtrl ::InsertTextAt(int pos, const std::vector<char> &listCharsToIns)
{
	for (auto charToInsert : listCharsToIns)
	{
		doc->InsertCharAt(pos, charToInsert);
		pos += 1;
	}
}

void ECTextDocumentCtrl ::RemoveTextAt(int pos, int lenToRemove)
{
	for (int i = 0; i < lenToRemove; ++i)
	{
		doc->RemoveCharAt(pos);
	}
}

void ECTextDocumentCtrl ::CapTextAt(int pos, int lenToCap)
{
	for (int i = 0; i < lenToCap; ++i)
	{
		doc->CapCharAt(pos);
		++pos;
	}
}

void ECTextDocumentCtrl ::LowerTextAt(int pos, int lenToLower)
{
	for (int i = 0; i < lenToLower; ++i)
	{
		doc->LowerCharAt(pos);
		++pos;
	}
}

bool ECTextDocumentCtrl ::Undo()
{
	return true;
}

bool ECTextDocumentCtrl ::Redo()
{
	return true;
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
