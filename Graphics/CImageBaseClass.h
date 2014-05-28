/*
* Copyright (C) 2012-2014, <Aeihu.z, aeihu.z@gmail.com>.
*
* Game Scenario Maker is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 2(GPLv2) as published by the Free Software Foundation.
*/

#ifndef _CIMAGEBASECLASS_H_
    #define _CIMAGEBASECLASS_H_

#include <SFML/Graphics.hpp>
#include "../Graphics/CSurface.h"
#include "../Common/CAdder.h"
#include "../Common/CObject.h"

class CImageBaseClass : virtual public CAdderControl, public CObject
{
    private:
        using CAdderControl::OnLoop;
        using CAdderControl::Count;

        char                _layerOrder;
    protected:
        sf::Texture         _image;
        sf::Sprite          _sprite;
        bool                _visible;

        bool IsStandby();
        virtual bool LoadImg(const char* filename);
    public:
        sf::Vector2f        _Coordinate;
        int                 _Alpha;

        CImageBaseClass(float x=0.0f, float y=0.0f);
        virtual ~CImageBaseClass();
        
        void SetLayerOrder(char order);
        char GetLayerOrder() const;
        static CImageBaseClass* Create(const char* filename);
        virtual void OnRender(sf::RenderWindow* Surf_Dest);
        virtual bool OnLoop();

        virtual bool GetVisible() const;
};

#endif
