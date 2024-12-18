//
//  ListLightsWindow.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-18.
//

#ifndef LISTLIGHTSWINDOW_HPP
#define LISTLIGHTSWINDOW_HPP



#include <imgui.h>

#include "backend/GLOBAL.hpp"
#include "backend/Light/ChannelFunction/ChannelFunction.hpp"
#include "backend/Light/Light.hpp"
#include "backend/Light/LightFileManager/LightFileManager.hpp"
#include "backend/defines.hpp"
#include "frontend/BaseWindow.hpp"

class ListLightsWindow : BaseWindow
{
public:
    ~ListLightsWindow();

    void Draw(ImVec2 pos, ImVec2 size);
    void DrawContents();

    static ImVec2 getIdealWindowSize() { return _idealWindowSize; };

private:
    ImVec2 _pos;
    ImVec2 _size;

    inline static auto _idealWindowSize = ImVec2(0.0f, 0.0f);
};


#endif //LISTLIGHTSWINDOW_HPP
