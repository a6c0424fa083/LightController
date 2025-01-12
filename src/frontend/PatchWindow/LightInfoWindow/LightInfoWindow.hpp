//
//  LightInfoWindow.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-24.
//

#ifndef LIGHTINFOWINDOW_HPP
#define LIGHTINFOWINDOW_HPP


#include <imgui.h>

#include "backend/GLOBAL.hpp"
#include "backend/Light/ChannelFunction/ChannelFunction.hpp"
#include "backend/Light/Light.hpp"
#include "backend/Light/LightFileManager/LightFileManager.hpp"
#include "backend/Patch/Patch.hpp"
#include "backend/Patch/PatchManager/PatchManager.hpp"
#include "backend/defines.hpp"
#include "frontend/BaseWindow.hpp"

class LightInfoWindow : BaseWindow
{
public:
    ~LightInfoWindow();

    void Draw(ImVec2 pos, ImVec2 size);
    void DrawContents();

    static ImVec2 getIdealWindowSize() { return _idealWindowSize; };

private:
    ImVec2 _pos;
    ImVec2 _size;

    inline static auto _idealWindowSize = ImVec2(0.0f, 0.0f);
};



#endif  // LIGHTINFOWINDOW_HPP
