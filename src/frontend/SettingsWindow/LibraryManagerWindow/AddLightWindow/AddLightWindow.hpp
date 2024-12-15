//
//  AddLightWindow.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-14.
//

#ifndef ADDLIGHTWINDOW_HPP
#define ADDLIGHTWINDOW_HPP


#include <imgui.h>

#include <backend/GLOBAL.hpp>
#include <backend/defines.hpp>
#include <frontend/BaseWindow.hpp>
#include <backend/Light/Light.hpp>
#include <backend/Light/ChannelFunction/ChannelFunction.hpp>

class AddLightWindow : BaseWindow
{
public:
    ~AddLightWindow();

    void Draw(ImVec2 pos, ImVec2 size);
    void DrawContents();

    static ImVec2 getIdealWindowSize() { return _idealWindowSize; };

private:
    ImVec2 _pos;
    ImVec2 _size;

    //char _name[MAX_LIGHT_NAME_LENGTH] = { 0 };
    //char _manufacturer[MAX_LIGHT_MANUFACTURER_LENGTH] = { 0 };
    //int  _channelCount                = 0;

    Light _light {};

    inline static auto _idealWindowSize = ImVec2(0.0f, 0.0f);
};



#endif  // ADDLIGHTWINDOW_HPP
