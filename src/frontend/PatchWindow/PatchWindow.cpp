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
            snprintf(buttonText, 4, "%03d", r * colums + c + 1);

            GLOBAL::PATCH::patchButtons.at(r * colums + c).address = r * colums + c + 1;

            if (GLOBAL::PATCH::patchButtons.at(r * colums + c).isUsed)
            {
                if (GLOBAL::PATCH::patchButtons.at(r * colums + c).address ==
                    GLOBAL::PATCH::patchButtons.at(r * colums + c).referenceLight->rootAddress)
                {
                    style.Colors[ImGuiCol_Button]        = darkgreen_ImGuiCol_Button;
                    style.Colors[ImGuiCol_ButtonHovered] = darkgreen_ImGuiCol_ButtonHovered;
                    style.Colors[ImGuiCol_ButtonActive]  = darkgreen_ImGuiCol_ButtonActive;
                }
                else
                {
                    style.Colors[ImGuiCol_Button]        = green_ImGuiCol_Button;
                    style.Colors[ImGuiCol_ButtonHovered] = green_ImGuiCol_ButtonHovered;
                    style.Colors[ImGuiCol_ButtonActive]  = green_ImGuiCol_ButtonActive;
                }
            }
            if (ImGui::Button(buttonText, ImVec2(buttonSize, buttonSize)))
            {
                if (!GLOBAL::PATCH::patchButtons.at(r * colums + c).isUsed)
                {
                    GLOBAL::SELECTLIGHTWINDOW::isWindowActive         = true;
                    GLOBAL::SELECTLIGHTWINDOW::referenceButtonAddress = r * colums + c + 1;
                }
                else
                {
                    GLOBAL::LIGHTINFOWINDOW::isWindowActive = true;
                    GLOBAL::LIGHTINFOWINDOW::light          = GLOBAL::PATCH::patchButtons.at(r * colums + c).referenceLight;
                    GLOBAL::LIGHTINFOWINDOW::referenceButtonAddress = r * colums + c + 1;
                }
            }
            if (GLOBAL::PATCH::patchButtons.at(r * colums + c).isUsed)
            {
                style.Colors[ImGuiCol_Button]        = default_ImGuiCol_Button;
                style.Colors[ImGuiCol_ButtonHovered] = default_ImGuiCol_ButtonHovered;
                style.Colors[ImGuiCol_ButtonActive]  = default_ImGuiCol_ButtonActive;
            }
        }
    }

    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + saveMargin / 2.0f));  // saveMargin / 2.0f is not
                                                                                                      // accurete and should be
                                                                                                      // replaced soon

    selectLightWindowSize = SelectLightWindow::getIdealWindowSize();
    if (GLOBAL::SELECTLIGHTWINDOW::isWindowActive) { selectLightWindow->Draw(ImVec2(_pos.x, _pos.y), selectLightWindowSize); }

    lightInfoWindowSize = LightInfoWindow::getIdealWindowSize();
    if (GLOBAL::LIGHTINFOWINDOW::isWindowActive) { lightInfoWindow->Draw(ImVec2(_pos.x, _pos.y), lightInfoWindowSize); }

    _idealWindowSize =
        ImVec2(io_width - 2 * saveMargin, io_height - GLOBAL::HEADERWINDOW::size.y - GLOBAL::HEADERWINDOW::pos.y - 2 * saveMargin);
}
