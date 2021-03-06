/*
* Copyright (C) 2012-2015, <Aeihu.z, aeihu.z@gmail.com>.
*
* YOYO is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 3(GPLv3) as published by the Free Software Foundation.
*/

#ifndef _CBAISCPROPERTIES_H_
    #define _CBAISCPROPERTIES_H_

#include "../Action/CSequenceOfAction.h"
#include "../Action/CSimultaneousOfAction.h"
#include "CObject.h"
#include <SFML/Graphics.hpp>
#include <list>
#include "../Action/CActionBy.h"

using namespace std;

class CBaiscProperties : public CObject
{
    private:
        sf::Vector2f                        _scale;
        sf::Vector2f                        _coordinate;
        sf::Vector2f                        _origin;
        float                               _rotation;

    protected:
        CSimultaneousOfAction               _actionList;
        static bool                         _isActionRunning;
    public:
        CBaiscProperties();

        void AddAction(CActionBaseClass* act);
        virtual float GetRotation();
        void SetRotation(float r);
        sf::Vector2f GetPosition();
        virtual void SetPosition(float x, float y);
        virtual void SetPosition(vector<float> args);
        virtual void SetPositionX(float x);
        virtual void SetPositionY(float y);

        virtual sf::Vector2f& GetScale();
        virtual void SetScale(float x, float y);
        virtual void SetScaleX(float x);
        virtual void SetScaleY(float y);

        virtual sf::Vector2f GetOrigin();
        virtual void SetOrigin(float x, float y);
        virtual void SetOriginX(float x);
        virtual void SetOriginY(float y);

        virtual void CleanActionList();

        virtual CSimultaneousOfAction* CreateActionOfOriginTo(size_t elapsed, float x, float y, bool restore);
        virtual CActionTo* CreateActionOfOriginXTo(size_t elapsed, float x, bool restore);
        virtual CActionTo* CreateActionOfOriginYTo(size_t elapsed, float y, bool restore);

        virtual CSimultaneousOfAction* CreateActionOfOriginBy(size_t elapsed, float x, float y, bool restore);
        virtual CActionBy* CreateActionOfOriginXBy(size_t elapsed, float x, bool restore);
        virtual CActionBy* CreateActionOfOriginYBy(size_t elapsed, float y, bool restore);

        /////////////////////////////////////////////////

        virtual void CreateActionOfOriginToForSelf(size_t elapsed, float x, float y, bool restore);
        virtual void CreateActionOfOriginXToForSelf(size_t elapsed, float x, bool restore);
        virtual void CreateActionOfOriginYToForSelf(size_t elapsed, float y, bool restore);

        virtual void CreateActionOfOriginByForSelf(size_t elapsed, float x, float y, bool restore);
        virtual void CreateActionOfOriginXByForSelf(size_t elapsed, float x, bool restore);
        virtual void CreateActionOfOriginYByForSelf(size_t elapsed, float y, bool restore);

        virtual CActionTo* CreateActionOfRotationTo(size_t elapsed, float rotation, bool restore);
        virtual CActionBy* CreateActionOfRotationBy(size_t elapsed, float rotation, bool restore);

        virtual CSimultaneousOfAction* CreateActionOfScaleTo(size_t elapsed, float x, float y, bool restore);
        virtual CActionTo* CreateActionOfScaleXTo(size_t elapsed, float x, bool restore);
        virtual CActionTo* CreateActionOfScaleYTo(size_t elapsed, float y, bool restore);

        virtual CSimultaneousOfAction* CreateActionOfScaleBy(size_t elapsed, float x, float y, bool restore);
        virtual CActionBy* CreateActionOfScaleXBy(size_t elapsed, float x, bool restore);
        virtual CActionBy* CreateActionOfScaleYBy(size_t elapsed, float y, bool restore);

        virtual CSimultaneousOfAction* CreateActionOfMoveTo(size_t elapsed, float x, float y, bool restore);      
        virtual CActionTo* CreateActionOfMoveXTo(size_t elapsed, float x, bool restore);
        virtual CActionTo* CreateActionOfMoveYTo(size_t elapsed, float y, bool restore);

        virtual CSimultaneousOfAction* CreateActionOfMoveBy(size_t elapsed, float x, float y, bool restore);      
        virtual CActionBy* CreateActionOfMoveXBy(size_t elapsed, float x, bool restore);
        virtual CActionBy* CreateActionOfMoveYBy(size_t elapsed, float y, bool restore);

        /////////////////////////////////////////////////////////////////////

        virtual void CreateActionOfRotationToForSelf(size_t elapsed, float rotation, bool restore);
        virtual void CreateActionOfRotationByForSelf(size_t elapsed, float rotation, bool restore);

        virtual void CreateActionOfScaleToForSelf(size_t elapsed, float x, float y, bool restore);
        virtual void CreateActionOfScaleXToForSelf(size_t elapsed, float x, bool restore);
        virtual void CreateActionOfScaleYToForSelf(size_t elapsed, float y, bool restore);

        virtual void CreateActionOfScaleByForSelf(size_t elapsed, float x, float y, bool restore);
        virtual void CreateActionOfScaleXByForSelf(size_t elapsed, float x, bool restore);
        virtual void CreateActionOfScaleYByForSelf(size_t elapsed, float y, bool restore);

        virtual void CreateActionOfMoveToForSelf(size_t elapsed, float x, float y, bool restore);
        virtual void CreateActionOfMoveXToForSelf(size_t elapsed, float x, bool restore);
        virtual void CreateActionOfMoveYToForSelf(size_t elapsed, float y, bool restore);

        virtual void CreateActionOfMoveByForSelf(size_t elapsed, float x, float y, bool restore);
        virtual void CreateActionOfMoveXByForSelf(size_t elapsed, float x, bool restore);
        virtual void CreateActionOfMoveYByForSelf(size_t elapsed, float y, bool restore);

        virtual void OnLoop();
        virtual void OnSaveData(Object& json) const;
        virtual void OnLoadData(Object json);
        virtual void OnCleanup();
};

#endif
