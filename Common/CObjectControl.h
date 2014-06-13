/*
* Copyright (C) 2012-2014, <Aeihu.z, aeihu.z@gmail.com>.
*
* Game Scenario Maker is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 2(GPLv2) as published by the Free Software Foundation.
*/

#ifndef _CObjectControl_H_
    #define _CObjectControl_H_

#include "CObject.h"
#include <map>

using namespace std;

class CObjectControl
{
    protected:
        map<string, CObject*>          _objectList;
    public:
        virtual bool AddObject(string name, CObject* obj);
        virtual bool DelObject(string name);
        virtual void OnCleanup();

        virtual bool IsExists(string name);
        virtual CObject* GetObject(string name);
};

#endif