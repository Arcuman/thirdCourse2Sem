#pragma once
#include <objbase.h>

#define FNAME L"Bor.CA.COM"
#define VINDX L"Bor.CA.1"
#define PRGID L"Bor.CA"

// {692C66D0-3CE5-4512-A311-782618DBC7A6}
static const GUID CLSID_CA =
{ 0x692c66d0, 0x3ce5, 0x4512, { 0xa3, 0x11, 0x78, 0x26, 0x18, 0xdb, 0xc7, 0xa6 } };

// {E5C68A2D-067F-4240-9DBD-FE4E4A0AA66C}
static const GUID IID_IAdder =
{ 0xe5c68a2d, 0x67f, 0x4240, { 0x9d, 0xbd, 0xfe, 0x4e, 0x4a, 0xa, 0xa6, 0x6c } };

interface IAdder :IUnknown {
    STDMETHOD(Add(const double, const double, double*)) PURE;
    STDMETHOD(Sub(const double, const double, double*)) PURE;
};

// {E5850B11-565C-4812-A8C9-3B62CC6EEC9A}
static const GUID IID_IMultiplier =
{ 0xe5850b11, 0x565c, 0x4812, { 0xa8, 0xc9, 0x3b, 0x62, 0xcc, 0x6e, 0xec, 0x9a } };

interface IMultiplier :IUnknown {
    STDMETHOD(Mul(const double, const double, double*))  PURE;
    STDMETHOD(Div(const double, const double,  double*)) PURE;
};
