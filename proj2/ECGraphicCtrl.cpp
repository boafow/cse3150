#include "ECGraphicCtrl.h"
#include "ECGraphicViewImp.h"
#include "ECCommand.h"
//*************************************************************************************************
// Keystroke observer
KeystrokeObserver ::KeystrokeObserver(ECGraphicViewImp *view, ECGraphicDocCtrl &ctrl) : ctrl(&ctrl)
{
    _subject = view;
    _subject->Attach(this);
}

KeystrokeObserver ::~KeystrokeObserver()
{
    _subject->Detach(this);
}

void KeystrokeObserver ::Update()
{
    ECGVEventType event = _subject->GetCurrEvent();
    if (event == ECGV_EV_KEY_DOWN_Z)
    {
        ctrl->Undo();
    }
    if (event == ECGV_EV_KEY_DOWN_Y)
    {
        ctrl->Redo();
    }
    if (event == ECGV_EV_KEY_DOWN_D)
    {
        // delete
    }
}

//************************************************************************************************************
// mouse event cobserver

MouseEvObserver ::MouseEvObserver(ECGraphicViewImp *view, ECGraphicDocCtrl &ctrl, ECGraphicDoc &docIn) : ctrl(&ctrl), doc(&docIn)
{
    _subject = view;
    mode = 0;
    _subject->Attach(this);
}

MouseEvObserver ::~MouseEvObserver()
{
    _subject->Detach(this);
}

void MouseEvObserver ::Update()
{
    ECGVEventType event = _subject->GetCurrEvent();

    if (event == ECGV_EV_KEY_DOWN_SPACE)
    {
        mode++;
    }
    // EDITING MODE
    if (mode % 2 == 1)
    {
        vector<ECShape> shapes = doc->GetListShapes();
        if (event == ECGV_EV_MOUSE_BUTTON_DOWN)
        {
            _subject->GetCursorPosition(x1, y1);
            clicked = true;
            for (int i = 0; i < shapes.size(); i++)
            {
                if ((x1 <= shapes[i].Getx1() && y1 <= shapes[i].Gety1() && x1 >= shapes[i].Getx2() && y1 >= shapes[i].Gety2()) ||
                    (x1 >= shapes[i].Getx1() && y1 >= shapes[i].Gety1() && x1 <= shapes[i].Getx2() && y1 <= shapes[i].Gety2()) ||
                    (x1 >= shapes[i].Getx1() && y1 <= shapes[i].Gety1() && x1 <= shapes[i].Getx2() && y1 >= shapes[i].Gety2()) ||
                    (x1 <= shapes[i].Getx1() && y1 >= shapes[i].Gety1() && x1 >= shapes[i].Getx2() && y1 <= shapes[i].Gety2()))
                {
                    pos = i;
                    selected = true;
                    break;
                }
                else
                {
                    pos = -1;
                    selected = false;
                }
            }
        }
        if (event == ECGV_EV_MOUSE_BUTTON_UP)
        {
            clicked = false;
            moving = false;
            _subject->GetCursorPosition(x2, y2);
            int xfactor = x2 - x1;
            int yfactor = y2 - y1;
            if (selected)
                ctrl->MoveShape(shapes[pos], xfactor, yfactor);
        }

        if (event == ECGV_EV_TIMER)
        {
            if (clicked && selected)
            {
                moving = true;
                _subject->GetCursorPosition(x2, y2);
                ECShape shape = shapes[pos];
                _subject->DrawRectangle(shape.Getx1() + (x2 - x1), shape.Gety1() + (y2 - y1), shape.Getx2() + (x2 - x1), shape.Gety2() + (y2 - y1));
            }
        }

        if (event == ECGV_EV_KEY_DOWN_D)
        {
            if (selected)
            {
                ctrl->RemoveShape(shapes[pos].Getx1(), shapes[pos].Gety1(), shapes[pos].Getx2(), shapes[pos].Gety2());
            }
            selected = false;
            pos = -1;
        }
    }

    // INSERTION MODE
    if (mode % 2 == 0)
    {
        pos = -1;
        selected = false;
        if (event == ECGV_EV_MOUSE_BUTTON_DOWN)
        {
            if (!clicked)
            {
                _subject->GetCursorPosition(x1, y1);
                clicked = true;
            }
        }

        if (event == ECGV_EV_MOUSE_BUTTON_UP)
        {
            clicked = false;
            _subject->GetCursorPosition(x2, y2);
            ctrl->AddShape(x1, y1, x2, y2);
        }

        if (event == ECGV_EV_TIMER)
        {
            if (clicked)
            {
                _subject->GetCursorPosition(x2, y2);
                _subject->DrawRectangle(x1, y1, x2, y2);
            }
        }
    }

    if (event == ECGV_EV_TIMER)
    {
        vector<ECShape> shapes = doc->GetListShapes();
        for (int i = 0; i < shapes.size(); i++)
        {
            if (moving && i == pos)
                _subject->DrawRectangle(shapes[i].Getx1(), shapes[i].Gety1(), shapes[i].Getx2(), shapes[i].Gety2(), 3, ECGV_NONE);
            else if (i == pos)
                _subject->DrawRectangle(shapes[i].Getx1(), shapes[i].Gety1(), shapes[i].Getx2(), shapes[i].Gety2(), 3, ECGV_BLUE);
            else
                _subject->DrawRectangle(shapes[i].Getx1(), shapes[i].Gety1(), shapes[i].Getx2(), shapes[i].Gety2());
        }
        _subject->SetRedraw(true);
    }
}

