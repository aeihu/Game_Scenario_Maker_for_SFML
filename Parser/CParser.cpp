/*
* Copyright (C) 2012-2015, <Aeihu.z, aeihu.z@gmail.com>.
*
* Game Scenario Maker is a free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* Version 2(GPLv2) as published by the Free Software Foundation.
*/

#include "CParser.h"

CParser CParser::_Parser;

CParser::CParser()
{
    _delay = 0;
    _pRunning = NULL;
    _pFunc = NULL;
    _index = 0;
    _pause = false;
}

void CParser::Reset()
{
    _index = 0;
    _cmdList.reset();
}

void CParser::SetRunning(bool* running)
{
    _pRunning = running;
}

void CParser::SetDeplay(int ms)
{
    _delay =  ms + CCommon::_Common.GetTicks();
}

bool CParser::IsDeplaying()
{
    return (CCommon::_Common.GetTicks() < _delay ? true : false);
}


void CParser::OnCleanup() 
{
    _cmdList.reset();
    _pRunning = NULL;
}

void CParser::ExecuteCmd(string cmd, CActionSet* act)
{
    vector<string> __listOfCmdPara;
    if (AnalysisOfParameters(cmd, __listOfCmdPara) > 0){

#ifdef _DEBUG
        for (size_t i=0; i<__listOfCmdPara.size(); i++){
            cout << i << ": " << __listOfCmdPara[i] << " ";
        }
        cout << endl;
#endif

        string __commandName = __listOfCmdPara[0];
        __listOfCmdPara.erase(__listOfCmdPara.begin());

        //if (__commandName == "@show_info") _pFunc = &Cmd_ShowInfo;

        if (__commandName == "@add_position") _pFunc = &Cmd_AddPosition;
        else if (__commandName == "@del_position") _pFunc = &Cmd_DelPosition;

        //else if (__commandName == "@add_chara") _pFunc = &Cmd_AddCharacterLayer;
        //else if (__commandName == "@del_chara") _pFunc = &Cmd_DelCharacterLayer;
        else if (__commandName == "@show_chara") _pFunc = &Cmd_ShowCharacterLayer;
        else if (__commandName == "@hide_chara") _pFunc = &Cmd_HideCharacterLayer;
        else if (__commandName == "@move_chara") _pFunc = &Cmd_MoveCharacterLayer;
        else if (__commandName == "@scale_chara") _pFunc = &Cmd_ScaleCharacterLayer;
        else if (__commandName == "@rota_chara") _pFunc = &Cmd_RotationCharacterLayer;
        else if (__commandName == "@face_chara") _pFunc = &Cmd_SetFaceCharacterLayer;
        else if (__commandName == "@order_chara") _pFunc = &Cmd_SetCharacterLayerOrder;

        //else if (__commandName == "@add_bg") _pFunc = &Cmd_AddBackground;
        else if (__commandName == "@show_bg") _pFunc = &Cmd_ShowBackground;
        else if (__commandName == "@hide_bg") _pFunc = &Cmd_HideBackground;
        else if (__commandName == "@move_bg") _pFunc = &Cmd_MoveBackground;
        else if (__commandName == "@scale_bg") _pFunc = &Cmd_ScaleBackground;
        else if (__commandName == "@rota_bg") _pFunc = &Cmd_RotationBackground;
        else if (__commandName == "@order_bg") _pFunc = &Cmd_SetBackgroundLayerOrder;

        //else if (__commandName == "@add_img") _pFunc = &Cmd_AddImg;
        else if (__commandName == "@show_img") _pFunc = &Cmd_ShowImg;
        else if (__commandName == "@hide_img") _pFunc = &Cmd_HideImg;
        else if (__commandName == "@move_img") _pFunc = &Cmd_MoveImg;
        else if (__commandName == "@scale_img") _pFunc = &Cmd_ScaleImg;
        else if (__commandName == "@rota_img") _pFunc = &Cmd_RotationImg;
        else if (__commandName == "@order_img") _pFunc = &Cmd_SetImgLayerOrder;

        //else if (__commandName == "@add_msgbox") _pFunc = &Cmd_AddMessageBox;
        else if (__commandName == "@show_msgbox") _pFunc = &Cmd_ShowMessageBox;
        else if (__commandName == "@hide_msgbox") _pFunc = &Cmd_HideMessageBox;
        //else if (__commandName == "@del_msgbox") _pFunc = &Cmd_DelMessageBox;
        else if (__commandName == "@order_msgbox") _pFunc = &Cmd_SetMessageBoxLayerOrder;
        else if (__commandName == "@msg") _pFunc = &Cmd_Message;

        //else if (__commandName == "@add_logbox") _pFunc = &Cmd_AddLogBox;
        else if (__commandName == "@show_logbox") _pFunc = &Cmd_ShowLogBox;
        else if (__commandName == "@hide_logbox") _pFunc = &Cmd_HideLogBox;
        //else if (__commandName == "@del_logbox") _pFunc = &Cmd_DelLogBox;
        else if (__commandName == "@order_logbox") _pFunc = &Cmd_SetLogBoxLayerOrder;

        //else if (__commandName == "@add_se") _pFunc = &Cmd_AddSE;
        //else if (__commandName == "@del_se") _pFunc = &Cmd_DelSE;
        else if (__commandName == "@play_se") _pFunc = &Cmd_PlaySE;

        //else if (__commandName == "@add_voice") _pFunc = &Cmd_AddVoice;
        //else if (__commandName == "@del_voice") _pFunc = &Cmd_DelVoice;

        else if (__commandName == "@play_bgm") _pFunc = &Cmd_PlayBGM;
        else if (__commandName == "@pause_bgm") _pFunc = &Cmd_PauseBGM;
        else if (__commandName == "@resume_bgm") _pFunc = &Cmd_ResumeBGM;

        //else if (__commandName == "@add_btn") _pFunc = &Cmd_AddButton;
        else if (__commandName == "@show_btn") _pFunc = &Cmd_ShowButton;
        else if (__commandName == "@hide_btn") _pFunc = &Cmd_HideButton;
        else if (__commandName == "@move_btn") _pFunc = &Cmd_MoveButton;
        else if (__commandName == "@scale_btn") _pFunc = &Cmd_ScaleButton;
        else if (__commandName == "@rota_btn") _pFunc = &Cmd_RotationButton;
        else if (__commandName == "@order_btn") _pFunc = &Cmd_SetButtonLayerOrder;
        
        else if (__commandName == "@use_camera") _pFunc = &Cmd_UseCamera;

        else if (__commandName == "@add_var") _pFunc = &Cmd_AddVariable;
        else if (__commandName == "@set_var") _pFunc = &Cmd_SetVariable;
        else if (__commandName == "@del_var") _pFunc = &Cmd_DelVariable;

        //else if (__commandName == "@add_font") _pFunc = &Cmd_AddFont;
        //else if (__commandName == "@del_font") _pFunc = &Cmd_DelFont;

        //else if (__commandName == "@add_particle") _pFunc = &Cmd_AddParticleSystem;
        //else if (__commandName == "@del_particle") _pFunc = &Cmd_DelParticleSystem;
        else if (__commandName == "@show_particle") _pFunc = &Cmd_ShowParticleSystem;
        else if (__commandName == "@hide_particle") _pFunc = &Cmd_HideParticleSystem;
        else if (__commandName == "@order_particle") _pFunc = &Cmd_SetParticleSystemLayerOrder;

        else if (__commandName == "@deplay"){
            if (__listOfCmdPara.size() == 1)
                SetDeplay(atoi(__listOfCmdPara[0].c_str()));
            else
                cout << "Cmd_Deplay(): command invaild. can't set " << __listOfCmdPara.size()
                    << " argument(s) in the command." <<endl;
        }
        //else if (__commandName == "@reload"){
        //    
        //}
        else if (__commandName == "@exit"){
            if (_pRunning != NULL)
                *_pRunning = false;
        }
        else{
            cout << "unknown command." << endl;
            return;
        }

        if (_pFunc != NULL){
            _pFunc(__listOfCmdPara, act);
            _pFunc = NULL;
        }
    }
}

