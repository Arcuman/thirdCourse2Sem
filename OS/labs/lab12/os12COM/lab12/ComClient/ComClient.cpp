#include <objbase.h>
#include <iostream>

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


#define IERR(s)    std::cout<<"error "<<s<<std::endl
#define IRES(s,r)  std::cout<<s<<r<<std::endl

IAdder* pIAdder = nullptr;
IMultiplier* pMultiplier = nullptr;


int main()
{
	IUnknown* pIUnknown = NULL;
	CoInitialize(NULL);                        // инициализация библиотеки OLE32
	HRESULT hr0 = CoCreateInstance(CLSID_CA, NULL, CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pIUnknown);
	if (SUCCEEDED(hr0))
	{
		std::cout << "CoCreateInstance succeeded" << std::endl;
		if (SUCCEEDED(pIUnknown->QueryInterface(IID_IAdder, (void**)&pIAdder)))
		{
			{
				double z = 0.0;
				if (!SUCCEEDED(pIAdder->Add(2.0, 3.0, z)))  IERR("IAdder::Add");
				else IRES("IAdder::Add 2+3= ", z);
			}
			{
				double z = 0.0;
				if (!SUCCEEDED(pIAdder->Sub(2.0, 3.0, z)))  IERR("IAdder::Sub");
				else IRES("IAdder::Sub 2-3= ", z);
			}
			if (SUCCEEDED(pIAdder->QueryInterface(IID_IMultiplier, (void**)&pMultiplier)))
			{
				{
					double z = 0.0;
					if (!SUCCEEDED(pMultiplier->Mul(2.0, 3.0, z))) IERR("IMultiplier::Mul");
					else IRES("Multiplier::Mul 2*3= ", z);
				}
				{
					double z = 0.0;
					if (!SUCCEEDED(pMultiplier->Div(2.0, 3.0, z))) IERR("IMultiplier::Div");
					else IRES("IMultiplier::Div 2/3= ", z);
				}
				if (SUCCEEDED(pMultiplier->QueryInterface(IID_IAdder, (void**)&pIAdder)))
				{
					double z = 0.0;
					if (!SUCCEEDED(pIAdder->Add(2.0, 3.0, z))) IERR("IAdder::Add");
					else IRES("IAdder::Add 2+3= ", z);
					pIAdder->Release();
				}
				else  IERR("IMultiplier->IAdder");
				pMultiplier->Release();
			}
			else IERR("IAdder->IMultiplier");
			pIAdder->Release();
		}
		else  IERR("IAdder");
	}
	else  std::cout << "CoCreateInstance error" << std::endl;
	pIUnknown->Release();
	CoFreeUnusedLibraries();                   // завершение работы с библиотекой      
	system("pause");
	return 0;
}


//
//IAdder* pAdder;
//IMultiplier* pMultiplier;
//int main() {
//	IUnknown* pIUnknown = NULL;
//	CoInitialize(NULL);
//	HRESULT hr0 = CoCreateInstance(CLSID_CA,
//		NULL,
//		CLSCTX_INPROC_SERVER,
//		IID_IUnknown,	//clsid
//		(void**)&pIUnknown);
//	if (SUCCEEDED(hr0)) {
//		std::cout << "CoCreateInstance succeeded" << std::endl;
//		if (SUCCEEDED(pIUnknown->QueryInterface(IID_IAdder, (void**) & pAdder))) {
//			double z = 0.0;
//			
//			if (!SUCCEEDED(pAdder->Add(2.0, 3.0, z))) std::cout << "error add\n";
//			else std::cout << "2 + 3 = " << z;
//
//			pAdder->Release();
//		}
//		else {
//			std::cout << "error getting IAdder\n";
//		}
//
//
//	}
//	else {
//		std::cout << "CoCreateInstance epic fail" << std::endl;
//	}
//	pIUnknown->Release();
//	CoFreeUnusedLibraries();
//
//	system("pause");
//}