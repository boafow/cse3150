#include "ECGraphicController.h"
#include "ECGraphicViewImp.h"
#include "ECShape.h"



//********************************************
// Command
ECCommandHistory::ECCommandHistory():currentCommandIndex(-1)
{
}

ECCommandHistory::~ECCommandHistory()
{
    for (int i = 0; i < commandHistory.size(); i++)
    {
        delete commandHistory[i];
    }
    commandHistory.clear();
    currentCommandIndex = -1;
}

bool ECCommandHistory::Undo()
{
    if (currentCommandIndex >= 0)
    {
        commandHistory[currentCommandIndex]->UnExecute();
        --currentCommandIndex;
        return true;
    }
    return false;
}

bool ECCommandHistory::Redo()
{
    if (currentCommandIndex < commandHistory.size() - 1)
    {
        ++currentCommandIndex;
        commandHistory[currentCommandIndex]->Execute();
        return true;
    }
    return false;
}

void ECCommandHistory::ExecuteCmd(ECCommand *pCmd)
{
    pCmd->Execute();
    if(currentCommandIndex >= -1){
        int szList = commandHistory.size();
        for (int i = currentCommandIndex + 1; i < szList; ++i)
        {
            delete commandHistory.back();
            commandHistory.pop_back();
        }
        commandHistory.push_back(pCmd);
        ++currentCommandIndex;
    }
}
//********************************************
ECGraphicController::ECGraphicController(ECGraphicDocument &docIn) : doc(docIn)
{}

ECGraphicController::~ECGraphicController()
{}


bool ECGraphicController::Undo()
{
    return commandHistory.Undo();
}

bool ECGraphicController::Redo()
{
    return commandHistory.Redo();
}

//********************************************
ECGraphicDocument::ECGraphicDocument(): controller(*this)
{}

ECGraphicDocument::~ECGraphicDocument()
{
    for (int i = 0; i < shapes.size(); i++)
    {
        delete shapes[i];
    }
    shapes.clear();
}

void ECGraphicDocument::CreateShape(ECShape *pShape)
{
    shapes.push_back(pShape);
}

void ECGraphicDocument::DeleteShape(ECShape *pShape)
{
    for (int i = 0; i < shapes.size(); i++)
    {
        if (shapes[i] == pShape)
        {
            shapes.erase(shapes.begin() + i);
            delete pShape;
            break;
        }
    }
}