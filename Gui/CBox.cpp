/*
* Copyright (C) 2012-2013, <Aeihu.z, aeihu.z@gmail.com>.
*
* Game Scenario Maker is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 2(GPLv2) as published by the Free Software Foundation.
*/

#include "CBox.h"

CBox::CBox(float x, float y):CImageBaseClass(x,y)
{
    _parameterList.clear();
}

CBox::~CBox()
{
	_parameterList.clear();
}

bool CBox::LoadBox(const char* FileName)
{    
    //char BOM[3] = {0xEF,0xBB,0xBF};
    list<string> __expressions = Cio::LoadTxtFile(FileName, "\r\n");
    //map<string, string> __valueList;
    _parameterList.clear();

    for (list<string>::iterator it=__expressions.begin();
        it!=__expressions.end(); it++){
        string __paraName = "";
        string __paraValue = "";
        if(Cio::AnalyticExpression((*it), __paraName, __paraValue))
            _parameterList[__paraName] = __paraValue;
    }

    if (!CheckList(_parameterList))
        return false;

    _Coordinate.x = atof(_parameterList["X"].c_str());
    _Coordinate.y = atof(_parameterList["Y"].c_str());

    sf::Image Surf_tileset;
    if (!CSurface::OnLoad(_parameterList["TILESET_PATH"].c_str(), Surf_tileset))
        return false;

    if (!CGuiCommon::CreateBoxBackground(
        &_image, &Surf_tileset, _parameterList["MAP_PATH"].c_str(), atoi(_parameterList["TILE_SIZE"].c_str())))
        return false;

    _sprite.SetTexture(_image);

    return Sub_OnLoad();
}

bool CBox::CheckList(map<string, string> list)
{
    bool __result = true;
    __result = Sub_CheckList(list);

    if (list.count("TILESET_PATH") < 1){
        cout << "can't find value of TILESET_PATH." << endl;
        __result = false;
    }

    if (list.count("MAP_PATH") < 1){
        cout << "can't find value of MAP_PATH." << endl;
        __result = false;
    }

    if (list.count("TILE_SIZE") < 1){
        cout << "can't find value of TILE_SIZE." << endl;
        __result = false;
    }

    if (list.count("X") < 1){
        cout << "can't find value of X." << endl;
        __result = false;
    }

    if (list.count("Y") < 1){
        cout << "can't find value of Y." << endl;
        __result = false;
    }

    return __result;
}
