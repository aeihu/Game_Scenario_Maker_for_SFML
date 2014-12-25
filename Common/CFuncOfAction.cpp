/*
* Copyright (C) 2012-2014, <Aeihu.z, aeihu.z@gmail.com>.
*
* Game Scenario Maker is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 2(GPLv2) as published by the Free Software Foundation.
*/

#include "CFuncOfAction.h"

CFuncOfAction::CFuncOfAction(void (*func)())
{
    _func = func;
}

bool CFuncOfAction::OnLoop()
{
    if (_func != 0){
        _func();
    }
    
    return true;
}