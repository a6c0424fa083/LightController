//
//  CreateProjectWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-21.
//

#include "CreateProjectWindow.hpp"

CreateProjectWindow::~CreateProjectWindow() {}

void CreateProjectWindow::Draw(ImVec2 pos, ImVec2 size)
{
    _pos               = pos;
    _size              = size;
    io.FontGlobalScale = fontSize;

    ImGui::PushFont(TITLE);
    setWindowPosSize(_pos, _size);

    ImGui::Begin("CreateProjectWindow", nullptr, STATIC__NO_VISUALS);

    DrawContents();

    ImGui::End();
    ImGui::PopFont();
}

void CreateProjectWindow::DrawContents()
{
    ImGui::PushFont(TITLE);
    ImGui::SetCursorPos(ImVec2(_size.x / 2.0f - ImGui::CalcTextSize("Configure Project").x / 2.0f, saveMargin));
    ImGui::Text("Configure Project");
    ImGui::PopFont();



    ImGui::PushFont(SUBTITLE);

    style.Colors[ImGuiCol_Button]        = green_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = green_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = green_ImGuiCol_ButtonActive;

    ImGui::SetCursorPos(ImVec2(_size.x - saveMargin - ImGui::CalcTextSize("Cancel").x - 2 * saveMargin,
                               _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    if (GLOBAL::CREATEPROJECTWINDOW::isEditMode)
    {
        if (ImGui::Button("Save",
                          ImVec2(ImGui::CalcTextSize("Save").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)))
        {
            GLOBAL::CREATEPROJECTWINDOW::isEditMode = false;
            GLOBAL::CREATEPROJECTWINDOW::isWindowActive = false;
        }
    }
    else
    {
        if (ImGui::Button("Create",
                          ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)))
        {
            GLOBAL::CREATEPROJECTWINDOW::isWindowActive = false;
        }
    }

    style.Colors[ImGuiCol_Button]        = red_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = red_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = red_ImGuiCol_ButtonActive;

    ImGui::SetCursorPos(ImVec2(saveMargin, _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    if (ImGui::Button("Cancel",
                      ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)))
    {
        GLOBAL::CREATEPROJECTWINDOW::isWindowActive = false;
    }

    style.Colors[ImGuiCol_Button]        = default_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = default_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = default_ImGuiCol_ButtonActive;

    ImGui::PopFont();

    _idealWindowSize =
        ImVec2(io_width - 2 * saveMargin, io_height - GLOBAL::HEADERWINDOW::size.y - GLOBAL::HEADERWINDOW::pos.y - 2 * saveMargin);

#undef secondRowPosY
}