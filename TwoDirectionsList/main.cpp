#include <iostream>
#include "tdlist.h"

using namespace std;

int main()
{
    TDList list;

    list.pushFront(1);
    list.pushFront(3);
    list.pushBack(0);
    list.pushFront(3);
    list.pushBack(1);
    list.removeElementAtIndex(1);

    for (int i = 0; i<4; ++i)
    {
        cout<<list.getValueAtIndex(i)<<endl;
    }

    return 0;
}