//**************************************************************************
// Create Shape Command

void ECCreateShapeCmd ::Execute()
{
    doc.AddShape(r);
}

void ECCreateShapeCmd ::UnExecute()
{
    doc.RemoveShape(r);
}

//*************************************************************************************
// Remove Shape Command

void ECRemoveShapeCmd ::Execute()
{
    doc.RemoveShape(r);
}

void ECRemoveShapeCmd ::UnExecute()
{
    doc.AddShape(r);
}

//*******************************************************************************************
// Move Shape Command

void ECMoveShapeCmd ::Execute()
{

    doc.MoveShape(r, xfactor, yfactor);
}

void ECMoveShapeCmd ::UnExecute()
{
    int x1, x2, y1, y2;
    x1 = r.Getx1() + xfactor;
    y1 = r.Gety1() + yfactor;
    x2 = r.Getx2() + xfactor;
    y2 = r.Gety2() + yfactor;
    ECShape newShape(x1, y1, x2, y2);
    doc.RemoveShape(newShape);
    doc.AddShape(r);
}

//***********************************************************************
// Graphic Document Controller

void ECGraphicDocCtrl ::AddShape(int x1, int y1, int x2, int y2)
{
    ECShape rectangle(x1, y1, x2, y2);
    ECCreateShapeCmd *pCmdShape = new ECCreateShapeCmd(doc, rectangle);
    histCmds.ExecuteCmd(pCmdShape);
}

void ECGraphicDocCtrl ::RemoveShape(int x1, int y1, int x2, int y2)
{
    ECShape rectangle(x1, y1, x2, y2);
    ECRemoveShapeCmd *pCmdRemove = new ECRemoveShapeCmd(doc, rectangle);
    histCmds.ExecuteCmd(pCmdRemove);
}

void ECGraphicDocCtrl ::MoveShape(ECShape r, int xfactor, int yfactor)
{
    ECMoveShapeCmd *pCmdMove = new ECMoveShapeCmd(doc, r, xfactor, yfactor);
    histCmds.ExecuteCmd(pCmdMove);
}

bool ECGraphicDocCtrl ::Undo()
{
    return histCmds.Undo();
}

bool ECGraphicDocCtrl ::Redo()
{
    return histCmds.Redo();
}

//***********************************************************************
// Graphic Document

void ECGraphicDoc ::AddShape(ECShape r)
{
    listShapes.push_back(r);
}

void ECGraphicDoc ::RemoveShape(ECShape r)
{
    int _x1, _y1, _x2, _y2, pos;
    _x1 = r.Getx1();
    _y1 = r.Gety1();
    _x2 = r.Getx2();
    _y2 = r.Gety2();

    for (int i = 0; i < listShapes.size(); i++)
    {
        if (_x1 == listShapes[i].Getx1() &&
            _y1 == listShapes[i].Gety1() &&
            _x2 == listShapes[i].Getx2() &&
            _y2 == listShapes[i].Gety2())
        {
            pos = i;
        }
    }
    listShapes.erase(listShapes.begin() + pos);
}

void ECGraphicDoc ::MoveShape(ECShape r, int xfactor, int yfactor)
{
    int _x1, _y1, _x2, _y2, pos;
    _x1 = r.Getx1();
    _y1 = r.Gety1();
    _x2 = r.Getx2();
    _y2 = r.Gety2();

    for (int i = 0; i < listShapes.size(); i++)
    {
        if (_x1 == listShapes[i].Getx1() &&
            _y1 == listShapes[i].Gety1() &&
            _x2 == listShapes[i].Getx2() &&
            _y2 == listShapes[i].Gety2())
        {
            pos = i;
        }
    }

    int x1, x2, y1, y2;
    x1 = r.Getx1() + xfactor;
    y1 = r.Gety1() + yfactor;
    x2 = r.Getx2() + xfactor;
    y2 = r.Gety2() + yfactor;
    ECShape newShape(x1, y1, x2, y2);
    listShapes[pos] = newShape;
}
