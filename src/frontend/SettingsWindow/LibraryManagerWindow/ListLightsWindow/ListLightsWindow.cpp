//
//  ListLightsWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-18.
//

#include "ListLightsWindow.hpp"

#include <frontend/SettingsWindow/LibraryManagerWindow/AddLightWindow/AddLightWindow.hpp>

ListLightsWindow::~ListLightsWindow() {}

void ListLightsWindow::Draw(ImVec2 pos, ImVec2 size)
{
    _pos               = pos;
    _size              = size;
    io.FontGlobalScale = fontSize;

    ImGui::PushFont(NUMBER);
    setWindowPosSize(_pos, _size);

    ImGui::Begin("ListLightsWindow", nullptr, STATIC__NO_VISUALS);

    DrawContents();

    ImGui::End();
    ImGui::PopFont();
}

void ListLightsWindow::DrawContents()
{
    LightFileManager::loadLightsFromLibrary();

    if (GLOBAL::LIGHTFILEMANAGER::lightsLibrary.empty())
    {
        GLOBAL::ADDLIGHTWINDOW::isWindowActive           = true;
        GLOBAL::LISTLIGHTSWINDOW::isWindowActive         = false;
        GLOBAL::ADDLIGHTWINDOW::cameFromListLightsWindow = true;
    }


    // if (GLOBAL::LIGHTFILEMANAGER::lightsLibrary.empty()) { ImGui::Text("No lights available."); }

    ImGui::SetNextWindowPos(ImVec2(_pos.x + saveMargin, _pos.y + saveMargin));
    ImGui::BeginChild("ListLightsWindowChild",
                      ImVec2(_size.x - 2 * saveMargin, _size.y - 6 * saveMargin - ImGui::CalcTextSize("XXX").y),
                      true,
                      ImGuiWindowFlags_AlwaysVerticalScrollbar);

    ImGui::SetCursorPos(ImVec2(_pos.x + 2 * saveMargin, _pos.y + saveMargin));

    for (size_t i = 0; i < GLOBAL::LIGHTFILEMANAGER::lightsLibrary.size(); ++i)
    {
        if (GLOBAL::LISTLIGHTSWINDOW::activeItemIndex == i)
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
            GLOBAL::LISTLIGHTSWINDOW::activeItemIndex = static_cast<int>(i);
        }

        // Display light details
        // TODO: account for scrollable full length (64) names
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

        if (GLOBAL::LISTLIGHTSWINDOW::activeItemIndex == i)
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
    if (ImGui::Button("Add", ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin))/* || ImGui::IsKeyPressed(ImGuiKey_A)*/)
    {
        GLOBAL::ADDLIGHTWINDOW::isWindowActive           = true;
        GLOBAL::LISTLIGHTSWINDOW::isWindowActive         = false;
        GLOBAL::ADDLIGHTWINDOW::cameFromListLightsWindow = true;
    }

    style.Colors[ImGuiCol_Button]        = default_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = default_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = default_ImGuiCol_ButtonActive;

    ImGui::SetCursorPos(ImVec2(_size.x - 2 * saveMargin - 2 * ImGui::CalcTextSize("Cancel").x - 4 * saveMargin,
                               _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    if (ImGui::Button("Edit", ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin))/* || ImGui::IsKeyPressed(ImGuiKey_E)*/)
    {
        GLOBAL::ADDLIGHTWINDOW::lightToEdit = GLOBAL::LIGHTFILEMANAGER::lightsLibrary.at(GLOBAL::LISTLIGHTSWINDOW::activeItemIndex);
        GLOBAL::ADDLIGHTWINDOW::isWindowActive           = true;
        GLOBAL::LISTLIGHTSWINDOW::isWindowActive         = false;
        GLOBAL::ADDLIGHTWINDOW::cameFromListLightsWindow = true;
        GLOBAL::ADDLIGHTWINDOW::isEditMode               = true;
    }

    style.Colors[ImGuiCol_Button]        = red_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = red_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = red_ImGuiCol_ButtonActive;

    ImGui::SetCursorPos(ImVec2(_size.x - 3 * saveMargin - 3 * ImGui::CalcTextSize("Cancel").x - 6 * saveMargin,
                               _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    if (ImGui::Button("Delete",
                      ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin))/* || ImGui::IsKeyPressed(ImGuiKey_Delete)*/)
    {
        // std::string lightName = GLOBAL::LIGHTFILEMANAGER::lightsLibrary.at(GLOBAL::LISTLIGHTSWINDOW::activeItemIndex).name;
        LightFileManager::deleteLightByIndex(GLOBAL::LISTLIGHTSWINDOW::activeItemIndex);
    }

    style.Colors[ImGuiCol_Button]        = default_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = default_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = default_ImGuiCol_ButtonActive;

    style.Colors[ImGuiCol_Button]        = red_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = red_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = red_ImGuiCol_ButtonActive;

    // ImGui::SetCursorPos(ImVec2(_size.x - saveMargin - ImGui::CalcTextSize("Cancel").x - 2 * saveMargin, _size.y -
    // ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    ImGui::SetCursorPos(ImVec2(saveMargin, _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    if (ImGui::Button("Cancel",
                      ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin))/* || ImGui::IsKeyPressed(ImGuiKey_Escape)*/)
    {
        GLOBAL::LISTLIGHTSWINDOW::isWindowActive         = false;
        GLOBAL::ADDLIGHTWINDOW::cameFromListLightsWindow = false;
    }

    style.Colors[ImGuiCol_Button]        = default_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = default_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = default_ImGuiCol_ButtonActive;

    ImGui::PopFont();

    _idealWindowSize =
        ImVec2(io_width - 2 * saveMargin, io_height - GLOBAL::HEADERWINDOW::size.y - GLOBAL::HEADERWINDOW::pos.y - 2 * saveMargin);
}