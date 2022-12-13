#include "ECGraphicCtrl.h"
#include "ECGraphicViewImp.h"
#include "ECCommand.h"
#include <cmath>
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
    mode;
    ;
    _subject->Attach(this);
}

MouseEvObserver ::~MouseEvObserver()
{
    _subject->Detach(this);
}

void MouseEvObserver ::Update()
{
    ECGVEventType event = _subject->GetCurrEvent();
    // Change mode
    if (event == ECGV_EV_KEY_DOWN_SPACE)
    {
        mode++;
    }
    // Change shape
    if (event == ECGV_EV_KEY_DOWN_G)
    {
        shapeType++;
    }

    // Change fill
    if (event == ECGV_EV_KEY_DOWN_F)
    {
        fill++;
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
                if (shapes[i].GetShapeType() % 2 == 0 && ((x1 <= shapes[i].Getx1() && y1 <= shapes[i].Gety1() && x1 >= shapes[i].Getx2() && y1 >= shapes[i].Gety2()) ||
                                                          (x1 >= shapes[i].Getx1() && y1 >= shapes[i].Gety1() && x1 <= shapes[i].Getx2() && y1 <= shapes[i].Gety2()) ||
                                                          (x1 >= shapes[i].Getx1() && y1 <= shapes[i].Gety1() && x1 <= shapes[i].Getx2() && y1 >= shapes[i].Gety2()) ||
                                                          (x1 <= shapes[i].Getx1() && y1 >= shapes[i].Gety1() && x1 >= shapes[i].Getx2() && y1 <= shapes[i].Gety2())))
                {
                    pos = i;
                    selected = true;
                    break;
                }
                else if (shapes[i].GetShapeType() % 2 == 1 &&
                         (pow((x1 - shapes[i].Getx1()), 2) + pow((y1 - shapes[i].Gety1()), 2) <= pow((shapes[i].Getx2() - shapes[i].Getx1()), 2) ||
                          pow((x1 - shapes[i].Getx2()), 2) + pow((y1 - shapes[i].Gety2()), 2) <= pow((shapes[i].Getx2() - shapes[i].Getx1()), 2) ||
                          pow((x1 - shapes[i].Getx1()), 2) + pow((y1 - shapes[i].Gety2()), 2) <= pow((shapes[i].Getx2() - shapes[i].Getx1()), 2) ||
                          pow((x1 - shapes[i].Getx2()), 2) + pow((y1 - shapes[i].Gety1()), 2) <= pow((shapes[i].Getx2() - shapes[i].Getx1()), 2)))
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
                if (shapes[pos].GetShapeType() % 2 == 0)
                {
                    moving = true;
                    _subject->GetCursorPosition(x2, y2);
                    ECShape shape = shapes[pos];
                    if (shape.GetFill() % 2 == 0)
                    {
                        _subject->DrawRectangle(shape.Getx1() + (x2 - x1), shape.Gety1() + (y2 - y1), shape.Getx2() + (x2 - x1), shape.Gety2() + (y2 - y1));
                    }
                    else
                    {
                        _subject->DrawFilledRectangle(shape.Getx1() + (x2 - x1), shape.Gety1() + (y2 - y1), shape.Getx2() + (x2 - x1), shape.Gety2() + (y2 - y1));
                    }
                }
                else
                {
                    moving = true;
                    _subject->GetCursorPosition(x2, y2);
                    ECShape shape = shapes[pos];
                    if (shape.GetFill() % 2 == 0)
                    {
                        _subject->DrawEllipse(shape.Getx1() + (x2 - x1), shape.Gety1() + (y2 - y1), shape.Getx2(), shape.Gety2());
                    }
                    else
                    {
                        _subject->DrawFilledEllipse(shape.Getx1() + (x2 - x1), shape.Gety1() + (y2 - y1), shape.Getx2(), shape.Gety2());
                    }
                }
            }
        }

        if (event == ECGV_EV_KEY_DOWN_D)
        {
            if (selected)
            {
                ctrl->RemoveShape(shapes[pos].Getx1(), shapes[pos].Gety1(), shapes[pos].Getx2(), shapes[pos].Gety2(), shapes[pos].GetShapeType(), shapes[pos].GetFill());
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
            if (shapeType % 2 == 0)
            {
                clicked = false;
                _subject->GetCursorPosition(x2, y2);
                ctrl->AddShape(x1, y1, x2, y2, 0, fill % 2);
            }
            else
            {
                clicked = false;
                _subject->GetCursorPosition(x2, y2);
                ctrl->AddShape(x1, y1, abs(x2 - x1) / 2, abs(y2 - y1) / 2, 1, fill % 2);
            }
        }

        if (event == ECGV_EV_TIMER)
        {
            if (clicked)
            {
                if (shapeType % 2 == 0)
                {
                    _subject->GetCursorPosition(x2, y2);
                    if (fill % 2 == 0)
                    {
                        _subject->DrawRectangle(x1, y1, x2, y2);
                    }
                    else
                    {
                        _subject->DrawFilledRectangle(x1, y1, x2, y2);
                    }
                }
                else
                {
                    _subject->GetCursorPosition(x2, y2);
                    if (fill % 2 == 0)
                    {
                        _subject->DrawEllipse(x1, y1, abs(x2 - x1) / 2, abs(y2 - y1) / 2);
                    }
                    else
                    {
                        _subject->DrawFilledEllipse(x1, y1, abs(x2 - x1) / 2, abs(y2 - y1) / 2);
                    }
                }
            }
        }
    }

    if (event == ECGV_EV_TIMER)
    {
        vector<ECShape> shapes = doc->GetListShapes();
        for (int i = 0; i < shapes.size(); i++)
        {
            if (shapes[i].GetShapeType() == 0)
            {
                if (shapes[i].GetFill() % 2 == 0)
                {
                    if (moving && i == pos)
                        _subject->DrawRectangle(shapes[i].Getx1(), shapes[i].Gety1(), shapes[i].Getx2(), shapes[i].Gety2(), 3, ECGV_NONE);
                    else if (i == pos)
                        _subject->DrawRectangle(shapes[i].Getx1(), shapes[i].Gety1(), shapes[i].Getx2(), shapes[i].Gety2(), 3, ECGV_BLUE);
                    else
                        _subject->DrawRectangle(shapes[i].Getx1(), shapes[i].Gety1(), shapes[i].Getx2(), shapes[i].Gety2());
                }
                else
                {
                    if (moving && i == pos)
                        _subject->DrawFilledRectangle(shapes[i].Getx1(), shapes[i].Gety1(), shapes[i].Getx2(), shapes[i].Gety2(), ECGV_NONE);
                    else if (i == pos)
                        _subject->DrawFilledRectangle(shapes[i].Getx1(), shapes[i].Gety1(), shapes[i].Getx2(), shapes[i].Gety2(), ECGV_BLUE);
                    else
                        _subject->DrawFilledRectangle(shapes[i].Getx1(), shapes[i].Gety1(), shapes[i].Getx2(), shapes[i].Gety2());
                }
            }
            else
            {
                if (shapes[i].GetFill() % 2 == 0)
                {
                    if (moving && i == pos)
                        _subject->DrawEllipse(shapes[i].Getx1(), shapes[i].Gety1(), shapes[i].Getx2(), shapes[i].Gety2(), 3, ECGV_NONE);
                    else if (i == pos)
                        _subject->DrawEllipse(shapes[i].Getx1(), shapes[i].Gety1(), shapes[i].Getx2(), shapes[i].Gety2(), 3, ECGV_BLUE);
                    else
                        _subject->DrawEllipse(shapes[i].Getx1(), shapes[i].Gety1(), shapes[i].Getx2(), shapes[i].Gety2());
                }
                else
                {
                    if (moving && i == pos)
                        _subject->DrawFilledEllipse(shapes[i].Getx1(), shapes[i].Gety1(), shapes[i].Getx2(), shapes[i].Gety2(), ECGV_NONE);
                    else if (i == pos)
                        _subject->DrawFilledEllipse(shapes[i].Getx1(), shapes[i].Gety1(), shapes[i].Getx2(), shapes[i].Gety2(), ECGV_BLUE);
                    else
                        _subject->DrawFilledEllipse(shapes[i].Getx1(), shapes[i].Gety1(), shapes[i].Getx2(), shapes[i].Gety2());
                }
            }
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
    if (r.GetShapeType() % 2 == 0)
    {
        x1 = r.Getx1() + xfactor;
        y1 = r.Gety1() + yfactor;
        x2 = r.Getx2() + xfactor;
        y2 = r.Gety2() + yfactor;
    }
    else
    {
        x1 = r.Getx1() + xfactor;
        y1 = r.Gety1() + yfactor;
        x2 = r.Getx2();
        y2 = r.Gety2();
    }
    ECShape newShape(x1, y1, x2, y2, r.GetShapeType(), r.GetFill());
    doc.RemoveShape(newShape);
    doc.AddShape(r);
}

//***********************************************************************
// Graphic Document Controller

void ECGraphicDocCtrl ::AddShape(int x1, int y1, int x2, int y2, int shapeType, int fill)
{
    ECShape shape(x1, y1, x2, y2, shapeType, fill);
    ECCreateShapeCmd *pCmdShape = new ECCreateShapeCmd(doc, shape);
    histCmds.ExecuteCmd(pCmdShape);
}

void ECGraphicDocCtrl ::RemoveShape(int x1, int y1, int x2, int y2, int shapeType, int fill)
{
    ECShape shape(x1, y1, x2, y2, shapeType, fill);
    ECRemoveShapeCmd *pCmdRemove = new ECRemoveShapeCmd(doc, shape);
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
    if (r.GetShapeType() % 2 == 0)
    {
        x1 = r.Getx1() + xfactor;
        y1 = r.Gety1() + yfactor;
        x2 = r.Getx2() + xfactor;
        y2 = r.Gety2() + yfactor;
    }
    else
    {
        x1 = r.Getx1() + xfactor;
        y1 = r.Gety1() + yfactor;
        x2 = r.Getx2();
        y2 = r.Gety2();
    }
    ECShape newShape(x1, y1, x2, y2, r.GetShapeType(), r.GetFill());
    listShapes[pos] = newShape;
}
