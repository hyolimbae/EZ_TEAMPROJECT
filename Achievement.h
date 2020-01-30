#pragma once
#include "GgaetIp.h"
#include "Observer.h"
#include <atlconv.h>

struct aInfo
{
	wstring title;
	wstring content;
	int notifyNum;
};

class Achievement: public Script, public Observer
{
public:
	vector<Object*> aBox;
	vector<aInfo> aList;

private:
	virtual void Init() override;
	virtual void OnNotify(MSGTYPE type, string event) override;

	wstring string_to_wstring(string str)
	{
		USES_CONVERSION;
		return std::wstring(A2W(str.c_str()));
	}
};

