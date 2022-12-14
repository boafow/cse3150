//
//  ECTextDocument.h
//
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#ifndef ECTextDocument_h
#define ECTextDocument_h

#include "ECCommand.h"
#include <vector>

class ECTextDocument;

// **********************************************************
// Implements Commands for editing
class InsertTextCmd : public ECCommand
{
    public:
        InsertTextCmd(ECTextDocument &docIn, int posIn, const std::vector<char> &listCharsToInsIn) : 
        doc(&docIn), pos(posIn), listCharsToIns(listCharsToInsIn) {}
        virtual void Execute() override;
        virtual void UnExecute() override;
    private:
        ECTextDocument *doc;
        int pos;
        std::vector<char> listCharsToIns;
};

class RemoveTextCmd : public ECCommand
{
    public:
        RemoveTextCmd(ECTextDocument &docIn, int posIn, int lenToRemoveIn, const std::vector<char> &listCharsRemoved): 
        doc(&docIn), pos(posIn), lenToRemove(lenToRemoveIn), listCharsRemoved(listCharsRemoved) {}
        virtual void Execute() override;
        virtual void UnExecute() override;
    private:
        ECTextDocument *doc;
        int pos;
        int lenToRemove;    
        std::vector<char> listCharsRemoved;
};

class CapTextCmd : public ECCommand
{
    public:
        CapTextCmd(ECTextDocument &docIn, int posIn, int lenToCapIn) : 
        doc(&docIn), pos(posIn), lenToCap(lenToCapIn) {}
        virtual void Execute() override;
        virtual void UnExecute() override;
    private:
        ECTextDocument *doc;
        int pos;
        int lenToCap;    
};

class LowerTextCmd : public ECCommand
{
    public:
        LowerTextCmd(ECTextDocument &docIn, int posIn, int lenToLowerIn) : 
        doc(&docIn), pos(posIn), lenToLower(lenToLowerIn) {}
        virtual void Execute() override;
        virtual void UnExecute() override;
    private:
        ECTextDocument *doc;
        int pos;
        int lenToLower;    
};

// your code goes here

// **********************************************************
// Controller for text document

class ECTextDocumentCtrl
{
public:
    ECTextDocumentCtrl(ECTextDocument &docIn); // conroller constructor takes the document as input
    virtual ~ECTextDocumentCtrl();
    void InsertTextAt(int pos, const std::vector<char> &listCharsToIns); // insert a list of characters starting at position
    void RemoveTextAt(int pos, int lenToRemove);                         // remove a segment of characters  of lenToRemove starting from pos
    void CapTextAt(int pos, int lenToCap);                               // Capitalize the text of lenToCap long starting from pos
    void LowerTextAt(int pos, int lenToLower);                           // Lowercase the text of lenToLoer starting from pos
    bool Undo();                                                         // undo any change you did to the text
    bool Redo();                                                         // redo the change to the text

private:
    ECTextDocument *doc; // the document we are controlling
    ECCommandHistory cmdHistory; // the command history

};

// **********************************************************
// Document for text document

class ECTextDocument
{
public:
    ECTextDocument();
    virtual ~ECTextDocument();
    ECTextDocumentCtrl &GetCtrl(); // return document controller
    int GetDocLen() const { return doc.size(); }
    char GetCharAt(int pos) const;       // get char at current position
    void InsertCharAt(int pos, char ch); // insert a single char at position
    void RemoveCharAt(int pos);          // erase a single char at position
    void CapCharAt(int pos);             // capitalize the char at position
    void LowerCharAt(int pos);           // lowercase the char at position
    std::vector<char> doc;

private:
    ECTextDocumentCtrl *docCtrl;
};

#endif /* ECTextDocument_h */
