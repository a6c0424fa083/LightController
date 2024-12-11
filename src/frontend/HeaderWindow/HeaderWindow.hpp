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

class HeaderWindow : BaseWindow
{
public:
    ~HeaderWindow();

    void Draw(ImVec2 pos, ImVec2 size);
    void DrawContents();

private:
    ImVec2 pos;
    ImVec2 size;
};


#endif  // HEADERWINDOW_HPP
