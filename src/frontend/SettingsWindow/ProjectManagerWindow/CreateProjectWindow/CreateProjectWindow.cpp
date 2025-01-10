//
//  CreateProjectWindow.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-21.
//

#include "CreateProjectWindow.hpp"

#include <backend/Light/LightFileManager/LightFileManager.hpp>
#include <backend/Project/Project.hpp>

CreateProjectWindow::~CreateProjectWindow() {}

void CreateProjectWindow::Draw(ImVec2 pos, ImVec2 size)
{
    _pos               = pos;
    _size              = size;
    io.FontGlobalScale = fontSize;

    ImGui::PushFont(NUMBER);
    setWindowPosSize(_pos, _size);

    ImGui::Begin("CreateProjectWindow", nullptr, STATIC__NO_VISUALS);

    DrawContents();

    ImGui::End();
    ImGui::PopFont();
}

void CreateProjectWindow::DrawContents()
{
    ProjectManager::loadProjectsToVector();


    static ImVec2 lastCursorPos;


    ImGui::PushFont(TITLE);
    ImGui::SetCursorPos(ImVec2(_size.x / 2.0f - ImGui::CalcTextSize("Configure Project").x / 2.0f, saveMargin));
    ImGui::Text("Configure Project");
    ImGui::PopFont();

    lastCursorPos = ImGui::GetCursorPos();

    // margin from addWindow
#define secondRowPosY (ImGui::CalcTextSize("Project Name: ").x + 2 * saveMargin)

    ImGui::SetCursorPos(ImVec2(saveMargin, lastCursorPos.y + saveMargin));
    ImGui::Text("Project Name: ");
    ImGui::SetCursorPos(ImVec2(secondRowPosY, lastCursorPos.y + saveMargin));
    ImGui::SetNextItemWidth(_size.x - secondRowPosY - saveMargin);
    ImGui::InputText("##ProjectName", _name, MAX_PROJECT_NAME_LENGTH);
    if (ImGui::IsItemActive()) GLOBAL::PROJECT::newProject = true;

    lastCursorPos = ImGui::GetCursorPos();

    ImGui::SetNextWindowPos(ImVec2(_pos.x + saveMargin, _pos.y + saveMargin + lastCursorPos.y));
    ImGui::BeginChild("ProjectsListWindowChild",
                      ImVec2(_size.x - 2 * saveMargin, _size.y - 6 * saveMargin - ImGui::CalcTextSize("XXX").y - lastCursorPos.y),
                      true,
                      ImGuiWindowFlags_AlwaysVerticalScrollbar);

    ImGui::PushFont(NUMBER);

    if (!GLOBAL::PROJECT::projects.empty())
    {
        for (size_t i = 0; i < GLOBAL::PROJECT::projects.size(); i++)
        {
            // if (GLOBAL::PROJECT::projects.at(i).extension() == ".LCproj") { ImGui::Text("%s",
            // GLOBAL::PROJECT::projects.at(i).stem().string().c_str()); }

            ImGui::PushID(static_cast<int>(i));  // Unique ID for each light container
            ImGui::SetCursorPos(
                ImVec2(saveMargin, saveMargin + static_cast<float>(i) * (ImGui::CalcTextSize("XXX").y + 3 * saveMargin)));


            if (GLOBAL::PROJECT::activeProjectIndex == i && !GLOBAL::PROJECT::newProject)
            {
                style.WindowBorderSize = 4 * default_WindowBorderSize;
                style.FrameBorderSize  = 4 * default_FrameBorderSize;
                style.ChildBorderSize  = 4 * default_ChildBorderSize;
            }

            ImGui::BeginChild("ProjectItem",
                              ImVec2(_size.x - 35.0f, ImGui::CalcTextSize("XXX").y + 2 * saveMargin),
                              true,
                              ImGuiWindowFlags_NoScrollbar);

            // Check for item click
            if (ImGui::IsWindowHovered() && ImGui::IsMouseClicked(0))
            {
                GLOBAL::PROJECT::activeProjectIndex = static_cast<int>(i);
                GLOBAL::PROJECT::newProject         = false;
            }

            // Display light details
            ImGui::SetCursorPos(ImVec2(_pos.x + saveMargin, ImGui::GetCursorPosY() + saveMargin));
            ImGui::Text("%s", GLOBAL::PROJECT::projects.at(i).stem().string().c_str());

            ImGui::EndChild();
            ImGui::PopID();

            if (GLOBAL::PROJECT::activeProjectIndex == i && !GLOBAL::PROJECT::newProject)
            {
                style.WindowBorderSize = default_WindowBorderSize;
                style.FrameBorderSize  = default_FrameBorderSize;
                style.ChildBorderSize  = default_ChildBorderSize;
            }

            ImGui::Spacing();  // Add some space between items
        }
    }

    ImGui::PopFont();

    ImGui::EndChild();



    ImGui::PushFont(SUBTITLE);

    style.Colors[ImGuiCol_Button]        = green_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = green_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = green_ImGuiCol_ButtonActive;

    ImGui::SetCursorPos(ImVec2(_size.x - saveMargin - ImGui::CalcTextSize("Cancel").x - 2 * saveMargin,
                               _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));


    if (ImGui::Button("Save",
                      ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin))/* ||
        (ImGui::IsKeyPressed(ImGuiKey_Enter) && !GLOBAL::KEYHANDLER::isKeyDown_Enter)*/)
    {
        // GLOBAL::KEYHANDLER::isKeyDown_Enter         = true;
        GLOBAL::CREATEPROJECTWINDOW::isWindowActive = false;
        ProjectManager::saveProject(std::string(_name));
    }

    style.Colors[ImGuiCol_Button]        = default_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = default_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = default_ImGuiCol_ButtonActive;

    ImGui::SetCursorPos(ImVec2(_size.x - 2 * saveMargin - 2 * ImGui::CalcTextSize("Cancel").x - 4 * saveMargin,
                               _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));


    if (ImGui::Button("Recall",
                      ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)))
    {
        // GLOBAL::KEYHANDLER::isKeyDown_Enter         = true;
        GLOBAL::CREATEPROJECTWINDOW::isWindowActive = false;
        if (!GLOBAL::PROJECT::newProject)
        {
            printf("jump in loadProject function\n");
            ProjectManager::recallProject(GLOBAL::PROJECT::activeProjectIndex);
        }
    }


    style.Colors[ImGuiCol_Button]        = red_ImGuiCol_Button;
    style.Colors[ImGuiCol_ButtonHovered] = red_ImGuiCol_ButtonHovered;
    style.Colors[ImGuiCol_ButtonActive]  = red_ImGuiCol_ButtonActive;

    ImGui::SetCursorPos(ImVec2(_size.x - 3 * saveMargin - 3 * ImGui::CalcTextSize("Cancel").x - 6 * saveMargin,
                               _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));

    if (ImGui::Button("Delete",
                      ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)))
    {
        ProjectManager::deleteProjectByIndex(GLOBAL::PROJECT::activeProjectIndex);
    }

    ImGui::SetCursorPos(ImVec2(saveMargin, _size.y - ImGui::CalcTextSize("XXX").y - 3 * saveMargin));
    if (ImGui::Button("Cancel",
                      ImVec2(ImGui::CalcTextSize("Cancel").x + 2 * saveMargin, ImGui::CalcTextSize("XXX").y + 2 * saveMargin)) ||
        (ImGui::IsKeyPressed(ImGuiKey_Escape) && !GLOBAL::KEYHANDLER::isKeyDown_Escape))
    {
        GLOBAL::KEYHANDLER::isKeyDown_Escape        = true;
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