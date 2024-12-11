//
//  HeaderWindow.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-11.
//

#ifndef HEADERWINDOW_HPP
#define HEADERWINDOW_HPP


#include <imgui.h>

#include "backend/defines.hpp"
#include "frontend/BaseWindow.hpp"
#include "backend/GLOBAL.hpp"

class HeaderWindow : BaseWindow
{
public:
    ~HeaderWindow();

    void Draw(ImVec2 pos, ImVec2 size);
    void DrawContents();

    static ImVec2 getWindowSize();

private:
    ImVec2 _pos;
    ImVec2 _size;

    float progressBarThickness = 5.0F;
    float lineThickness = 0.2F;
};


#endif  // HEADERWINDOW_HPP
