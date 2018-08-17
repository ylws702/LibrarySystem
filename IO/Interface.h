#pragma once
#include "UserHelper.h"
#include "AdminHelper.h"
#include "RootHelper.h"

UserHelper* uHelper = nullptr;
AdminHelper* aHelper = nullptr;
RootHelper* rHelper = nullptr;

extern "C" bool __declspec(dllexport) AdminLogin(const ID id, const char * name, const char * password);
extern "C" bool __declspec(dllexport) RootLogin(const char* password);
extern "C" bool __declspec(dllexport) ChangeRootPassword(const char * oldpw, const char * newpw);
extern "C" ID __declspec(dllexport) AddAdmin(const char * name, const char * password);
