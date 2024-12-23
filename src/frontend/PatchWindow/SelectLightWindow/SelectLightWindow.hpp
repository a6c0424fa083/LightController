//
//  SelectLightWindow.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-23.
//

#ifndef SELECTLIGHTWINDOW_HPP
#define SELECTLIGHTWINDOW_HPP


#include <imgui.h>

#include "backend/GLOBAL.hpp"
#include "backend/Light/LightFileManager/LightFileManager.hpp"
#include "backend/defines.hpp"
#include "frontend/BaseWindow.hpp"

class SelectLightWindow : BaseWindow
{
public:
    ~SelectLightWindow();

    void Draw(ImVec2 pos, ImVec2 size);
    void DrawContents();

    static ImVec2 getIdealWindowSize() { return _idealWindowSize; };

private:
    ImVec2 _pos;
    ImVec2 _size;

    inline static auto _idealWindowSize = ImVec2(0.0f, 0.0f);
};



#endif  // SELECTLIGHTWINDOW_HPP
