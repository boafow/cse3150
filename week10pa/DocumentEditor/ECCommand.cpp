#include "ECCommand.h"

// ******************************************************
// Implement command history

ECCommandHistory :: ECCommandHistory(): cmdHistory(), cmdIndex(0)
{
}

ECCommandHistory :: ~ECCommandHistory()
{
  // your code goes here
}

void ECCommandHistory :: ExecuteCmd( ECCommand *pCmd )
{
  cmdIndex = cmdHistory.size();

  pCmd->Execute();
  cmdHistory.push_back(pCmd);

  cmdIndex++;
}

bool ECCommandHistory :: Undo()
{
  if (cmdIndex == 0)
  {
    return false;
  }

  cmdIndex--;
  cmdHistory[cmdIndex]->UnExecute();

  return true;
}

bool ECCommandHistory :: Redo()
{
  if (cmdIndex == cmdHistory.size())
  {
    return false;
  }

  cmdHistory[cmdIndex]->Execute();
  cmdIndex++;

  return true;
}




