//
//  SelectLightWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-23.
//

#include "SelectLightWindow.hpp"

SelectLightWindow::~SelectLightWindow() {}

void SelectLightWindow::Draw(ImVec2 pos, ImVec2 size)
{
    _pos               = pos;
    _size              = size;
    io.FontGlobalScale = fontSize;

    ImGui::PushFont(NUMBER);
    setWindowPosSize(_pos, _size);

    ImGui::Begin("SelectLightWindow", nullptr, STATIC__NO_VISUALS);

    DrawContents();

    ImGui::End();
    ImGui::PopFont();
}

void SelectLightWindow::DrawContents()
{
    LightFileManager::loadLightsFromLibrary();

    ImGui::SetNextWindowPos(ImVec2(_pos.x + saveMargin, _pos.y + saveMargin));
    ImGui::BeginChild("ListLightsWindowChild",
                      ImVec2(_size.x - 2 * saveMargin, _size.y - 6 * saveMargin - ImGui::CalcTextSize("XXX").y),
                      true,
                      ImGuiWindowFlags_AlwaysVerticalScrollbar);

    ImGui::SetCursorPos(ImVec2(_pos.x + 2 * saveMargin, _pos.y + saveMargin));

    for (size_t i = 0; i < GLOBAL::LIGHTFILEMANAGER::lightsLibrary.size(); ++i)
    {
        if (GLOBAL::SELECTLIGHTWINDOW::activeItemIndex == i)
        {
            style.WindowBorderSize = 4 * default_WindowBorderSize;
            style.FrameBorderSize  = 4 * default_FrameBorderSize;
            style.ChildBorderSize  = 4 * default_ChildBorderSize;
        }

        Light &light = GLOBAL::LIGHTFILEMANAGER::lightsLibrary.at(i);

        ImGui::PushID(static_cast<int>(i));  // Unique ID for each light container
        ImGui::SetCursorPos(
            ImVec2(saveMargin, saveMargin + static_cast<float>(i) * (3 * ImGui::CalcTextSize("XXX").y + 5 * saveMargin)));
        // ImGui::SetNextWindowPos(ImVec2(_pos.x + 2 * saveMargin, ImGui::GetCursorPosY() + 100.0f));
        ImGui::BeginChild("LightItem",
                          ImVec2(_size.x - 35.0f, 3 * ImGui::CalcTextSize("XXX").y + 4 * saveMargin),
                          true,
                          ImGuiWindowFlags_NoScrollbar);

        // Check for item click
        if (ImGui::IsWindowHovered() && ImGui::IsMouseClicked(0))
        {
            GLOBAL::SELECTLIGHTWINDOW::activeItemIndex = static_cast<int>(i);
        }

        // Display light details
        ImGui::SetCursorPos(ImVec2(_pos.x + saveMargin, ImGui::GetCursorPosY() + saveMargin));
        ImGui::Text("Name:         %*.*s", MAX_LIGHT_NAME_LENGTH, MAX_LIGHT_NAME_LENGTH, light.name);
        // ImGui::SameLine();
        ImGui::SetCursorPos(ImVec2(_pos.x + saveMargin, ImGui::GetCursorPosY() /* + ImGui::CalcTextSize("XXX").y + saveMargin*/));
        ImGui::Text("Manufacturer: %*.*s", MAX_LIGHT_MANUFACTURER_LENGTH, MAX_LIGHT_MANUFACTURER_LENGTH, light.manufacturer);
        // ImGui::SameLine();
        ImGui::SetCursorPos(ImVec2(_pos.x + saveMargin, ImGui::GetCursorPosY() /* + ImGui::CalcTextSize("XXX").y + saveMargin*/));
        ImGui::Text("Channels:     %*d", MAX_LIGHT_NAME_LENGTH, light.channelCount);
        // ImGui::SameLine();
        // ImGui::SetCursorPos(ImVec2(_pos.x + saveMargin, ImGui::GetCursorPosY()/* + ImGui::CalcTextSize("XXX").y +
        // saveMargin*/));

        ImGui::EndChild();
        ImGui::PopID();

        /// ImGui::SetCursorPos(ImVec2(_pos.x + saveMargin, ImGui::GetCursorPosY() + ImGui::CalcTextSize("XXX").y + saveMargin));


        ImGui::Spacing();  // Add some space between items

        if (GLOBAL::SELECTLIGHTWINDOW::activeItemIndex == i)
        {
            style.WindowBorderSize = default_WindowBorderSize;
            style.FrameBorderSize  = default_FrameBorderSize;
            style.ChildBorderSize  = default_ChildBorderSize;
        }
    }

    ImGui::SetCursorPos(ImVec2(ImGui::GetCursorPosX(), ImGui::GetCursorPosY() + saveMargin));

    ImGui::EndChild();


    ImGui::PushFont(SUBTITLE);

    style.Colors[ImGuiCol_Button]        = green_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = green_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = green_ImGuiCol_ButtonActive;

    ImGui::SetCursorPos(ImVec2(_size.x - saveMargin - ImGui::CalcTextSize("Cancel").x - 2 * saveMargin,
                               _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    if (ImGui::Button("Select",
                      ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)) ||
        (ImGui::IsKeyPressed(ImGuiKey_A) && !GLOBAL::KEYHANDLER::isKeyDown_A))
    {
        bool hasFreeSpace = true;

        if (GLOBAL::LIGHTFILEMANAGER::lightsLibrary.at(GLOBAL::SELECTLIGHTWINDOW::activeItemIndex).channelCount +
                GLOBAL::SELECTLIGHTWINDOW::referenceButtonAddress - 1 >
            512)
        {
            hasFreeSpace = false;
            goto BACKEND_ACTION;
        }

        for (uint16_t i = 0; i < GLOBAL::LIGHTFILEMANAGER::lightsLibrary.at(GLOBAL::SELECTLIGHTWINDOW::activeItemIndex).channelCount;
             i++)
        {
            if (GLOBAL::PATCH::patchButtons.at(GLOBAL::SELECTLIGHTWINDOW::referenceButtonAddress - 1 + i).isUsed)
            {
                hasFreeSpace = false;
                break;
            }
        }

    BACKEND_ACTION:
        if (hasFreeSpace)
        {
            GLOBAL::SELECTLIGHTWINDOW::isWindowActive                                                    = false;
            GLOBAL::PATCH::patchButtons.at(GLOBAL::SELECTLIGHTWINDOW::referenceButtonAddress - 1).isUsed = true;

            auto *light = new Light(GLOBAL::LIGHTFILEMANAGER::lightsLibrary.at(GLOBAL::SELECTLIGHTWINDOW::activeItemIndex),
                                    GLOBAL::SELECTLIGHTWINDOW::referenceButtonAddress);

            GLOBAL::PATCH::patchButtons.at(GLOBAL::SELECTLIGHTWINDOW::referenceButtonAddress - 1).referenceLight = light;

            // add light to the patchLight vector (also used for project storrage)
            GLOBAL::PATCH::patchLights.emplace_back(
                GLOBAL::LIGHTFILEMANAGER::lightsLibrary.at(GLOBAL::SELECTLIGHTWINDOW::activeItemIndex),
                GLOBAL::SELECTLIGHTWINDOW::referenceButtonAddress);

            for (uint16_t i = 1;
                 i < GLOBAL::LIGHTFILEMANAGER::lightsLibrary.at(GLOBAL::SELECTLIGHTWINDOW::activeItemIndex).channelCount;
                 i++)
            {
                GLOBAL::PATCH::patchButtons.at(GLOBAL::SELECTLIGHTWINDOW::referenceButtonAddress - 1 + i).isUsed         = true;
                GLOBAL::PATCH::patchButtons.at(GLOBAL::SELECTLIGHTWINDOW::referenceButtonAddress - 1 + i).referenceLight = light;
            }
        }
    }

    style.Colors[ImGuiCol_Button]        = default_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = default_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = default_ImGuiCol_ButtonActive;


    style.Colors[ImGuiCol_Button]        = red_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = red_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = red_ImGuiCol_ButtonActive;

    ImGui::SetCursorPos(ImVec2(saveMargin, _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    if (ImGui::Button("Cancel",
                      ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)) ||
        (ImGui::IsKeyPressed(ImGuiKey_Escape) && !GLOBAL::KEYHANDLER::isKeyDown_Escape))
    {
        GLOBAL::SELECTLIGHTWINDOW::isWindowActive = false;
    }

    style.Colors[ImGuiCol_Button]        = default_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = default_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = default_ImGuiCol_ButtonActive;

    ImGui::PopFont();

    _idealWindowSize =
        ImVec2(io_width - 2 * saveMargin, io_height - GLOBAL::HEADERWINDOW::size.y - GLOBAL::HEADERWINDOW::pos.y - 2 * saveMargin);
}
