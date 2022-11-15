//
//  ECTextDocument.cpp
//  

#include "ECTextDocument.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

// **********************************************************
// Commands

ECInsertCommand::ECInsertCommand(ECTextDocument &docIn): textDoc(docIn){}
ECInsertCommand::~ECInsertCommand(){}
void ECInsertCommand::AddIndivCommand(int index, char c){
  indivCommands.push_back(pair<int, char>(index, c));
}
void ECInsertCommand::Execute(){
  for(auto command : indivCommands){
    int index = command.first;
    int character = command.second;
    textDoc.InsertCharAt(index, character);
  }
}
void ECInsertCommand::UnExecute(){
  for(auto command : indivCommands){
    int index = command.first;
    textDoc.RemoveCharAt(index);
  }
}
ECRemoveCommand::ECRemoveCommand(ECTextDocument &docIn): textDoc(docIn){}
ECRemoveCommand::~ECRemoveCommand(){}
void ECRemoveCommand::AddIndivCommand(int index, char c){
  indivCommands.push_back(index);
  removedCharacters.push_back(c);
}
void ECRemoveCommand::Execute(){
  for(int pos : indivCommands){
    textDoc.RemoveCharAt(pos);
  }
}
void ECRemoveCommand::UnExecute(){
  assert(indivCommands.size() == removedCharacters.size());
  for(int i = (int)indivCommands.size() - 1; i >= 0; i--){
    textDoc.InsertCharAt(indivCommands[i], removedCharacters[i]);
  }
}


// more commands ...


// **********************************************************
// Controller for text document

ECTextDocumentCtrl :: ECTextDocumentCtrl(ECTextDocument &docIn): textDoc(docIn)
{
}

ECTextDocumentCtrl :: ~ECTextDocumentCtrl()
{
}

void ECTextDocumentCtrl :: InsertTextAt(int pos, const std::vector<char> &listCharsToIns)
{
  ECInsertCommand* insertCommand = new ECInsertCommand(textDoc);
  for(auto k = listCharsToIns.rbegin(); k != listCharsToIns.rend(); k++){
    insertCommand->AddIndivCommand(pos, *k);
  }
  history.ExecuteCmd(insertCommand);
}

void ECTextDocumentCtrl :: RemoveTextAt(int pos, int lenToRemove)
{
  ECRemoveCommand* remCommand = new ECRemoveCommand(textDoc);
  int count = 0;
  for(int i = pos; i < textDoc.GetDocLen() && count < lenToRemove; i++){
  //for(int i = 0; i < lenToRemove; i++){
    if(pos >= textDoc.GetDocLen()) break;
    remCommand->AddIndivCommand(pos, textDoc.GetCharAt(i));
    count++;
  }
  history.ExecuteCmd(remCommand);
}

// .....

bool ECTextDocumentCtrl :: Undo()
{
  return history.Undo();
}

bool ECTextDocumentCtrl :: Redo()
{
  return history.Redo();
}

// **********************************************************
// Document for text document

// implementation omitted


// ******************************************************
// Implement command history

ECCommandHistory :: ECCommandHistory(): pos(-1)
{
}

ECCommandHistory :: ~ECCommandHistory()
{
  for(ECCommand* command : history){
    delete command;
  }
}

bool ECCommandHistory::Undo(){
  if(history.size() == 0) return false;
  if(pos < 0){
    pos = history.size() - 1;
  }
  history[pos]->UnExecute();
  pos--;
  return true;
}
bool ECCommandHistory::Redo(){
  if(history.size() == 0 || pos == (int)history.size()) return false;
  pos++;
  history[pos]->Execute();
  return true;
}
void ECCommandHistory::ExecuteCmd( ECCommand *pCmd ){
  history.push_back(pCmd);
  pCmd->Execute();
  pos++;
}

