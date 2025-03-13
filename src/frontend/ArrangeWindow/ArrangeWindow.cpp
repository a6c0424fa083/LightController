//
//  ArrangeWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2025-01-15.
//

#include "ArrangeWindow.hpp"

//#include <imgui_internal.h>

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
    ImGui::GetWindowDrawList()->AddLine(
        ImVec2(_pos.x + 4 * saveMargin + ImGui::CalcTextSize("XXXXX").x, _pos.y + saveMargin),
        ImVec2(_pos.x + 4 * saveMargin + ImGui::CalcTextSize("XXXXX").x, _pos.y + _size.y - saveMargin),
        ImGui::ColorConvertFloat4ToU32(ImVec4(1.0f, 1.0f, 1.0f, 1.0f)),
        1.0f);

    style.ChildBorderSize = 0.0f;
    ImGui::SetCursorPos(ImVec2(0.0f, 0.0f));
    ImGui::BeginChild(
        "LightsList",
        ImVec2(4 * saveMargin + ImGui::CalcTextSize("XXXXX").x, _size.y - 4 * saveMargin - ImGui::CalcTextSize("XXX").y),
        true,
        ImGuiWindowFlags_NoScrollbar | STATIC__NO_VISUALS);

    for (size_t i = 0; i < GLOBAL::PATCH::patchLights.size(); i++) {
        char label[4];
        snprintf(label, sizeof(label), "%03i", GLOBAL::PATCH::patchLights[i].rootAddress);

        ImGui::SetCursorPos(ImVec2(saveMargin + ImGui::CalcTextSize("XX").x / 2.0f, ImGui::GetCursorPosY() + saveMargin));
        if (ImGui::Button(label, ImVec2(ImGui::CalcTextSize("XXX").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)))
        {
        }
    }

    ImGui::EndChild();
    style.ChildBorderSize = BaseWindow::default_ChildBorderSize;

    // ImGui::PushFont(SUBTITLE);
    ImGui::SetCursorPos(ImVec2(saveMargin, _size.y - 3 * saveMargin - ImGui::CalcTextSize("XXX").y));
    if (ImGui::Button("Edit", ImVec2(ImGui::CalcTextSize("XXXXX").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)))
    {
    }
    // ImGui::PopFont();



    idealSize =
        ImVec2(io_width - 2 * saveMargin, io_height - GLOBAL::HEADERWINDOW::pos.y + GLOBAL::HEADERWINDOW::size.y + 2 * saveMargin);
    GLOBAL::ARRANGEWINDOW::size = idealSize;
    GLOBAL::ARRANGEWINDOW::pos  = _pos;
}
