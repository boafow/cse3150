#include "ECCommand.h"

// ******************************************************
// Implement command history

ECCommandHistory :: ECCommandHistory(): cmdHistory()
{
}

ECCommandHistory :: ~ECCommandHistory()
{
  // your code goes here
}

void ECCommandHistory :: ExecuteCmd( ECCommand *pCmd )
{
  // your code goes here
  pCmd->Execute();
  cmdHistory.push_back(pCmd);
  redoHistory.clear();  
}

bool ECCommandHistory :: Undo()
{
  // your code goes here
  if (cmdHistory.size() == 0)  return false;
  cmdHistory.back()->UnExecute();
  redoHistory.push_back(cmdHistory.back());
  cmdHistory.pop_back();
  return true;
}

bool ECCommandHistory :: Redo()
{
  if (redoHistory.size() == 0) return false;
  redoHistory.back()->Execute();
  redoHistory.pop_back();
  return true;
}




