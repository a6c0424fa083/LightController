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

#include "backend/GLOBAL.hpp"
#include "backend/defines.hpp"
#include "frontend/BaseWindow.hpp"

class HeaderWindow : BaseWindow
{
public:
    ~HeaderWindow();

    void Draw(ImVec2 pos, ImVec2 size);
    void DrawContents();

    static ImVec2 getIdealSize() { return idealSize; };


    ImVec2 _pos;
    ImVec2 _size;

    inline static ImVec2 idealSize = ImVec2(0.0f, 0.0f);

    float progressBarThickness = 5.0F;
    float lineThickness        = 0.2F;
};


#endif  // HEADERWINDOW_HPP
