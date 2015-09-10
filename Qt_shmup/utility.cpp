#include "utility.h"

Utility::Utility()
{

}

int Utility::priceOfWeapon(int w)
{
    switch(w)
    {
    case 1:
        return 20;
        break;
    case 2:
        return 60;
        break;
    case 3:
        return 110;
        break;
    }
}

