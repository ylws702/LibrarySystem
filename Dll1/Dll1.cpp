// Dll1.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"



extern "C" __declspec(dllexport) int SampleMethod(int i)
{
    return i * 10;
}