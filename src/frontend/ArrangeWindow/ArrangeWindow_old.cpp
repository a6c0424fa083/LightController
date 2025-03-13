//
//  ArrangeWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2025-01-15.
//

#include "ArrangeWindow.hpp"

// #include "../../../lib/thirdParty/glfw/src/cocoa_platform.h"

ArrangeWindow::~ArrangeWindow() {}

void ArrangeWindow::Draw(ImVec2 pos, ImVec2 size)
{
    _pos               = pos;
    _size              = size;
    io.FontGlobalScale = fontSize;

    ImGui::PushFont(NUMBER);
    setWindowPosSize(_pos, _size);

    ImGui::Begin("ArrangeWindow", nullptr, STATIC__NO_VISUALS);

    DrawContents();

    ImGui::End();
    ImGui::PopFont();
}

void ArrangeWindow::DrawContents()
{
    /*
    static const int    gridSize   = 100;
    static const float  cellSize   = 3.5f;                                        // Size of each grid cell (visual)
    static const ImVec2 buttonSize = ImVec2(cellSize * 10.0f, cellSize * 10.0f);  // Button size
    static ImVec2       buttonPos  = ImVec2(0, 0);                                // Initial position of the button
    static bool         isDragging = false;                                       // Is the button being dragged?
    static ImVec2       dragOffset = ImVec2(0, 0);                                // Offset between cursor and button position

    // Get the cursor position to start the grid
    ImVec2 gridOrigin = ImVec2(io_width / 2.0f - (gridSize * cellSize) / 2.0f, io_height / 2.0f - (gridSize * cellSize) / 2.0f);

    // Draw the grid lines (only every fifth line)
    ImDrawList *drawList = ImGui::GetWindowDrawList();
    ImVec2      gridEnd  = ImVec2(gridOrigin.x + gridSize * cellSize, gridOrigin.y + gridSize * cellSize);

    for (size_t i = 0; i <= gridSize; ++i)
    {
        if (i % 5 == 0)
        {
            // Vertical lines
            drawList->AddLine(ImVec2(gridOrigin.x + static_cast<float>(i) * cellSize - cellSize / 2 + 0.5f, gridOrigin.y),
                              ImVec2(gridOrigin.x + static_cast<float>(i) * cellSize - cellSize / 2 + 0.5f, gridEnd.y),
                              IM_COL32(200, 200, 200, 255),
                              1.0f);

            // Horizontal lines
            drawList->AddLine(ImVec2(gridOrigin.x, gridOrigin.y + static_cast<float>(i) * cellSize - cellSize / 2 + 0.5f),
                              ImVec2(gridEnd.x, gridOrigin.y + static_cast<float>(i) * cellSize - cellSize / 2 + 0.5f),
                              IM_COL32(200, 200, 200, 255),
                              1.0f);
        }
    }

    // Handle dragging
    if (ImGui::IsMouseDown(0))
    {  // Left mouse button held
        ImVec2 mousePos = ImGui::GetMousePos();

        // Check if we're starting a drag
        if (!isDragging && ImGui::IsMouseHoveringRect(buttonPos, ImVec2(buttonPos.x + buttonSize.x, buttonPos.y + buttonSize.y)))
        {
            isDragging = true;
            dragOffset = ImVec2(mousePos.x - buttonPos.x, mousePos.y - buttonPos.y);  // Calculate the offset
        }

        if (isDragging)
        {
            // Snap to the nearest grid field center
            float relativeX = mousePos.x - dragOffset.x - gridOrigin.x;
            float relativeY = mousePos.y - dragOffset.y - gridOrigin.y;

            int gridX = static_cast<int>(std::round((relativeX + cellSize / 2) / cellSize)) - 1;
            int gridY = static_cast<int>(std::round((relativeY + cellSize / 2) / cellSize)) - 1;

            // Adjust the button position to snap to the center of the grid field
            buttonPos = ImVec2(gridOrigin.x + gridX * cellSize, gridOrigin.y + gridY * cellSize);
        }
    }
    else
    {
        isDragging = false;  // Stop dragging when the mouse button is released
    }

    // Ensure the button stays within the grid bounds
    buttonPos.x = std::clamp(buttonPos.x, gridOrigin.x, gridOrigin.x + (gridSize - 5) * cellSize);  // -5 to account for button
                                                                                                    // width
    buttonPos.y = std::clamp(buttonPos.y, gridOrigin.y, gridOrigin.y + (gridSize - 5) * cellSize);  // -5 to account for button
                                                                                                    // height

    // Draw the button at its current position
    ImGui::SetCursorScreenPos(buttonPos);
    ImGui::PushFont(NUMBER);
    ImGui::Button("XXX", buttonSize);  // displaying root address of light
    ImGui::PopFont();
*/

    // printf("Pos: %f, %f,   GridPos: %f, %f\n", _pos.x, _pos.y, _gridPos.x, _gridPos.y);

    DrawGrid();


    if (ImGui::IsMouseDown(0))
    {  // Left mouse button held
        // ImVec2 mousePos = ImGui::GetMousePos();

        // Check if we're starting a drag
        if (!_isDragging /*&&
            ImGui::IsMouseHoveringRect(ImVec2(_buttonPos.x + _pos.x, _buttonPos.y + _pos.y), ImVec2(_buttonPos.x + _pos.x + lightListSize.x, _buttonPos.y - _pos.y + lightListSize.y))*/)
        {
            // printf("Button is now draggable at (%f, %f)...\n", _buttonPos.x, _buttonPos.y);
            _isDragging = true;
            _isInTable  = false;
            _dragOffset = ImVec2(ImGui::GetMousePos().x - _buttonPos.x, ImGui::GetMousePos().y - _buttonPos.y);  // Calculate the
                                                                                                                 // offset
        }

        if (_isDragging)
        {
            // printf("Button dragged...\n");
            //  Adjust the button position to snap to the center of the grid field
            _buttonPos = getNearestSnapPoint(ImVec2(ImGui::GetMousePos().x - _dragOffset.x, ImGui::GetMousePos().y - _dragOffset.y),
                                             lightListSize);
        }
    }
    else
    {
        // printf("Button released...\n");
        _isDragging = false;  // Stop dragging when the mouse button is released
        /*
        // ckeck if the table or grid is closer
        if (_gridPos.x - (_buttonPos.x + lightListSize.x / 2.0f) <
            (_buttonPos.x + lightListSize.x / 2.0f) - (saveMargin + lightListSize.x))  // grid is closer
        {
            // snap to nearest grid point
        }
        else
        {
            // snap back to table
            _buttonPos = ImVec2(saveMargin, saveMargin);
        }*/
    }


    if (_isInTable)
    {
        ImGui::SetCursorPos(ImVec2(_gridPos.x, _gridPos.y));
        // printf("Curs: %f, %f\n", _gridPos.x, _gridPos.y);
        _buttonPos = ImGui::GetCursorPos();
        // printf("Btn: %f, %f\n", _buttonPos.x, _buttonPos.y);
    }
    else { ImGui::SetCursorPos(ImVec2(_buttonPos.x, _buttonPos.y)); }
    ImGui::Button("XXX", lightListSize);


    // ImGui::SetCursorPos(ImVec2(_gridPos.x, _gridPos.y));
    // ImGui::Button("XXX", lightListSize);

    idealSize =
        ImVec2(io_width - 2 * saveMargin, io_height - GLOBAL::HEADERWINDOW::pos.y + GLOBAL::HEADERWINDOW::size.y + 2 * saveMargin);
    lightListSize = ImVec2(3.0f * (_gridSize.x / static_cast<float>(_gridSnapPoints.at(0)) * static_cast<float>(_gridNthVisible)),
                           2.0f * (_gridSize.y / static_cast<float>(_gridSnapPoints.at(1)) * static_cast<float>(_gridNthVisible)));
    _gridPos      = ImVec2(2.5f * saveMargin + lightListSize.x + saveMargin, 2.5f * saveMargin);
    _gridSize     = ImVec2(_size.x - _gridPos.x - 2.5f * saveMargin, _size.y - 5 * saveMargin);
    // printf("Pos: %f, %f,   GridPos: %f, %f\n", _pos.x, _pos.y, _gridPos.x, _gridPos.y); // -> Pos: 5.000000, 47.000000,
    // GridPos: 56.500000, 59.500000
    GLOBAL::ARRANGEWINDOW::size = idealSize;
    GLOBAL::ARRANGEWINDOW::pos  = _pos;
}

