#include "ECObserver.h"
#include "ECGraphicViewImp.h"

ECCommandHistory::~ECCommandHistory()
{
    for (auto cmd : cmdHistory)
    {
        delete cmd;
    }
}
void ECCommandHistory::AddCommand(ECCommand *cmd)
{
    cmdHistory.push_back(cmd);
    currCmdIndex++;
}
bool ECCommandHistory::Undo()
{
    if (currCmdIndex < 0)
    {
        return false;
    }
    cmdHistory[currCmdIndex]->Unexecute();
    --currCmdIndex;
    return true;
}
bool ECCommandHistory::Redo()
{
    if (currCmdIndex >= cmdHistory.size() - 1)
    {
        return false;
    }
    ++currCmdIndex;
    cmdHistory[currCmdIndex]->Execute();
    return true;
}
void ECCommandHistory::ExecuteCmd(ECCommand *cmd)
{
    cmdHistory[currCmdIndex]->Execute();
    if (currCmdIndex >= -1)
    {
        int listSize = cmdHistory.size();
        for (int i = currCmdIndex + 1; i < listSize; i++)
        {
            delete cmdHistory[i];
            cmdHistory.pop_back();
        }
    }
    cmdHistory.push_back(cmd);
    ++currCmdIndex;
}

MouseDownCommand::MouseDownCommand(ECGraphicModelImp &model) : model(model) {}
void MouseDownCommand::Execute()
{
    // model.MouseDown();
}
void MouseDownCommand::Unexecute()
{
    // model.MouseUp();
}

ECMouseDownObserver::ECMouseDownObserver(ECObserverSubject *view)
{
    this->view = view;
}
ECMouseUpObserver::ECMouseUpObserver(ECObserverSubject *view)
{
    this->view = view;
}
ECMouseMoveObserver::ECMouseMoveObserver(ECObserverSubject *view)
{
    this->view = view;
}
ECKeyDownObserver::ECKeyDownObserver(ECObserverSubject *view)
{
    this->view = view;
}
ECKeyUpObserver::ECKeyUpObserver(ECObserverSubject *view)
{
    this->view = view;
}

void ECMouseDownObserver::Update()
{
    ECGraphicViewImp *viewImp = dynamic_cast<ECGraphicViewImp *>(view);
    if (viewImp->GetCurrEvent() == ECGV_EV_MOUSE_BUTTON_DOWN)
    {
        int x1, y1;
        viewImp->GetCursorPosition(x1, y1);
        std::cout << "Mouse down at (" << x1 << ", " << y1 << ")" << std::endl;
    }
}
void ECMouseUpObserver::Update()
{
    ECGraphicViewImp *viewImp = dynamic_cast<ECGraphicViewImp *>(view);
    if (viewImp->GetCurrEvent() == ECGV_EV_MOUSE_BUTTON_UP)
    {
        int x2, y2;
        viewImp->GetCursorPosition(x2, y2);
        std::cout << "Mouse up at (" << x2 << "," << y2 << ")\n";
    }
}
void ECMouseMoveObserver::Update()
{
    ECGraphicViewImp *viewImp = dynamic_cast<ECGraphicViewImp *>(view);
    if (viewImp->GetCurrEvent() == ECGV_EV_MOUSE_MOVING)
    {
        int x2, y2;
        viewImp->GetCursorPosition(x2, y2);
        std::cout << "Mouse moving at (" << x2 << "," << y2 << ")\n";
    }
}
void ECKeyDownObserver::Update()
{
}
void ECKeyUpObserver::Update()
{
}

ECGraphicControllerImp::ECGraphicControllerImp(ECGraphicModelImp &model): model(model){}
ECGraphicModelImp::ECGraphicModelImp(): ctrl(*this){}

