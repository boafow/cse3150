#ifndef ECGRAHPICCONTROLLER_H
#define ECGRAHPICCONTROLLER_H

#include <vector>
#include <map>
#include <iostream>
#include "ECGraphicViewImp.h"
#include "ECShape.h"

class ECGraphicDocument;
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
    ECGraphicDocument &doc;
public:
    ECCreateRectangleCommand(ECGraphicViewImp &docIn, int x1, int y1, int x2, int y2);
    virtual void Execute();
    virtual void UnExecute();
};

class ECCreateCircleCommand : public ECCommand
{
    ECGraphicDocument &doc;
public:
    ECCreateCircleCommand(ECGraphicViewImp &docIn, int xcenter, int ycenter, double radius);
    virtual void Execute();
    virtual void UnExecute();
};

class ECCreateEllipseCommand : public ECCommand
{
    ECGraphicDocument &doc;
public:
    ECCreateEllipseCommand(ECGraphicViewImp &docIn, int xcenter, int ycenter, double radiusx, double radiusy);
    virtual void Execute();
    virtual void UnExecute();
};

//********************************************
// Command History
class ECCommandHistory
{
    std::vector<ECCommand *> commandHistory;
    int currentCommandIndex;
public:
    ECCommandHistory();
    ~ECCommandHistory();
    void ExecuteCmd(ECCommand *pCmd);
    bool Undo();
    bool Redo();
};

//********************************************
// Controller
class ECGraphicController
{
    ECGraphicDocument &doc;
    ECCommandHistory commandHistory;

public:
    ECGraphicController(ECGraphicDocument &docIn);
    virtual ~ECGraphicController();
    void CreateShape(ECShape *shape);
    bool Undo();
    bool Redo();
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
    void CreateShape(ECShape *shape);
    void DeleteShape(ECShape *shape);
};

#endif /* ECGRAHPICCONTROLLER_H */