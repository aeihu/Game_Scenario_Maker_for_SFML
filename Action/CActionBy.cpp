/*
* Copyright (C) 2012-2015, <Aeihu.z, aeihu.z@gmail.com>.
*
* Game Scenario Maker is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 2(GPLv2) as published by the Free Software Foundation.
*/

#include "CActionBy.h"

CActionBy::CActionBy(float* val, size_t elapsed, float fin, bool restore, bool pause)
{
    _val = NULL;
    if (val){
        _isRunning = false;
        //if (elapsed == 0) elapsed = 1;
        _val = val;
        _byVal = fin;
        //_valOfFinish = fin;
        _pause = pause;
        _restore = restore;
        _elapsed = elapsed;
    }
}

/*
    when result is true, it's mean action has finished
*/
bool CActionBy::OnLoop(bool cleanup)
{
    if (_val == NULL)
        return true;
    
    if (!_isRunning){
        _isRunning = true;
        _orgVal = *_val;
        _valOfFinish = _orgVal + _byVal;

        if (_elapsed == 0)
            *_val = _valOfFinish;
        else
            _incr = abs(_byVal * ((1000.0f/(float)CCommon::_Common.MAX_FPS)/(float)_elapsed));
    }

    if ((*_val) != _valOfFinish){
        bool __b = (*_val) < _valOfFinish ? true:false; 
        (*_val) += (__b ? _incr : -_incr) * (_skip ? 10 : 1);
        _skip = false;

        if (__b){
            if ((*_val) > _valOfFinish){
                (*_val) = _valOfFinish;
                goto FINISH;
            }
        }
        else{
            if ((*_val) < _valOfFinish){
                (*_val) = _valOfFinish;
                goto FINISH;
            }
        }
  
        return false;
    }
    else{
FINISH:
        if (_restore) *_val = _orgVal;
        
        _isRunning = false;
        return true;
    }
}

bool CActionBy::IsPause()
{
    return _pause && _isRunning;
}