void ArrangeWindow::DrawGrid()
{
    float x = _gridPos.x;
    while (x < _gridPos.x + _gridSize.x)
    {
        float y = _gridPos.y;
        while (y < _gridPos.y + _gridSize.y)
        {
            ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(x - 0.5f + _pos.x, y - 0.5f + _pos.y),
                                                      ImVec2(x + 0.5f + _pos.x, y + 0.5f + _pos.y),
                                                      ImGui::ColorConvertFloat4ToU32(ImVec4(1.0f, 1.0f, 1.0f, 1.0f)));

            y = y + (_gridSize.y / static_cast<float>(_gridSnapPoints.at(1)) * static_cast<float>(_gridNthVisible));
        }
        x = x + (_gridSize.x / static_cast<float>(_gridSnapPoints.at(0)) * static_cast<float>(_gridNthVisible));
    }
}

ImVec2 ArrangeWindow::getNearestSnapPoint(ImVec2 pos, ImVec2 buttonSize) const
{
    ImVec2 returnPos;

    float x = _gridPos.x;
    while (x < _gridPos.x + _gridSize.x)
    {
        // if the pos is greater than a snap point
        if (x > pos.x + 0.05f) break;

        x = x + (_gridSize.x / static_cast<float>(_gridSnapPoints.at(0)));
    }
    returnPos.x = x - pos.x < pos.x - (x - (_gridSize.x / static_cast<float>(_gridSnapPoints.at(0)))) ?
                      x :
                      x - (_gridSize.x / static_cast<float>(_gridSnapPoints.at(0)));

    float y = _gridPos.y;
    while (y < _gridPos.y + _gridSize.y)
    {
        // if the pos is greater than a snap point
        if (y > pos.y + 0.05f) break;

        y = y + (_gridSize.y / static_cast<float>(_gridSnapPoints.at(1)));
    }
    returnPos.y = y - pos.y < pos.y - (y - (_gridSize.y / static_cast<float>(_gridSnapPoints.at(0)))) ?
                      y :
                      y - (_gridSize.y / static_cast<float>(_gridSnapPoints.at(0)));


    // button is outside grid
    if (_gridPos.x + _gridSize.x < pos.x + buttonSize.x) returnPos.x = _gridPos.x + _gridSize.x - buttonSize.x;
    if (_gridPos.y + _gridSize.y < pos.y + buttonSize.y) returnPos.y = _gridPos.y + _gridSize.y - buttonSize.y;


    return returnPos;
}
