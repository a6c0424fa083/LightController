//
//  ClearWindow.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-24.
//

#ifndef CLEARWINDOW_HPP
#define CLEARWINDOW_HPP


#include <imgui.h>

#include "backend/GLOBAL.hpp"
#include "backend/defines.hpp"
#include "frontend/BaseWindow.hpp"

class ClearWindow : BaseWindow
{
public:
    ~ClearWindow();

    void Draw(ImVec2 pos, ImVec2 size);
    void DrawContents();

private:
    ImVec2 _pos;
    ImVec2 _size;
};



#endif  // CLEARWINDOW_HPP
