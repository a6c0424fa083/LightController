//
//  PatchWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-22.
//

#include "PatchWindow.hpp"

PatchWindow::~PatchWindow() {}

void PatchWindow::Draw(ImVec2 pos, ImVec2 size)
{
    _pos               = pos;
    _size              = size;
    io.FontGlobalScale = fontSize;

    ImGui::PushFont(NUMBER);
    setWindowPosSize(_pos, _size);

    ImGui::Begin("PatchWindow", nullptr, STATIC__NO_VISUALS);

    DrawContents();

    ImGui::End();
    ImGui::PopFont();
}

void PatchWindow::DrawContents()
{
    buttonSize = (io_width - ((static_cast<float>(colums) + 1) * saveMargin) - (2.0f * saveMargin)) / static_cast<float>(colums);

    for (uint8_t r = 0; r < rows; r++)
    {
        for (uint8_t c = 0; c < colums; c++)
        {
            ImGui::SetCursorPos(ImVec2(saveMargin + static_cast<float>(c) * (saveMargin + buttonSize),
                                       saveMargin + static_cast<float>(r) * (saveMargin + buttonSize)));
            char buttonText[4];
            snprintf(buttonText, 3, "%03d", r * colums + c);
            buttonText[3] = '\0';
            printf("Address: %s\n", buttonText);
            if (ImGui::Button(buttonText, ImVec2(buttonSize, buttonSize)))
            {
                // do something
            }
        }
    }

    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + saveMargin / 2.0f));  // saveMargin / 2.0f is not
                                                                                                      // accurete and should be
                                                                                                      // replaced soon

    _idealWindowSize =
        ImVec2(io_width - 2 * saveMargin, io_height - GLOBAL::HEADERWINDOW::size.y - GLOBAL::HEADERWINDOW::pos.y - 2 * saveMargin);
}