void CParser::SetIndex(size_t i)
{
    _index = i;
}

size_t CParser::GetIndex()
{
    return _index;
}

void CParser::Pause()
{
    _pause = true;
}

void CParser::Continue()
{
    _pause = false;
}
        
void CParser::ParserObject(Object& obj, CActionSet* act)
{
    if (obj.has<String>("type") && obj.has<Array>("script")){
        CActionSet* __actionSet = NULL;

        if (obj.get<String>("type") == "seq")
            __actionSet = new CSequenceOfAction();
        else if (obj.get<String>("type") == "sim")
            __actionSet = new CSimultaneousOfAction();
        else if (obj.get<String>("type") == "rep"){
            if (obj.has<Number>("loop")){
                CRepeatOfAction* __rep = new CRepeatOfAction();
                __rep->SetLoopNum(obj.get<Number>("loop"));
                __actionSet = __rep;
            }
            else{
                cout << "error!" << endl;
                return;
            }
        }
        else{
            cout << "error!" << endl;
            return;
        }

        Array __arrOfScr = obj.get<Array>("script");

        for (size_t i=0; i<__arrOfScr.size(); i++){
            if (__arrOfScr.has<String>(i)){
                ExecuteCmd(__arrOfScr.get<String>(i), __actionSet);
            }
            else if (__arrOfScr.has<Object>(i)){
                ParserObject(__arrOfScr.get<Object>(i), __actionSet);
            }
        }
        
        if (__actionSet != NULL)
            act->AddAction(__actionSet);
    }else{
        cout << "error!" << endl;
    }
}

