/*
* Copyright (C) 2012-2014, <Aeihu.z, aeihu.z@gmail.com>.
*
* Game Scenario Maker is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 2(GPLv2) as published by the Free Software Foundation.
*/

#ifndef _CPARTICLESYSTEM_H_
    #define _CPARTICLESYSTEM_H_

#include <cmath>
#include "../Common/Cio.h"
#include "../Common/CObject.h"
#include "../Common/CConfigFile.h"
#include "../Graphics/CSurface.h"
#include "../Graphics/CImageBaseClass.h"

class CParticleSystem : public CImageBaseClass, public CConfigFile
{
    private:
        struct Particle
        {
            sf::Vector2f        _Velocity;
            sf::Time            _LifeTime;
            sf::RectangleShape  _Rectangle;
            //char                _Layer;
        };

        std::vector<Particle>   _particles;
        sf::Time                _lifeTime;
        sf::Vector2f            _emitter;
        sf::Vector2f            _origin;
        sf::Vector2i            _emitterDeviation;
        int                     _angleMin;
        int                     _angleOffet;
        int                     _speedMin;
        int                     _speedOffet;
        int                     _number;
        sf::Texture             _texture;
        float                   _rotation;
        float                   _ratio;
        float                   _width;
        float                   _height;
        bool                    _enable;

        void ResetParticle(std::size_t index);
        bool CheckList(Object json);
        bool SetProperty(Object json);
    public:
        CParticleSystem();

        static CParticleSystem* Create(const char* filename);
        bool SetTexture(string filename);
        void SetEmitter(sf::Vector2f position);
        bool OnLoop();
        void OnRender(sf::RenderTarget* Surf_Dest);
        virtual void OnSaveData(Object& json) const;
        bool GetEnable() const;
        void SetEnable(bool val);
};

#endif
