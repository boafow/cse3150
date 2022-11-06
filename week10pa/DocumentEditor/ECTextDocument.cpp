#include "ECTextDocument.h"
#include <iostream>
#include <cctype>

using namespace std;

// **********************************************************
// Commands

// your code goes here 



// **********************************************************
// Controller for text document

ECTextDocumentCtrl :: ECTextDocumentCtrl(ECTextDocument &docIn) 
{
	textDocument = docIn;
}

ECTextDocumentCtrl :: ~ECTextDocumentCtrl()
{
}

void ECTextDocumentCtrl :: InsertTextAt(int pos, const std::vector<char> &listCharsToIns)
{
	for(auto charToInsert : listCharsToIns){
		textDocument->InsertCharAt(pos, charToInsert);
		++pos;
	}
}

void ECTextDocumentCtrl :: RemoveTextAt(int pos, int lenToRemove)
{
	for(int i = 0; i < lenToRemove; ++i){
		textDocument->RemoveCharAt(pos);
	}
}

void ECTextDocumentCtrl :: CapTextAt(int pos, int lenToCap)
{
	for(int i = 0; i < lenToCap; ++i){
                textDocument->CapCharAt(pos);
		++pos;
        }

}

void ECTextDocumentCtrl :: LowerTextAt(int pos, int lenToLower)
{
	for(int i = 0; i < lenToLower; ++i){
                textDocument->LowerCharAt(pos);
                ++pos;
        }
}

bool ECTextDocumentCtrl :: Undo()
{
  // your code
}

bool ECTextDocumentCtrl :: Redo()
{
  // your code
}

// **********************************************************
// Document for text document


ECTextDocument :: ECTextDocument() 
{
}

ECTextDocument :: ~ECTextDocument()
{
}

ECTextDocumentCtrl & ECTextDocument :: GetCtrl()
{
    return docCtrl;
}

char ECTextDocument :: GetCharAt(int pos) const
{
    return listChars[pos];
}

void ECTextDocument :: InsertCharAt(int pos, char ch)
{
	doc.insert(doc.begin() + pos, ch);
}

void ECTextDocument :: RemoveCharAt(int pos)
{
	doc.remove(doc.begin() + pos);
}

void ECTextDocument :: CapCharAt(int pos)
{
	if(!isupper(doc[pos]) && isalpha(doc[pos])){
		doc[pos] = toupper(doc[pos]);
	}
}

void ECTextDocument :: LowerCharAt(int pos)
{
	if(!islower(doc[pos]) && isalpha(doc[pos])){
                doc[pos] = tolower(doc[pos]);
        }

}

