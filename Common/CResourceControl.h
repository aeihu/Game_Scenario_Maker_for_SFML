/*
* Copyright (C) 2012-2014, <Aeihu.z, aeihu.z@gmail.com>.
*
* Game Scenario Maker is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 2(GPLv2) as published by the Free Software Foundation.
*/

#ifndef _CRESOURCECONTROL_H_
    #define _CRESOURCECONTROL_H_

#include <string>
#include "CCommon.h"
#include "CObjectControl.h"
#include "CPositionControl.h"
#include "../Graphics/CCamera.h"
#include "../Script/CScript.h"
#include "../Sound/CSoundBank.h"
#include "../Graphics/CDrawableObjectControl.h"
#include "../Graphics/CCameraControl.h"

using namespace std;

class CResourceControl : public CScript
{
    private:
        Object                                  _script;
        Object                                  _scriptOfAsset;
        Object                                  _gameBaiscAsset;
        sf::Thread                              _threadOfLoading;

        string GetNameInFilename(string filename);
        void LoadAsset();
        char CheckIn(Object& json, string colName, string objTypeName);
        bool CheckOut(Object& json, string colName, string objTypeName);
        bool OnInit(string filename);
    protected:
        friend bool Common_FuncOfShow(string funcName, CResourceControl* controlBase, vector<string> args);
        friend bool Cmd_AddVariable(vector<string> args);
        
        //map<string, CCamera*>                   _cameraList;
        //CScript                                 _script;

        inline CResourceControl():_threadOfLoading(&CResourceControl::LoadAsset, this) {_script.reset();}
    public:
        static CResourceControl                 _ResourceManager;
        CSoundBank                              _SoundControl;
        CPositionControl                        _PositionControl;
        CDrawableObjectControl                  _DrawableObjectControl;
        CObjectControl                          _ObjectControl;
        CCameraControl                          _CameraControl;
        
        bool OnInit(string filename, sf::RenderTarget* display);
        bool LoadScript(string filename);
        void OnLoop();
        void OnRender(sf::RenderTarget* Surf_Dest);
        void OnCleanup();
        void OnSaveData();
        void OnLoadData();
};

#endif