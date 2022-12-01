#include "ECObserver.h"
#include "ECGraphicViewImp.h"

ModeObserver::ModeObserver(ECObserverSubject *view)
{
    this->view = view;
    view->Attach(this);
}

DObserver::DObserver(ECObserverSubject *view)
{
    this->view = view;
    view->Attach(this);
}

ZObserver::ZObserver(ECObserverSubject *view)
{
    this->view = view;
    view->Attach(this);
}

YObserver::YObserver(ECObserverSubject *view)
{
    this->view = view;
    view->Attach(this);
}

MouseDownObserver::MouseDownObserver(ECObserverSubject *view)
{
    this->view = view;
    view->Attach(this);
}

MouseUpObserver::MouseUpObserver(ECObserverSubject *view)
{
    this->view = view;
    view->Attach(this);
}

MouseDragObserver::MouseDragObserver(ECObserverSubject *view)
{
    this->view = view;
    view->Attach(this);
}

void ModeObserver::Update()
{
    ECGraphicViewImp *viewImp = dynamic_cast<ECGraphicViewImp *>(view);
    if (viewImp->GetCurrEvent() == ECGV_EV_KEY_DOWN_SPACE)
    {
        std::cout << "mode updated" << std::endl;
    }
}

void DObserver::Update()
{
    ECGraphicViewImp *viewImp = dynamic_cast<ECGraphicViewImp *>(view);
    if (viewImp->GetCurrEvent() == ECGV_EV_KEY_DOWN_D)
    {
        std::cout << "d updated" << std::endl;
    }
}

void ZObserver::Update()
{
    ECGraphicViewImp *viewImp = dynamic_cast<ECGraphicViewImp *>(view);
    if (viewImp->GetCurrEvent() == ECGV_EV_KEY_DOWN_Z)
    {
        std::cout << "z updated" << std::endl;
    }
}

void YObserver::Update()
{
    ECGraphicViewImp *viewImp = dynamic_cast<ECGraphicViewImp *>(view);
    if (viewImp->GetCurrEvent() == ECGV_EV_KEY_DOWN_Y)
    {
        std::cout << "y updated" << std::endl;
    }
}

void MouseDownObserver::Update()
{
    ECGraphicViewImp *viewImp = dynamic_cast<ECGraphicViewImp *>(view);
    if (viewImp->GetCurrEvent() == ECGV_EV_MOUSE_BUTTON_DOWN)
    {
        std::cout << "mouse down updated" << std::endl;
    }
}

void MouseUpObserver::Update()
{
    ECGraphicViewImp *viewImp = dynamic_cast<ECGraphicViewImp *>(view);
    if (viewImp->GetCurrEvent() == ECGV_EV_MOUSE_BUTTON_UP)
    {
        std::cout << "mouse up updated" << std::endl;
    }
}

void MouseDragObserver::Update()
{
    int x, y;
    ECGraphicViewImp *viewImp = dynamic_cast<ECGraphicViewImp *>(view);
    if (viewImp->GetCurrEvent() == ECGV_EV_MOUSE_MOVING){
        viewImp->GetCursorPosition(x, y);
        //cout mouse moving at (x, y)
        std::cout << "mouse moving at ( " << x << " : " << y << " )\n";
    }
}

// observer subject constructor
ECObserverSubject::ECObserverSubject()
{
    // instantiate all observers
    ECObserver *pModeObs = new ModeObserver(this);
    ECObserver *pDObs = new DObserver(this);
    ECObserver *pZObs = new ZObserver(this);
    ECObserver *pYObs = new YObserver(this);
    ECObserver *pMouseDownObs = new MouseDownObserver(this);
    ECObserver *pMouseUpObs = new MouseUpObserver(this);
    ECObserver *pMouseDragObs = new MouseDragObserver(this);
}
