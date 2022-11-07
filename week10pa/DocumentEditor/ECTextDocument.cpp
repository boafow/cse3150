#include "ECTextDocument.h"
#include <iostream>
#include <cctype>

using namespace std;

// **********************************************************
// Commands
void InsertTextCmd ::Execute()
{
	for (int i = pos; i < listCharsToIns.size() + pos; i++)
	{
		doc->InsertCharAt(i, listCharsToIns[i - pos]);
	}

	//print all chars in doc vector
	cout << "InsertTextCmd::Execute() - doc vector: ";
	for (int i = 0; i < doc->GetDocLen(); ++i)
	{
		cout << doc->GetCharAt(i);
	}
	cout << endl;

	
}

void InsertTextCmd ::UnExecute()
{
		for (int i = 0; i < listCharsToIns.size(); i++)
	{
		doc->RemoveCharAt(pos);
	}

	cout << "InsertTextCmd::Execute() - doc vector: ";
	for (int i = 0; i < doc->GetDocLen(); ++i)
	{
		cout << doc->GetCharAt(i);
	}
	cout << endl;


}

void RemoveTextCmd ::Execute()
{
	for (int i = 0; i < lenToRemove; i++)
	{
		listCharsRemoved.push_back(doc->GetCharAt(pos));
		doc->RemoveCharAt(pos);
	}

//print all chars in doc vector
	cout << "RemoveTextCmd::Execute() - doc vector: ";
	//print pos: pos and lenToRemove
	cout << "pos: " << pos << " lenToRemove: " << lenToRemove << endl;
	for (int i = 0; i < doc->GetDocLen(); ++i)
	{
		cout << doc->GetCharAt(i);
	}
	cout << endl;

	// save the removed chars for unexecute
	
}

void RemoveTextCmd ::UnExecute()
{

		for (int i = pos; i < listCharsRemoved.size() + pos; i++)
	{
		doc->InsertCharAt(i, listCharsRemoved[i - pos]);
	}

	cout << "RemoveTextCmd::UnExecute() - doc vector: ";
	for (int i = 0; i < doc->GetDocLen(); ++i)
	{
		cout << doc->GetCharAt(i);
	}
	cout << endl;


}

void CapTextCmd ::Execute()
{

	for (int i = pos; i < lenToCap + pos; i++)
	{
		doc->CapCharAt(i);
	}

	cout << "CapTextCmd::Execute() - doc vector: ";
	for (int i = 0; i < doc->GetDocLen(); ++i)
	{
		cout << doc->GetCharAt(i);
	}
	cout << endl;

	
}

void CapTextCmd ::UnExecute()
{

	for (int i = pos; i < lenToCap + pos; i++)
	{
		doc->LowerCharAt(i);
	}

	cout << "CapTextCmd::UnExecute() - doc vector: ";
	for (int i = 0; i < doc->GetDocLen(); ++i)
	{
		cout << doc->GetCharAt(i);
	}
	cout << endl;

	
}

void LowerTextCmd ::Execute()
{
	for (int i = pos; i < lenToLower + pos; i++)
	{
		doc->LowerCharAt(i);
	}
	cout << "LowerTextCmd::Execute() - doc vector: ";

	for (int i = 0; i < doc->GetDocLen(); ++i)
	{
		cout << doc->GetCharAt(i);
	}
	cout << endl;

	
}

void LowerTextCmd ::UnExecute()
{
	for (int i = pos; i < lenToLower + pos; i++)
	{
		doc->CapCharAt(i);
	}

	cout << "LowerTextCmd::UnExecute() - doc vector: ";
	for (int i = 0; i < doc->GetDocLen(); ++i)
	{
		cout << doc->GetCharAt(i);
	}
	cout << endl;

	
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
	// print out the characters before the insert
	InsertTextCmd *pCmd = new InsertTextCmd(*doc, pos, listCharsToIns);
	cmdHistory.ExecuteCmd(pCmd);
}

void ECTextDocumentCtrl ::RemoveTextAt(int pos, int lenToRemove)
{
	// create vector for removed chars
	std::vector<char> listCharsRemoved;
	RemoveTextCmd *pCmd = new RemoveTextCmd(*doc, pos, lenToRemove, listCharsRemoved);
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
