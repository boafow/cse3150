#ifndef ECGRAHPICCONTROLLER_H
#define ECGRAHPICCONTROLLER_H

#include <vector>
#include <map>
#include <iostream>
#include "ECGraphicViewImp.h"
#include "ECShape.h"

//********************************************
// Command
class ECCommand
{
public:
    virtual ~ECCommand() {}
    virtual void Execute() = 0;
    virtual void UnExecute() = 0;
};

class ECCreateRectangleCommand : public ECCommand
{
    ECRectangle *rect;
    ECGraphicViewImp *view;
public:
    ECCreateRectangleCommand(ECGraphicViewImp *view, int x1, int y1, int x2, int y2);
    virtual void Execute();
    virtual void UnExecute();
};

class ECCreateCircleCommand : public ECCommand
{
    ECCircle *circle;
    ECGraphicViewImp *view;
public:
    ECCreateCircleCommand(ECGraphicViewImp *view, int xcenter, int ycenter, double radius);
    virtual void Execute();
    virtual void UnExecute();
};

class ECCreateEllipseCommand : public ECCommand
{
    ECEllipse *ellipse;
    ECGraphicViewImp *view;
public:
    ECCreateEllipseCommand(ECGraphicViewImp *view, int xcenter, int ycenter, double radiusx, double radiusy);
    virtual void Execute();
    virtual void UnExecute();
};

//********************************************
// Command History
class ECCommandHistory
{
    std::vector<ECCommand *> commandHistory;
    int currentCommandIndex;
    int maxCommandIndex;

public:
    ECCommandHistory() : currentCommandIndex(-1), maxCommandIndex(-1) {}
    void AddCommand(ECCommand *pCmd);
    void Execute();
    void Unexecute();
};

//********************************************
// Controller
class ECGraphicController
{
    ECGraphicViewImp &view;
    ECCommandHistory commandHistory;

public:
    ECGraphicController(ECGraphicViewImp &view) : view(view) {}
    virtual ~ECGraphicController(){};
    void CreateShape(ECShape *shape);
    void Undo();
    void Redo();
};

//********************************************
// Model
class ECGraphicDocument
{
    std::vector<ECShape *> shapes;
    ECGraphicController controller;

public:
    ECGraphicDocument();
    virtual ~ECGraphicDocument();
    ECGraphicController &GetController();
    int GetNumShapes() const;
    ECShape *GetShape(int index) const;
    void CreateShape(ECShape *shape);
    virtual void DeleteShape(ECShape *shape);
};

#endif /* ECGRAHPICCONTROLLER_H */