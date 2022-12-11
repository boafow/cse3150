//
//  Created by Yufeng Wu on 3/2/22.
//
#include "ECGraphicViewImp.h"
#include "ECGraphicCtrl.h"

// Test graphical view code
int real_main(int argc, char **argv)
{ 
  ECGraphicViewImp *view = new ECGraphicViewImp(500, 500);
  ECGraphicDoc doc = ECGraphicDoc(view);
  ECGraphicDocCtrl &docCtrl = doc.getCtrl();
  KeystrokeObserver keys = KeystrokeObserver(view, docCtrl);
  MouseEvObserver mouse = MouseEvObserver(view, docCtrl, doc);
  view->Show();
  
  return 0;
}

int main(int argc, char **argv)
{
    return real_main(argc, argv);
    //return al_run_main(argc, argv, real_main);
}

