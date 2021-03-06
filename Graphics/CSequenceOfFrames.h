/*
* Copyright (C) 2012-2015, <Aeihu.z, aeihu.z@gmail.com>.
*
* YOYO is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 3(GPLv3) as published by the Free Software Foundation.
*/
#ifndef _CSEQUENCEOFFRAMES_H_
    #define _CSEQUENCEOFFRAMES_H_

#include "CImageBaseClass.h"
#include "../Animation/CAnimation.h"

class CSequenceOfFrames : public CAnimation
{
    private:
        sf::IntRect         _rect;
        sf::Image*          _destOriImage;
        sf::Image           _image;
        sf::Image           _tile;
        sf::Texture*        _destTexture;
        sf::Vector2i        _offset;

        void Composite(sf::Image& baseImage, sf::Image& compositeImage);
    public:
        CSequenceOfFrames(int left=0, int top=0, int width=1, int height=1);
        ~CSequenceOfFrames();
        
        void SetCurrentImageFrame(int frame);
        sf::Vector2i GetOffset();
        void SetDestTexture(sf::Texture* pTexture, sf::IntRect rect, sf::Image* pImg);
        void SetDestTexture(sf::Texture* pTexture, sf::Image* pImg);
        void SetDestTexture(sf::Texture* pTexture, sf::IntRect rect);
        void SetTexture(sf::Image& image);
        bool LoadImg(const char* filename);

        int GetWidth() const;
        int GetHeight() const;
        void TurnOff();

        void OnLoop();
};

#endif