#include "stdafx.h"
#include "Interface.h"

bool RootLogin(const char * password)
{
    if (nullptr==rootHelper)
    {
        rootHelper = new RootHelper();
    }
    return rootHelper->Login(password);
}
