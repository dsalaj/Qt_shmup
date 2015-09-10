#include "utility.h"

Utility::Utility()
{

}

int Utility::priceOfWeapon(int w)
{
    // FIXME: move magic numbers to constants
    switch(w)
    {
    case 1:
        return 20;
        break;
    case 2:
        return 70;
        break;
    case 3:
        return 110;
        break;
    }
}

