#include "LinkedList.cpp"

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
   LinkedList<int> list;

   list.append(1);
   list.append(2);
   list.prepend(5);
   list.prepend(4);
   list.prepend(4);
   list.prepend(4);

   list.removeByPosition(0);
   list.removeByValue(4);
   list.insertByPosition(2, 7);

   list.ascendingSort();
   list.reverse();

   list.display();
}