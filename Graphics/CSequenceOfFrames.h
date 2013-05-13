/*
* Copyright (C) 2012-2013, <Aeihu.z, aeihu.z@gmail.com>.
*
* Game Scenario Maker is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 2(GPLv2) as published by the Free Software Foundation.
*/
#ifndef _CSEQUENCEOFFRAMES_H_
    #define _CSEQUENCEOFFRAMES_H_

#include "CImageBaseClass.h"
#include "../Common/Define.h"

class CSequenceOfFrames : public CImageBaseClass
{
    private:
        CIntRect        _rect;
    public:
        CSequenceOfFrames(float x=0.0f, float y=0.0f, int left=0, int top=0, int width=1, int height=1);
        void SetCurrentImageFrame(int frame);
        void SetWidth(int w);
        void SetHeight(int h);
        void SetPosition(float x, float y);
        bool LoadImg(const char* filename);

        CCoordinate2f GetPosition();
        int GetWidth();
        int GetHeight();
};

#endif