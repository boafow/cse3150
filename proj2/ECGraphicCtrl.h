#ifndef ECGRAPHICCTRL_H
#define ECGRAPHICCTRL_H

#include "ECObserver.h"
#include "ECCommand.h"
#include "ECGraphicViewImp.h"

//*************************************************************************
// Keystroke Observer
class ECGraphicDoc;

class KeystrokeObserver : public ECObserver
{
public:
    KeystrokeObserver(ECGraphicViewImp *view, ECGraphicDocCtrl &ctrl);
    virtual ~KeystrokeObserver();
    virtual void Update();

private:
    ECGraphicDocCtrl *ctrl;
    ECGraphicViewImp *_subject;
};

//********************************************************************************
// Mouse observer

class MouseEvObserver : public ECObserver
{
public:
    MouseEvObserver(ECGraphicViewImp *view, ECGraphicDocCtrl &ctrl, ECGraphicDoc &docIn);
    virtual ~MouseEvObserver();
    virtual void Update();

private:
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    ECGraphicViewImp *_subject;
    ECGraphicDoc *doc;
    int mode = 0;      // 0 = insertion, 1 = edit
    int shapeType = 0; // 0 = rectangle, 1 = ellipse
    int fill = 0;      // 0 = no fill, 1 = fill
    bool clicked = false;
    ECGraphicDocCtrl *ctrl;
    int pos = -1;
    bool selected = false;
    bool moving = false;
};

class ECShape
{
public:
    ECShape(int x1, int y1, int x2, int y2, int shapeType, int fill) : x1(x1), y1(y1), x2(x2), y2(y2), shapeType(shapeType), fill(fill) {};
    int Getx1() { return x1; }
    int Gety1() { return y1; }
    int Getx2() { return x2; }
    int Gety2() { return y2; }
    int GetShapeType() { return shapeType; }
    int GetFill() { return fill; }
private:
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    int shapeType;
    int fill;
};

class ECCompShape : public ECShape
{
public:
    ECCompShape(vector<ECShape> &shapes) : ECShape(0, 0, 0, 0, -1, 0), shapes(shapes){};
    ~ECCompShape();
    int GetNumShapes() { return shapes.size(); };
    vector<ECShape> GetShapes() { return shapes; };
    
private:
    std::vector<ECShape> shapes;
};

class ECCreateGroupCmd : public ECCommand
{
public:
    ECCreateGroupCmd(ECGraphicDoc &docIn, ECCompShape* r) : doc(docIn), r(r){};
    ~ECCreateGroupCmd(){};
    virtual void Execute();
    virtual void UnExecute();

private:
    ECGraphicDoc &doc;
    ECCompShape* r;
};

class ECRemoveGroupCmd : public ECCommand
{
public:
    ECRemoveGroupCmd(ECGraphicDoc &docIn, ECCompShape* r) : doc(docIn), r(r){};
    ~ECRemoveGroupCmd(){};
    virtual void Execute();
    virtual void UnExecute();

private:
    ECGraphicDoc &doc;
    ECCompShape* r;
};

class ECMoveGroupCmd : public ECCommand
{
public:
    ECMoveGroupCmd(ECGraphicDoc &docIn, ECCompShape* r, int x, int y) : doc(docIn), r(r), xfactor(x), yfactor(y){};
    ~ECMoveGroupCmd(){};
    virtual void Execute();
    virtual void UnExecute();

private:
    ECGraphicDoc &doc;
    ECCompShape* r;
    int xfactor;
    int yfactor;
};

class ECCreateShapeCmd : public ECCommand
{
public:
    ECCreateShapeCmd(ECGraphicDoc &docIn, ECShape r) : doc(docIn), r(r){};
    ~ECCreateShapeCmd(){};
    virtual void Execute();
    virtual void UnExecute();

private:
    ECGraphicDoc &doc;
    ECShape r;
};

class ECRemoveShapeCmd : public ECCommand
{
public:
    ECRemoveShapeCmd(ECGraphicDoc &docIn, ECShape r) : doc(docIn), r(r){};
    ~ECRemoveShapeCmd(){};
    virtual void Execute();
    virtual void UnExecute();

private:
    ECGraphicDoc &doc;
    ECShape r;
};

class ECMoveShapeCmd : public ECCommand
{
public:
    ECMoveShapeCmd(ECGraphicDoc &docIn, ECShape r, int x, int y) : doc(docIn), r(r), xfactor(x), yfactor(y){};
    ~ECMoveShapeCmd(){};
    virtual void Execute();
    virtual void UnExecute();

private:
    ECGraphicDoc &doc;
    ECShape r;
    int xfactor;
    int yfactor;
};

// Add other commands

class ECGraphicDocCtrl
{
public:
    ECGraphicDocCtrl(ECGraphicDoc &docIn) : doc(docIn){};
    virtual ~ECGraphicDocCtrl(){};
    void AddShape(int x1, int y1, int x2, int y2, int shapeType, int fill);
    void RemoveShape(int x1, int y1, int x2, int y2, int shapeType, int fill);
    void MoveShape(ECShape s, int xfactor, int yfactor);
    void CreateGroup(ECCompShape *r);
    void RemoveGroup(ECCompShape *r);
    void MoveGroup(ECCompShape *r, int xfactor, int yfactor);
    bool Undo();
    bool Redo();

private:
    ECGraphicDoc &doc;
    ECCommandHistory histCmds;
};

class ECGraphicDoc
{
public:
    ECGraphicDoc(ECGraphicViewImp *view) : view(view), docCtrl(*this){};
    ECGraphicDocCtrl &getCtrl() { return docCtrl; };
    virtual ~ECGraphicDoc(){};
    void AddShape(ECShape r);
    void RemoveShape(ECShape r);
    void MoveShape(ECShape r, int xfactor, int yfactor);
    void CreateGroup(ECCompShape* r);
    void RemoveGroup(ECCompShape* r);
    void MoveGroup(ECCompShape* r, int xfactor, int yfactor);
    vector<ECShape> GetListShapes() { return listShapes; };

private:
    ECGraphicViewImp *view;
    ECGraphicDocCtrl docCtrl;
    vector<ECShape> listShapes;
};

#endif