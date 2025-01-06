//
//  GLOBAL.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-11.
//

#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <cstdint>
#include <string>
#include <vector>
#include <filesystem>

#include <imgui.h>

#include "backend/Light/Light.hpp"
#include "backend/Patch/Patch.hpp"


namespace GLOBAL
{
    namespace KEYHANDLER
    {
        inline bool isKeyDown_Escape    = false;
        inline bool isKeyDown_Enter     = false;
        inline bool isKeyDown_A         = false;
        inline bool isKeyDown_E         = false;
        inline bool isKeyDown_Delete    = false;
        inline bool isKeyDown_UpArrow   = false;
        inline bool isKeyDown_DownArrow = false;
    };  // namespace KEYHANDLER

    namespace HEADERWINDOW
    {
        inline std::vector<std::string> sections = { "Patch", "CH Control", "Scene Editor", "Live", "Settings" };

        inline uint8_t activeSection    = sections.size() - 1;  // set last element (= settings) to active
        inline uint8_t progressBarProg  = 255;                  // 0 - 255
        inline auto    progressBarColor = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);
        inline auto    size             = ImVec2(0.0f, 0.0f);
        inline auto    pos              = ImVec2(0.0f, 0.0f);
    };  // namespace HEADERWINDOW

    namespace ADDLIGHTWINDOW
    {
        inline bool  isWindowActive           = false;
        inline bool  cameFromListLightsWindow = false;
        inline bool  isEditMode               = false;
        inline Light lightToEdit              = Light {};
    };  // namespace ADDLIGHTWINDOW

    namespace LIGHTFILEMANAGER
    {
        inline std::vector<Light> lightsLibrary;
    };

    namespace LISTLIGHTSWINDOW
    {
        inline bool   isWindowActive  = false;
        inline size_t activeItemIndex = 0;
    };  // namespace LISTLIGHTSWINDOW

    namespace CREATEPROJECTWINDOW
    {
        inline bool isWindowActive = false;
        inline bool isEditMode     = false;
        inline auto activeProjectPath = std::filesystem::path("../applicationData/Projects/");
    };  // namespace CREATEPROJECTWINDOW

    namespace PATCH
    {
        /**
         * @brief Index is starting from 0
         * vector index 4 -> dmx address 5
         */
        inline auto patchButtons = std::vector(512, PatchButton {});
        inline std::vector<Light> patchLights;
    };  // namespace PATCH

    namespace SELECTLIGHTWINDOW
    {
        inline auto     light                  = Light {};
        inline bool     selectionValid         = false;
        inline bool     isWindowActive         = false;
        inline uint16_t referenceButtonAddress = 0;
        inline size_t   activeItemIndex        = 0;
    };  // namespace SELECTLIGHTWINDOW

    namespace LIGHTINFOWINDOW
    {
        inline bool isWindowActive = false;
        inline size_t lightIndex = -1;
        inline uint16_t referenceButtonAddress = 0;
    };

    namespace PROJECT {
        inline std::vector<std::filesystem::path> projects;
        inline size_t activeProjectIndex = 0;
    };

};  // namespace GLOBAL



#endif  // GLOBAL_HPP
