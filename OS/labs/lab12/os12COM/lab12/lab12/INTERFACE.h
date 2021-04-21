#pragma once
#include <objbase.h>
#define FNAME L"Llh.OS_12.COM"
#define VINDX L"Llh.OS_12.1"
#define PRGID L"Llh.OS_12"

// {EF946480-2FD4-4879-81FF-899B4B6D002D}
static const GUID CLSID_CA =
{ 0xef946480, 0x2fd4, 0x4879, { 0x81, 0xff, 0x89, 0x9b, 0x4b, 0x6d, 0x0, 0x2d } };

// {96E1329E-6512-4512-96AD-CB2DD57A0744}
static const GUID IID_IAdder =
{ 0x96e1329e, 0x6512, 0x4512, { 0x96, 0xad, 0xcb, 0x2d, 0xd5, 0x7a, 0x7, 0x44 } };
interface IAdder :IUnknown {
	STDMETHOD(Add(const double x,const double y,double& z)) PURE;
	STDMETHOD(Sub(const double x,const double y,double& z)) PURE;
};

// {21CCE562-4B5B-4159-8B71-24DA1D177944}
static const GUID IID_IMultiplier =
{ 0x21cce562, 0x4b5b, 0x4159, { 0x8b, 0x71, 0x24, 0xda, 0x1d, 0x17, 0x79, 0x44 } };
interface IMultiplier :IUnknown {
	STDMETHOD(Mul(const double x,const double y,double& z)) PURE;
	STDMETHOD (Div(const double x,const double y,double& z)) PURE;
};
