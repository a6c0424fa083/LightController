//
//  LibraryManagerWindow.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-13.
//

#ifndef LIBRARYMANAGERWINDOW_HPP
#define LIBRARYMANAGERWINDOW_HPP


#include <imgui.h>

#include <backend/GLOBAL.hpp>
#include <backend/defines.hpp>
#include <frontend/BaseWindow.hpp>

class LibraryManagerWindow : BaseWindow
{
public:
    ~LibraryManagerWindow();

    void Draw(ImVec2 pos, ImVec2 size);
    void DrawContents();

private:
    ImVec2 _pos;
    ImVec2 _size;
};



#endif  // LIBRARYMANAGERWINDOW_HPP
