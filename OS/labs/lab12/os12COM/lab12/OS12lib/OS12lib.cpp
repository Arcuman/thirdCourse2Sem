// OS12lib.cpp : Определяет функции для статической библиотеки.
//

#pragma once
#include "pch.h"
#include "framework.h"
#include <iostream>
#include "OS12lib.h"
#include <objbase.h>


static const GUID CLSID_CA =
{ 0xef946480, 0x2fd4, 0x4879, { 0x81, 0xff, 0x89, 0x9b, 0x4b, 0x6d, 0x0, 0x2d } };

// {96E1329E-6512-4512-96AD-CB2DD57A0744}
static const GUID IID_IAdder =
{ 0x96e1329e, 0x6512, 0x4512, { 0x96, 0xad, 0xcb, 0x2d, 0xd5, 0x7a, 0x7, 0x44 } };
interface IAdder :IUnknown {
	virtual HRESULT __stdcall Add(
		const double x,
		const double y,
		double& z
	) = 0;
	virtual HRESULT __stdcall Sub(
		const double x,
		const double y,
		double& z
	) = 0;
};

// {21CCE562-4B5B-4159-8B71-24DA1D177944}
static const GUID IID_IMultiplier =
{ 0x21cce562, 0x4b5b, 0x4159, { 0x8b, 0x71, 0x24, 0xda, 0x1d, 0x17, 0x79, 0x44 } };
interface IMultiplier :IUnknown {
	virtual HRESULT __stdcall Mul(
		const double x,
		const double y,
		double& z
	) = 0;
	virtual HRESULT __stdcall Div(
		const double x,
		const double y,
		double& z
	) = 0;
};


// TODO: Это пример библиотечной функции.
void fnOS12lib() {
	std::cout << "hello from lib";
}


IAdder* pIAdder = nullptr;
IMultiplier* pMultiplier = nullptr;

OS12HANDEL OS12::Init() {
	IUnknown* pIUnknown = NULL;
	CoInitialize(NULL);                        // инициализация библиотеки OLE32
	HRESULT hr0 = CoCreateInstance(CLSID_CA, NULL, CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pIUnknown);
	if (SUCCEEDED(hr0))
	{
		return pIUnknown;
	}
	else {
		throw (int)hr0;
		return NULL;
	}
}


void OS12::Dispose(OS12HANDEL h) {
	((IUnknown * )h)->Release();
	CoFreeUnusedLibraries();
}


double OS12::Adder::Add(OS12HANDEL h, double x, double y)
{
	double result = 0.0;
	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IAdder, (void**)&pIAdder);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pIAdder->Add(x, y, result);
		if (!SUCCEEDED(hr1)) {
			pIAdder->Release();
			throw (int)hr1;
			return -1;
		}
		else {
			pIAdder->Release();
			return result;
		}
	}
	else {

		throw (int)hr0;
		return -1;
	}
}
// return x+y
//  if QueryInteface(IID_IAdder) != succesfull -->  throw (int)HRESULT   


double OS12::Adder::Sub(OS12HANDEL h, double x, double y)
{
	double result = 0.0;
	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IAdder, (void**)&pIAdder);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pIAdder->Sub(x, y, result);
		if (!SUCCEEDED(hr1)) {
			pIAdder->Release();
			throw (int)hr1;
			return -1;
		}
		else {
			pIAdder->Release();
			return result;
		}
	}
	else {

		throw (int)hr0;
		return -1;
	}
}
// return x-y
//  if QueryInteface(IID_IAdder) != succesfull -->  throw (int)HRESULT



double OS12::Multiplier::Mul(OS12HANDEL h, double x, double y)
{
	double result = 0.0;
	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IMultiplier, (void**)&pMultiplier);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pMultiplier->Mul(x, y, result);
		if (!SUCCEEDED(hr1)) {
			pMultiplier->Release();
			throw (int)hr1;
			return -1;
		}
		else {
			pMultiplier->Release();
			return result;
		}
	}
	else {

		throw (int)hr0;
		return -1;
	}
}
// return x*y
//  if QueryInteface(IID_IMultiplier) != succesfull -->  throw (int)HRESULT 
double OS12::Multiplier::Div(OS12HANDEL h, double x, double y)
{
	if (y == 0) {
		throw 0;
	}
	double result = 0.0;
	HRESULT hr0 = ((IUnknown*)h)->QueryInterface(IID_IMultiplier, (void**)&pMultiplier);
	if (SUCCEEDED(hr0))
	{
		HRESULT hr1 = pMultiplier->Div(x, y, result);
		if (!SUCCEEDED(hr1)) {
			pMultiplier->Release();
			throw (int)hr1;
			return -1;
		}
		else {
			pMultiplier->Release();
			return result;
		}
	}
	else {

		throw (int)hr0;
		return -1;
	}
}
// return x/y
//  if QueryInteface(IID_IMultiplier) != succesfull -->  throw (int)HRESULT 