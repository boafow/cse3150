//
//  Created by Yufeng Wu on 3/2/22.
//
#include "ECGraphicViewImp.h"
#include "ECGraphicCtrl.h"
#include <iostream>
#include <fstream>
#include <string>
// Test graphical view code
int real_main(int argc, char **argv)
{
  // if a file is passed in, open it

  ECGraphicViewImp *view = new ECGraphicViewImp(500, 500);
  ECGraphicDoc doc = ECGraphicDoc(view);
  ECGraphicDocCtrl &docCtrl = doc.getCtrl();
  KeystrokeObserver keys = KeystrokeObserver(view, docCtrl);
  MouseEvObserver mouse = MouseEvObserver(view, docCtrl, doc);
  if (argc > 1)
  {
    // open file
    string line;
    char ch;
    ifstream loadfile(argv[1]);
    // number of shapes in file is first number or first line in file
    loadfile.get(ch);
    cout << ch << endl;
    loadfile.get(ch);
    cout << ch << endl;

    while (getline(loadfile, line))
    {
      cout << line << endl;
      if (line.size() == 4)
      {
      }
      else
      {
        // convert string of numbers separated by spaces to vector of ints
        vector<int> shapeInfo;
        int i = 0;
        while (i < line.size())
        {
          string num = "";
          while (line[i] != ' ')
          {
            num += line[i];
            i++;
          }
          shapeInfo.push_back(stoi(num));
          i++;
        }
        if (shapeInfo.size() == 6)
        {
          docCtrl.AddShape(shapeInfo[1], shapeInfo[2], shapeInfo[3], shapeInfo[4], 1, shapeInfo[5]);
        }
        if (shapeInfo.size() == 11)
        {
          docCtrl.AddShape(shapeInfo[2], shapeInfo[3], shapeInfo[8], shapeInfo[9], 0, shapeInfo[10]);
        }
      }
    }
  }
  view->Show();
  return 0;
}

int main(int argc, char **argv)
{
  return real_main(argc, argv);
  // return al_run_main(argc, argv, real_main);
}
