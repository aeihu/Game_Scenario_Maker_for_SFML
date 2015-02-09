/*
* Copyright (C) 2012-2015, <Aeihu.z, aeihu.z@gmail.com>.
*
* Game Scenario Maker is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 2(GPLv2) as published by the Free Software Foundation.
*/

#ifndef _CREPEATOFACTION_H_
    #define _CREPEATOFACTION_H_

#include "CActionSet.h"

class CRepeatOfAction : public CActionSet
{
    private:
        int     _count;
        int     _loopNum;
    protected:
    public:
        CRepeatOfAction();
        bool OnLoop(bool cleanup=true);
        void SetLoopNum(int num);
};

#endif