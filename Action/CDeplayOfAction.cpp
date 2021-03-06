/*
* Copyright (C) 2012-2015, <Aeihu.z, aeihu.z@gmail.com>.
*
* YOYO is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 3(GPLv3) as published by the Free Software Foundation.
*/

#include "CDeplayOfAction.h"

CDeplayOfAction::CDeplayOfAction(size_t delay)
{
    _isRunning = false;
    _delay = delay;
}

bool CDeplayOfAction::OnLoop()
{
    if (!_isRunning){
        _time = CCommon::_Common.GetTicks() + _delay;
        _isRunning = true;
    }

    if (_time < CCommon::_Common.GetTicks() || _skip){
        _isRunning = false;
        return true;
    }

    return false;
}

CActionBaseClass* CDeplayOfAction::Copy()
{
    return new CDeplayOfAction(_delay);
}