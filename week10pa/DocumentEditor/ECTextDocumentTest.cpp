#include <iostream>
#include "ECTextDocument.h"

using namespace std;

static void Test1()
{
    //
    ECTextDocument doc;
    ECTextDocumentCtrl &docCtrl = doc.GetCtrl();
    vector<char> listText1;
    listText1.push_back('a');
    listText1.push_back('b');
    listText1.push_back('c');
    listText1.push_back('d');
    listText1.push_back('E');
    docCtrl.InsertTextAt(0, listText1);
    vector<char> listText2;
    listText2.push_back('f');
    listText2.push_back('g');
    listText2.push_back('h');
    int posIns = 2;
    docCtrl.InsertTextAt(posIns, listText2);
    int lenDel = 2;
    docCtrl.RemoveTextAt(posIns, lenDel);
    int posCap = 2;
    int lenCap = 1;
    docCtrl.CapTextAt(posCap, lenCap);
    int posLow = 2;
    int lenLow = 1;
    docCtrl.LowerTextAt(posLow, lenLow);

    cout << "Text: ";
    for (int i = 0; i < doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;

    // try undo/redo
    docCtrl.Undo();
    docCtrl.Undo();

    docCtrl.Undo();

    docCtrl.Undo();

    docCtrl.Undo();

    cout << "After undo, text: ";
    for (int i = 0; i < doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;

    docCtrl.Redo();
    cout << "After redo, text: ";
    for (int i = 0; i < doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
}

int main()
{
    // test code
    Test1();

    return 0;
}
