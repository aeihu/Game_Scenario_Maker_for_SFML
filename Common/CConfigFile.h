/*
* Copyright (C) 2012-2015, <Aeihu.z, aeihu.z@gmail.com>.
*
* YOYO is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 3(GPLv3) as published by the Free Software Foundation.
*/

#ifndef _CCONFIGFILE_H_
    #define _CCONFIGFILE_H_

#include <map>
#include <string>
#include "Cio.h"
#include "jsonxx.h"

using namespace std;
using namespace jsonxx;

class CConfigFile
{
    private:
        Object _json;
    protected:
        virtual bool CheckList(const Object& json)=0;
        virtual bool SetProperty(const Object& json, bool isLoad = true) = 0;
    public:
        virtual bool LoadConfigFile(const char* FileName);
        virtual void Reset();
};

#endif
