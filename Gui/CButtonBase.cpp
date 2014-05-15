/*
* Copyright (C) 2012-2014, <Aeihu.z, aeihu.z@gmail.com>.
*
* Game Scenario Maker is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 2(GPLv2) as published by the Free Software Foundation.
*/

#include "CButtonBase.h"
#include "../Sound/CSoundBank.h"

CButtonBase::CButtonBase(float x, float y, int w, int h, int maxframes, int framerate):CSequenceOfFrames(x,y,0,0,w,h)
{
    _AnimationControl._MaxFrames = maxframes;
    _AnimationControl.SetFrameRate(framerate);
    _AnimationControl.SetCurrentFrame(0);
    _AnimationControl._Type = CAnimation::Backward;
    _isMouseDown = false;
    _isMouseOver = false;
    _seNameOfMouseOver = CCommon::_Common.MOUSEOVER_SE;
    _seNameOfMouseDown = CCommon::_Common.MOUSEDOWN_SE;
    _Coordinate.x=x;
    _Coordinate.y=y;
}

bool CButtonBase::OnLButtonDown(int x, int y)
{
    if (IsStandby())
        if (_isMouseOver)
        {
            _isMouseDown = true;
            SetCurrentImageFrame(_AnimationControl._MaxFrames);
            _AnimationControl.SetCurrentFrame(_AnimationControl._MaxFrames-1);
            CSoundBank::_SoundControl.PlaySE(_seNameOfMouseDown);
            return true;
        }

    return false;
}

bool CButtonBase::OnLButtonUp(int x, int y)
{
    if (IsStandby()){
        if(_isMouseOver){
            _isMouseDown = false;
            SetCurrentImageFrame(_AnimationControl._MaxFrames-1);
            Exec();
            return true;
        }
        else{
            SetCurrentImageFrame(_AnimationControl.GetCurrentFrame());
        }
    }

    return false;
}

bool CButtonBase::OnLoop()
{
    bool __result = CImageBaseClass::OnLoop();

    if (!_isMouseDown){
        SetCurrentImageFrame(_AnimationControl.GetCurrentFrame());
        _AnimationControl.OnAnimate(CCommon::_Common.GetTicks());
    }

    return __result;
}

bool CButtonBase::IsMouseOver() const
{
    return _isMouseOver;
}

bool CButtonBase::IsMouseDown() const
{
    return _isMouseDown;
}

void CButtonBase::OnMouseMove(int x, int y)
{
    if (IsStandby()){
        if(( x > GetPosition().x ) && ( x < GetPosition().x + GetWidth()) && 
            ( y > GetPosition().y ) && ( y < GetPosition().y + GetHeight())){
            if (!_isMouseOver)
            _isMouseOver = true;
            _AnimationControl._Type = CAnimation::Forward;
        }
        else{
            _isMouseOver = false;
            _isMouseDown = false;
            _AnimationControl._Type = CAnimation::Backward;
        }
    }
}

bool CButtonBase::CheckList(map<string, string>& list) 
{
    bool result = true;
    if (list.count("TILESET_PATH") < 1){
        cout << "can't find value of TILESET_PATH." << endl;
        result = false;
    }

    if (list.count("WIDTH") < 1){
        cout << "can't find value of WIDTH." << endl;
        result = false;
    }

    if (list.count("HEIGHT") < 1){
        cout << "can't find value of HEIGHT." << endl;
        result = false;
    }

    if (list.count("MAX_FRAMES") < 1){
        cout << "can't find value of MAX_FRAMES." << endl;
        result = false;
    }

    if (list.count("FRAME_RATE") < 1){
        cout << "can't find value of FRAME_RATE." << endl;
        result = false;
    }

    return result;
}

bool CButtonBase::SetProperty(map<string, string>& list)
{    
    SetWidth(atoi(list["WIDTH"].c_str()));
    SetHeight(atoi(list["HEIGHT"].c_str()));
    if (!LoadImg(list["TILESET_PATH"].c_str()))
        return false;

    _AnimationControl._MaxFrames = atoi(list["MAX_FRAMES"].c_str());
    _AnimationControl.SetFrameRate(atoi(list["FRAME_RATE"].c_str()));
    if (list.count("X") > 0){
        _Coordinate.x=atof(list["X"].c_str());
    }

    if (list.count("Y") > 0){
        _Coordinate.y=atof(list["Y"].c_str());
    }

    return true;
}