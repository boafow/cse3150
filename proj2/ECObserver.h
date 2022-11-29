#ifndef ECOBERVER_H
#define ECOBERVER_H

#include <vector>
#include <algorithm>
#include <iostream>
//********************************************
// Command design pattern: command interface
class ECGraphicModelImp;
class ECCommand
{
public:
    virtual void Execute() = 0;
    virtual void Unexecute() = 0;
};

class MouseDownCommand : public ECCommand
{
public:
    MouseDownCommand(ECGraphicModelImp &model);
    virtual ~MouseDownCommand(){};
    void Execute();
    void Unexecute();

private:
    ECGraphicModelImp &model;
    int x1, y1;
};

class MouseUpCommand : public ECCommand
{
public:
    MouseUpCommand(ECGraphicModelImp &model);
    virtual ~MouseUpCommand(){};
    void Execute();
    void Unexecute();

private:
    ECGraphicModelImp &model;
};

class MouseMoveCommand : public ECCommand
{
public:
    MouseMoveCommand(ECGraphicModelImp &model);
    virtual ~MouseMoveCommand(){};
    void Execute();
    void Unexecute();

private:
    ECGraphicModelImp &model;
};

class KeyDownCommand : public ECCommand
{
public:
    KeyDownCommand(ECGraphicModelImp &model);
    virtual ~KeyDownCommand(){};
    void Execute();
    void Unexecute();

private:
    ECGraphicModelImp &model;
};

class KeyUpCommand : public ECCommand
{
public:
    KeyUpCommand(ECGraphicModelImp &model);
    virtual ~KeyUpCommand(){};
    void Execute();
    void Unexecute();

private:
    ECGraphicModelImp &model;
};

// Command design pattern: command history
class ECCommandHistory
{
public:
    ECCommandHistory() : currCmdIndex(-1) {}
    ~ECCommandHistory();
    void AddCommand(ECCommand *cmd);
    bool Undo();
    bool Redo();
    void ExecuteCmd(ECCommand *cmd);

private:
    std::vector<ECCommand *> cmdHistory;
    int currCmdIndex;
};

//********************************************
// Observer design pattern: observer interface

class ECObserverSubject;
// class ECGraphicViewImp;

class ECObserver
{
public:
    virtual ~ECObserver() {}
    virtual void Update() = 0;
};

class ECMouseDownObserver : public ECObserver
{
    ECObserverSubject *view;
    // ECGraphicViewImp *viewImp;

public:
    ECMouseDownObserver(ECObserverSubject *view);
    virtual ~ECMouseDownObserver() {}
    virtual void Update();
};

class ECMouseUpObserver : public ECObserver
{
    ECObserverSubject *view;

public:
    ECMouseUpObserver(ECObserverSubject *view);
    virtual ~ECMouseUpObserver() {}
    virtual void Update();
};

class ECMouseMoveObserver : public ECObserver
{
    ECObserverSubject *view;

public:
    ECMouseMoveObserver(ECObserverSubject *view);
    virtual ~ECMouseMoveObserver() {}
    virtual void Update();
};

class ECKeyDownObserver : public ECObserver
{
    ECObserverSubject *view;

public:
    ECKeyDownObserver(ECObserverSubject *view);
    virtual ~ECKeyDownObserver() {}
    virtual void Update();
};

class ECKeyUpObserver : public ECObserver
{
    ECObserverSubject *view;

public:
    ECKeyUpObserver(ECObserverSubject *view);
    virtual ~ECKeyUpObserver() {}
    virtual void Update();
};

//********************************************
// MVC Design Pattern: Controller
class ECGraphicControllerImp
{
public:
    ECGraphicControllerImp(ECGraphicModelImp &model);
    virtual ~ECGraphicControllerImp(){};

private:
    ECGraphicModelImp &model;
    ECCommandHistory cmdHistory;
};

//********************************************
// MVC design pattern: Model
class ECGraphicModelImp
{
public:
    ECGraphicModelImp();
    virtual ~ECGraphicModelImp() {}
    ECGraphicControllerImp &GetController() { return ctrl; }
    void SetX1(int x1) { this->x1 = x1; }
    void SetY1(int y1) { this->y1 = y1; }
    void SetX2(int x2) { this->x2 = x2; }
    void SetY2(int y2) { this->y2 = y2; }
    int GetX1() const { return x1; }
    int GetY1() const { return y1; }
    int GetX2() const { return x2; }
    int GetY2() const { return y2; }
private:
    int x1, y1, x2, y2;
    ECGraphicControllerImp ctrl;
};

//********************************************
// Observer design pattern: subject

class ECObserverSubject
{
public:
    ECObserverSubject();
    virtual ~ECObserverSubject() {}
    void Attach(ECObserver *pObs)
    {
        // std::cout << "Adding an observer.\n";
        listObservers.push_back(pObs);
    }
    void Detach(ECObserver *pObs)
    {
        listObservers.erase(std::remove(listObservers.begin(), listObservers.end(), pObs), listObservers.end());
    }
    void Notify()
    {
        // std::cout << "Notify: number of observer: " << listObservers.size() << std::endl;
        for (unsigned int i = 0; i < listObservers.size(); ++i)
        {
            listObservers[i]->Update();
        }
    }

private:
    std::vector<ECObserver *> listObservers;
};

#endif
