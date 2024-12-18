//
//  ListLightsWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-18.
//

#include "ListLightsWindow.hpp"

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


    if (GLOBAL::LIGHTFILEMANAGER::lightsLibrary.empty()) { ImGui::Text("No lights available."); }

    ImGui::SetNextWindowPos(ImVec2(_pos.x + saveMargin, _pos.y + saveMargin));
    ImGui::BeginChild("ListLightsWindowChild",
                      ImVec2(_size.x - 2 * saveMargin, _size.y - 6 * saveMargin - ImGui::CalcTextSize("XXX").y),
                      true,
                      ImGuiWindowFlags_HorizontalScrollbar);

    for (size_t i = 0; i < GLOBAL::LIGHTFILEMANAGER::lightsLibrary.size(); ++i)
    {
        Light &light = GLOBAL::LIGHTFILEMANAGER::lightsLibrary.at(i);

        ImGui::PushID(static_cast<int>(i));  // Unique ID for each light container
        ImGui::SetNextWindowPos(ImVec2(_pos.x + 2 * saveMargin, _pos.y + 2 * saveMargin + static_cast<float>(i) * (ImGui::CalcTextSize("XXX").y + 5 * saveMargin)));
        ImGui::BeginChild("LightItem",
                          ImVec2(_size.x / 2.0f, 3 * ImGui::CalcTextSize("XXX").y + 4 * saveMargin),
                          true,
                          ImGuiWindowFlags_NoScrollbar);

        // Display light details
        ImGui::SetCursorPos(ImVec2(_pos.x + saveMargin, ImGui::GetCursorPosY() + saveMargin));
        ImGui::Text("Name: %s", light.name);
        ImGui::SameLine();
        ImGui::SetCursorPos(ImVec2(_pos.x + saveMargin, ImGui::GetCursorPosY() + ImGui::CalcTextSize("XXX").y + saveMargin));
        ImGui::Text("Manufacturer: %s", light.manufacturer);
        ImGui::SameLine();
        ImGui::SetCursorPos(ImVec2(_pos.x + saveMargin, ImGui::GetCursorPosY() + ImGui::CalcTextSize("XXX").y + saveMargin));
        ImGui::Text("Channels: %d", light.channelCount);
        ImGui::SameLine();
        ImGui::SetCursorPos(ImVec2(_pos.x + saveMargin, ImGui::GetCursorPosY() + ImGui::CalcTextSize("XXX").y + saveMargin));

        ImGui::EndChild();
        ImGui::PopID();

        ImGui::SetCursorPos(ImVec2(_pos.x + saveMargin, ImGui::GetCursorPosY() + ImGui::CalcTextSize("XXX").y + saveMargin));


        //ImGui::Spacing();  // Add some space between items
    }

    ImGui::EndChild();


    ImGui::PushFont(SUBTITLE);

    style.Colors[ImGuiCol_Button]        = red_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = red_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = red_ImGuiCol_ButtonActive;

    ImGui::SetCursorPos(ImVec2(_size.x - saveMargin - ImGui::CalcTextSize("Cancel").x - 2 * saveMargin,
                               _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    if (ImGui::Button("Cancel",
                      ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)))
    {
        GLOBAL::LISTLIGHTSWINDOW::isWindowActive = false;
    }

    style.Colors[ImGuiCol_Button]        = default_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = default_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = default_ImGuiCol_ButtonActive;

    ImGui::PopFont();

    _idealWindowSize =
        ImVec2(io_width - 2 * saveMargin, io_height - GLOBAL::HEADERWINDOW::size.y - GLOBAL::HEADERWINDOW::pos.y - 2 * saveMargin);
}