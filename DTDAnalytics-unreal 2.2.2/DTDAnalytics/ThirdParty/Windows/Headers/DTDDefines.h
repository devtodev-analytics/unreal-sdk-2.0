#pragma once


#ifdef EXPORT_SPEC
#define DLL_SPEC __declspec(dllexport)
#define EXPIMP_TEMPLATE
#else
#define DLL_SPEC __declspec(dllimport)
#define EXPIMP_TEMPLATE extern
#endif