void CParser::OnLoop()
{
    try
    {
        if (_pause || IsDeplaying())
            return;

        if (_cmdList.size() > _index){
            if (_cmdList.has<String>(_index)){
                ExecuteCmd(_cmdList.get<String>(_index), &CResourceControl::_ResourceManager._ActionControl);
            }
            else if (_cmdList.has<Object>(_index)){
                Object __obj = _cmdList.get<Object>(_index);
                ParserObject(__obj, &CResourceControl::_ResourceManager._ActionControl);
                
            }else{
                    cout << "error!" << endl;
            }

            ++_index;
        }
    }
    catch(exception& e)
    {
        cout << "Standard exception: " << e.what() << endl;
    }
}

void CParser::InsertCmd(Array cmd)
{
    _cmdList.import(cmd);
    //_cmdList.push_back(cmd);
}

int CParser::AnalysisOfParameters(string para, vector<string> &plist)
{
    string __tmp = "";
    size_t __index = 0;

    while (para.length() != 0)
    {
        if (para[0] != 0x20 && para[0] != 0x09){
            if (para[0] == '\'' && __tmp.empty()){
                para.erase(0,1);
                
                __index = 0;
                do{
                     __index = para.find("'", __index == 0 ? 0 : __index+1);
                    if (__index != string::npos && __index > 0){
                        if (para[__index-1] != '\\'){
                            __tmp.insert (0, para, 0, __index);
                            plist.push_back(__tmp);
                            __tmp.clear();
                            para.erase(0, __index + 1);
                            break;
                        }
                    }
                    else{
                        plist.clear();
                        return -1;
                    }
                }while (true);
            }
            else{
                __tmp += para[0];
                para.erase(0,1);

                if (para.length() == 0)
                    plist.push_back(__tmp);
            }
        }
        else{
            if (!__tmp.empty()){
                    plist.push_back(__tmp);
                    __tmp.clear();
            }

            para.erase(0,1);
        }
    }

    for (size_t i = 1; i < plist.size(); i++)
    {
        if(plist[i].at(0) == '$'){
            //if (CCommon::_Common._PlayerVariableTable.count(plist[i]) > 0){
                //plist[i] = CCommon::_Common._PlayerVariableTable[plist[i]];
            //}
            plist[i] = CResourceControl::_ResourceManager.GetVariable(plist[i]);
        }
    }

    return plist.size();
}
