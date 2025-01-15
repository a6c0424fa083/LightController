//
//  ArrangeWindow.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2025-01-15.
//

#ifndef ARRANGEWINDOW_HPP
#define ARRANGEWINDOW_HPP


#include <algorithm>
#include <cmath>
#include <imgui.h>

#include "backend/GLOBAL.hpp"
#include "backend/defines.hpp"
#include "frontend/BaseWindow.hpp"

class ArrangeWindow : BaseWindow
{
public:
    ~ArrangeWindow();

    void Draw(ImVec2 pos, ImVec2 size);
    void DrawContents();

    static ImVec2 getIdealSize() { return idealSize; };

private:
    ImVec2 _pos;
    ImVec2 _size;

    inline static ImVec2 idealSize = ImVec2(0.0f, 0.0f);
};


#endif  // ARRANGEWINDOW_HPP
