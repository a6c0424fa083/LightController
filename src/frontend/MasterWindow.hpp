//
//  MasterWindow.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-10.
//

#ifndef MASTERWINDOW_HPP
#define MASTERWINDOW_HPP


#include <imgui.h>
#include <string>
#include <vector>

#include "backend/defines.hpp"
#include "frontend/BaseWindow.hpp"
#include "frontend/HeaderWindow/HeaderWindow.hpp"


class MasterWindow : BaseWindow
{
public:
    ~MasterWindow();

    void        Draw(ImVec2 pos, ImVec2 size);
    inline void DrawContents();

private:
    ImVec2 _pos;
    ImVec2 _size;

    ImVec2 idealHeaderWindowSize = ImVec2(0.0f, 0.0f);
    HeaderWindow *headerWindow = new HeaderWindow();
};


#endif  // MASTERWINDOW_HPP
