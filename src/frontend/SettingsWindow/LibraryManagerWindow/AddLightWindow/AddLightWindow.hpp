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

#include "backend/GLOBAL.hpp"
#include "backend/Light/ChannelFunction/ChannelFunction.hpp"
#include "backend/Light/Light.hpp"
#include "backend/Light/LightFileManager/LightFileManager.hpp"
#include "backend/defines.hpp"
#include "frontend/BaseWindow.hpp"

class AddLightWindow : BaseWindow
{
public:
    ~AddLightWindow();

    void Draw(ImVec2 pos, ImVec2 size);
    void DrawContents();

    static ImVec2 getIdealWindowSize() { return _idealWindowSize; };

    void setLight(const Light &light) { _light = light; };

private:
    ImVec2 _pos;
    ImVec2 _size;

    ImVec2 _channelFunctionContainerSize;


    Light _light {};

    bool loadedLightToEdit = false;

    inline static auto _idealWindowSize = ImVec2(0.0f, 0.0f);
};



#endif  // ADDLIGHTWINDOW_HPP
