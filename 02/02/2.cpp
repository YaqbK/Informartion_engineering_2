#include <iostream>
#include <vector>
#include "header2.h"

using namespace std;

int main()
{
    Invoice inv(7770003699, 1338745680);
    inv.add_item(Item("M3 screw", 0.37, 'A', 100));
    inv.add_item(Item("2 mm drill", 2.54, 'B', 2));
    return 0;
}


