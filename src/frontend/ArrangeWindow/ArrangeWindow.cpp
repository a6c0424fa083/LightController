//
//  ArrangeWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2025-01-15.
//

#include "ArrangeWindow.hpp"

// #include <imgui_internal.h>

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

    if (GLOBAL::ARRANGEWINDOW::isEditOptionsWindowActive) { DrawEditOptionsWindow(); }

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
    setWindowPosSize(ImVec2(_pos.x + saveMargin ,_pos.y + saveMargin), ImVec2(2 * saveMargin + ImGui::CalcTextSize("XXXXX").x, _size.y - 5 * saveMargin - ImGui::CalcTextSize("XXX").y));

    ImGui::Begin(
        "LightsList",
        nullptr, STATIC__NO_VISUALS);

    for (size_t i = 0; i < GLOBAL::PATCH::patchLights.size(); i++)
    {
        char label[4];
        snprintf(label, sizeof(label), "%03i", GLOBAL::PATCH::patchLights[i].rootAddress);

        ImGui::SetCursorPos(ImVec2((2 * saveMargin + ImGui::CalcTextSize("XXXXX").x) / 2.0f - (ImGui::CalcTextSize("XXX").x + 2 * saveMargin) / 2.0f, ImGui::GetCursorPosY() + saveMargin));
        if (ImGui::Button(label, ImVec2(ImGui::CalcTextSize("XXX").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)))
        {
            if (GLOBAL::ARRANGEWINDOW::isButtonEdit) { GLOBAL::ARRANGEWINDOW::isEditOptionsWindowActive = true; }
            else {}
        }
    }

    ImGui::SetCursorPos(ImVec2(saveMargin, ImGui::GetCursorPosY() + saveMargin));
    ImGui::End();
    style.ChildBorderSize = BaseWindow::default_ChildBorderSize;

    // ImGui::PushFont(SUBTITLE);
    ImGui::SetCursorPos(ImVec2(saveMargin, _size.y - 3 * saveMargin - ImGui::CalcTextSize("XXX").y));
    if (ImGui::Button(GLOBAL::ARRANGEWINDOW::isButtonEdit ? "Edit" : "Move",
                      ImVec2(ImGui::CalcTextSize("XXXXX").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)))
    {
        GLOBAL::ARRANGEWINDOW::isButtonEdit = !GLOBAL::ARRANGEWINDOW::isButtonEdit;
    }
    // ImGui::PopFont();



    idealSize =
        ImVec2(io_width - 2 * saveMargin, io_height - GLOBAL::HEADERWINDOW::pos.y + GLOBAL::HEADERWINDOW::size.y + 2 * saveMargin);
    GLOBAL::ARRANGEWINDOW::size = idealSize;
    GLOBAL::ARRANGEWINDOW::pos  = _pos;
}

void ArrangeWindow::DrawEditOptionsWindow()
{
    ImVec2 size = ImVec2(io_width / 5.0f, io_height / 1.5f);
    ImVec2 pos  = ImVec2(io_width / 2.0f - size.x / 2.0f, io_height / 2.0f - size.y / 2.0f);
    setWindowPosSize(pos, size);

    ImGui::Begin("EditOptionsWindow", nullptr, STATIC__NO_VISUALS);


    ImGui::PushFont(SUBTITLE);





    ImGui::SetCursorPos(
        ImVec2(saveMargin, saveMargin + 0 * (ImGui::CalcTextSize("XXX").y + 3 * saveMargin)));
    if (ImGui::Button("Live Edit", ImVec2(size.x - 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin))) {}

    ImGui::SetCursorPos(
        ImVec2(saveMargin, saveMargin + 1 * (ImGui::CalcTextSize("XXX").y + 3 * saveMargin)));
    if (ImGui::Button("Arrange", ImVec2(size.x - 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin))) {}

    ImGui::SetCursorPos(
        ImVec2(saveMargin, saveMargin + 2 * (ImGui::CalcTextSize("XXX").y + 3 * saveMargin)));
    if (ImGui::Button("Edit Color", ImVec2(size.x - 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin))) {}



    style.Colors[ImGuiCol_Button]        = red_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = red_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = red_ImGuiCol_ButtonActive;

    ImGui::SetCursorPos(ImVec2(saveMargin, size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    if (ImGui::Button("Cancel",
                      ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)) ||
        (ImGui::IsKeyPressed(ImGuiKey_Escape) && !GLOBAL::KEYHANDLER::isKeyDown_Escape))
    {
        GLOBAL::ARRANGEWINDOW::isEditOptionsWindowActive = false;
    }

    style.Colors[ImGuiCol_Button]        = default_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = default_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = default_ImGuiCol_ButtonActive;


    ImGui::PopFont();
    ImGui::End();
}
