//
//  ECTextDocument.cpp
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include "ECTextDocument.h"
#include <iostream>
#include <cctype>

using namespace std;

// **********************************************************
// Commands


// **********************************************************
// Controller for text document

ECTextDocumentCtrl::ECTextDocumentCtrl(ECTextDocument &docIn){
    doc = &docIn;
    version = 0; // so first edit is version 0
}

ECTextDocumentCtrl :: ~ECTextDocumentCtrl()
{
}

void ECTextDocumentCtrl :: InsertTextAt(int pos, const std::vector<char> &listCharsToIns)
{
    
    int i = 0;
    for (auto x : listCharsToIns){
        doc->InsertCharAt(pos + i, x);
        i++;
    }
    std::vector<char> newText = doc->GetChars();
    history.push_back(newText);
    version += 1;
}

void ECTextDocumentCtrl :: RemoveTextAt(int pos, int lenToRemove)
{
    for (int i=0; i<lenToRemove; i++){
        doc->RemoveCharAt(pos);
    }
    std::vector<char> newText = doc->GetChars();
    history.push_back(newText);
    version += 1;
}

...

bool ECTextDocumentCtrl :: Undo()
{   //set to old text
    //int oldSize = oldText.size();
    if (version < 1 ){
        return false;
    }
    int currSize = doc->GetDocLen();
    //std::cout << "size: " << currSize << std::endl;
    
    for (int i=0; i<currSize; i++){
        doc->RemoveCharAt(0);
    } //clear doc
    
    //std::cout << "old size: " << oldText.size() << std::endl;
   
    int i = 0;
    for (auto x : history[version-2]){
        doc->InsertCharAt(i, x);
        i++;
    }
    
    //std::cout << "size: " << doc->GetDocLen() << std::endl;
    version -= 1;
    return true;
}

bool ECTextDocumentCtrl :: Redo()
{   //set to new text
    if (version > history.size() ){
        
        return false;
    }
    
    int currSize = doc->GetDocLen();
    for (int i=0; i<currSize; i++){
        doc->RemoveCharAt(0);
    } //clear doc
    
    
    int i = 0;
    for (auto x : history[version]){
        doc->InsertCharAt(i, x);
        i++;
    }
    
    version += 1;
    return true;
}

// ECTextDocument implemented: omitted
.....
