#pragma once
#include "RootHelper.h"

RootHelper* rootHelper = nullptr;

extern "C" bool __declspec(dllexport) RootLogin(const char* password);

extern "C" __declspec(dllexport) int SampleMethod(int i)
{
    return i * 10;
}