#include "stdafx.h"
#include "Interface.h"

bool AdminLogin(const ID id, const char * name, const char * password)
{
    if (nullptr != uHelper)
    {
        delete uHelper;
    }
    if (nullptr == aHelper)
    {
        aHelper = new AdminHelper();
    }
    if (nullptr != rHelper)
    {
        delete rHelper;
    }
    return aHelper->Login(id, name, password);
}

bool RootLogin(const char * password)
{
    if (nullptr!=uHelper)
    {
        delete uHelper;
    }
    if (nullptr!=aHelper)
    {
        delete aHelper;
    }
    if (nullptr==rHelper)
    {
        rHelper = new RootHelper();
    }
    return rHelper->Login(password);
}

bool ChangeRootPassword(const char * oldpw, const char * newpw)
{
    if (nullptr==rHelper)
    {
        return false;
    }
    return rHelper->ChangePassword(oldpw, newpw);
}

ID AddAdmin(const char * name, const char * password)
{
    if (nullptr == rHelper)
    {
        return 0;
    }
    return rHelper->AddAdmin(name, password);
}
