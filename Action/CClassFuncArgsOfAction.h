/*
* Copyright (C) 2012-2015, <Aeihu.z, aeihu.z@gmail.com>.
*
* YOYO is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 3(GPLv3) as published by the Free Software Foundation.
*/

#ifndef _CCLASSFUNCARGSOFACTION_H_
    #define _CCLASSFUNCARGSOFACTION_H_

#include "CActionBaseClass.h"

template<class T>
class CClassFuncArgsOfAction : public CActionBaseClass
{
    private:
        void (T::*_func)(vector<string>);
        
        T*              _obj;
        vector<string>  _args;
    protected:
    public:
        CClassFuncArgsOfAction(T* obj, void (T::*func)(vector<string>), vector<string> args)
        {
            _obj = obj;
            _func = func;
            _args = args;
        }

        bool OnLoop()
        {
            if (_func != 0 && _obj != 0){
                (_obj->*_func)(_args);
            }
    
            return true;
        }
        
        virtual CActionBaseClass* Copy()
        {
            return new CClassFuncArgsOfAction<T>(_obj, _func, _args);
        }

        virtual inline EActType GetType() { return ACTION_CLASS_FUNC_ARGS;}
};

#endif
