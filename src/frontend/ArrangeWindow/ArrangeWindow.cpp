//
//  ArrangeWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2025-01-15.
//

#include "ArrangeWindow.hpp"

ArrangeWindow::~ArrangeWindow() {}

void ArrangeWindow::Draw(ImVec2 pos, ImVec2 size)
{
    _pos               = pos;
    _size              = size;
    io.FontGlobalScale = fontSize;

    ImGui::PushFont(SUBTITLE);
    setWindowPosSize(_pos, _size);

    ImGui::Begin("ArrangeWindow", nullptr, STATIC__NO_VISUALS);

    DrawContents();

    ImGui::End();
    ImGui::PopFont();
}

void ArrangeWindow::DrawContents()
{
    static const int    gridSize   = 100;
    static const float  cellSize   = 3.5f;                                      // Size of each grid cell (visual)
    static const ImVec2 buttonSize = ImVec2(cellSize * 10.0f, cellSize * 10.0f);  // Button size
    static ImVec2       buttonPos  = ImVec2(0, 0);                              // Initial position of the button
    static bool         isDragging = false;                                     // Is the button being dragged?
    static ImVec2       dragOffset = ImVec2(0, 0);                              // Offset between cursor and button position

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
                              IM_COL32(200, 200, 200, 255), 1.0f);

            // Horizontal lines
            drawList->AddLine(ImVec2(gridOrigin.x, gridOrigin.y + static_cast<float>(i) * cellSize - cellSize / 2 + 0.5f),
                              ImVec2(gridEnd.x, gridOrigin.y + static_cast<float>(i) * cellSize - cellSize / 2 + 0.5f),
                              IM_COL32(200, 200, 200, 255), 1.0f);
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
    ImGui::Button("XXX", buttonSize); // displaying root address of light
    ImGui::PopFont();


    idealSize =
        ImVec2(io_width - 2 * saveMargin, io_height - GLOBAL::HEADERWINDOW::pos.y + GLOBAL::HEADERWINDOW::size.y + 2 * saveMargin);
    GLOBAL::ARRANGEWINDOW::size = idealSize;
    GLOBAL::ARRANGEWINDOW::pos  = _pos;
}
