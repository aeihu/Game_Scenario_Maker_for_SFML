/*
* Copyright (C) 2012-2014, <Aeihu.z, aeihu.z@gmail.com>.
*
* Game Scenario Maker is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 2(GPLv2) as published by the Free Software Foundation.
*/

#include "CFontControl.h"

CObject* CFontControl::GetObject(string name)
{
    if (_fontList.count(name) < 1)
        return NULL;
    
    return &_fontList[name];
}

bool CFontControl::AddCFont(string name, const char* filename)
{
    if (!IsExists(name)){
        _fontList.insert(
            std::pair<string,CFont>(name, CFont()));
    }
    else
        return false;

    //if(_fontList[name].LoadFont(filename)){
    //    return true;
    //}
    //else{
    //    _fontList.erase(name);
    //    return false;
    //}
}

bool CFontControl::DelCFont(string name)
{
    if (name == "__main"){
        cout << "CFontControl::DelCFont(): can't delete font \"__main\"." << endl;
        return true;
    }

    if (IsExists(name)){
        _fontList.erase(name);
        return true;
    }
    return false;
}

void CFontControl::OnCleanup()
{
    map<std::string, CFont>::iterator it;
    for ( it=_fontList.begin();it!=_fontList.end(); it++ )
        (*it).second.OnCleanup();

    _fontList.clear();
}
