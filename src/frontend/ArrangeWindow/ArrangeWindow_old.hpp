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

    void DrawGrid();

    ImVec2 getNearestSnapPoint(ImVec2 pos, ImVec2 buttonSize) const;

    static ImVec2 getIdealSize() { return idealSize; };

private:
    ImVec2 _pos;
    ImVec2 _size;

    ImVec2              _gridSize;
    std::vector<size_t> _gridSnapPoints = { 270, 170 };
    size_t              _gridNthVisible = 5;  // every n'th grid is shown
    ImVec2              lightListSize   = ImVec2(0.0f, 0.0f);
    ImVec2              _gridPos        = ImVec2(0.0f, 0.0f);
    bool                _isInTable      = true;

    ImVec2 _buttonPos  = ImVec2(0, 0);
    bool   _isDragging = false;
    ImVec2 _dragOffset = ImVec2(0, 0);

    inline static ImVec2 idealSize = ImVec2(0.0f, 0.0f);
};


#endif  // ARRANGEWINDOW_HPP
