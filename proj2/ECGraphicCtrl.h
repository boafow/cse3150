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
//Mouse observer

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
    int mode; // 0 = insertion, 1 = edit
    bool clicked = false;
    ECGraphicDocCtrl *ctrl;
    int pos = -1;
    bool selected = false;
    bool moving = false;
};


class ECShape
{
public:
    ECShape(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {};
    int Getx1() {return x1;}
    int Gety1() {return y1;}
    int Getx2() {return x2;} 
    int Gety2() {return y2;}
    
private:
    int x1=0;
    int y1=0;
    int x2=0;
    int y2=0;
};

class ECCreateShapeCmd : public ECCommand
{
public:
    ECCreateShapeCmd(ECGraphicDoc &docIn, ECShape r) : doc(docIn), r(r) {};
    ~ECCreateShapeCmd() {};
    virtual void Execute();
    virtual void UnExecute();
private:
    ECGraphicDoc &doc;
    ECShape r;
};

class ECRemoveShapeCmd : public ECCommand
{
public:
    ECRemoveShapeCmd(ECGraphicDoc &docIn, ECShape r) : doc(docIn), r(r) {};
    ~ECRemoveShapeCmd() {};
    virtual void Execute();
    virtual void UnExecute();

private:
    ECGraphicDoc &doc;
    ECShape r;
};

class ECMoveShapeCmd : public ECCommand
{
public:
    ECMoveShapeCmd(ECGraphicDoc &docIn, ECShape r, int x, int y) : doc(docIn), r(r), xfactor(x), yfactor(y) {};
    ~ECMoveShapeCmd() {};
    virtual void Execute();
    virtual void UnExecute();

private:
    ECGraphicDoc &doc;
    ECShape r;
    int xfactor;
    int yfactor;
};

//Add other commands

class ECGraphicDocCtrl
{
public:
    ECGraphicDocCtrl(ECGraphicDoc &docIn) : doc(docIn) {};
    virtual ~ECGraphicDocCtrl() {};
    void AddShape(int x1, int y1, int x2, int y2);
    void RemoveShape(int x1, int y1, int x2, int y2);
    void MoveShape(ECShape s, int xfactor, int yfactor);
    bool Undo();
    bool Redo();

private:
    ECGraphicDoc &doc;
    ECCommandHistory histCmds;
};

class ECGraphicDoc
{
public:
    ECGraphicDoc(ECGraphicViewImp *view) : view(view), docCtrl(*this) {};
    ECGraphicDocCtrl &getCtrl() {return docCtrl;};
    virtual ~ECGraphicDoc() {};
    void AddShape(ECShape r);
    void RemoveShape(ECShape r);
    void MoveShape(ECShape r, int xfactor, int yfactor);
    vector<ECShape> GetListShapes() {return listShapes;};

private:
    ECGraphicViewImp *view;
    ECGraphicDocCtrl docCtrl;
    vector<ECShape> listShapes;
};

#endif