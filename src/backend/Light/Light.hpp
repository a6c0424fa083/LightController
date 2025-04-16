//
//  Light.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2024-12-14.
//

#ifndef LIGHT_HPP
#define LIGHT_HPP


#include <array>
#include <cstring>
#include <imgui.h>

#include "backend/Light/ChannelFunction/ChannelFunction.hpp"
#include "backend/defines.hpp"
#include "frontend/BaseWindow.hpp"


/**
 * @brief This struct defines a light
 *
 * <b>Featuring mainly:</b>
 * - rootAddress
 * - channelCount
 * - channelFunction[]
 * - name[]
 * - manufacturer[]
 * - universe
 */
struct Light
{
    ImVec4           color                                       = BaseWindow::default_ImGuiCol_Button;
    ImVec2           arrangePos                                  = ImVec2(0.0f, 0.0f);
    uint16_t         rootAddress                                 = 1;
    uint16_t         channelCount                                = 0;
    CHANNEL_FUNCTION channelFunction[512]                        = { CHANNEL_FUNCTION::CHANNEL };
    uint8_t          channelFunctionIdentifier[512]              = { 0 };
    uint8_t          universe                                    = 0;
    char             name[MAX_LIGHT_NAME_LENGTH]                 = { 0 };
    char             manufacturer[MAX_LIGHT_MANUFACTURER_LENGTH] = { 0 };
    bool             colorShown                                  = false;
    bool             lightArranged                               = false;

    /**
     * @brief This is the default constructor of the struct leaving the default values
     */
    Light() {}

    /**
     * @brief This constructor copies the data from one source to the light
     * while using a different root address
     * @param source A reference to an existing light
     * @param rootAddr A new root address
     */
    Light(const Light &source, const uint16_t rootAddr)
    {
        channelCount = source.channelCount;
        rootAddress  = rootAddr;
        std::copy(std::begin(source.channelFunction), std::end(source.channelFunction), channelFunction);
        std::copy(std::begin(source.channelFunctionIdentifier), std::end(source.channelFunctionIdentifier), channelFunctionIdentifier);
        std::strncpy(name, source.name, MAX_LIGHT_NAME_LENGTH);
        std::strncpy(manufacturer, source.manufacturer, MAX_LIGHT_MANUFACTURER_LENGTH);
        universe      = source.universe;
        color         = source.color;
        colorShown    = source.colorShown;
        lightArranged = source.lightArranged;
        arrangePos    = source.arrangePos;
    }
};


#endif  // LIGHT_HPP
