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
    // core data
    uint16_t         channelCount         = 0;
    CHANNEL_FUNCTION channelFunction[512] = { CHANNEL_FUNCTION::CHANNEL };
    // uint8_t          channelFunctionIdentifier[512]              = { 0 };
    char name[MAX_LIGHT_NAME_LENGTH]                 = { 0 };
    char manufacturer[MAX_LIGHT_MANUFACTURER_LENGTH] = { 0 };

    // instance data
    uint8_t  universe      = 0;
    uint16_t rootAddress   = 1;  // based of the dmx protocol (byte 0 is reserved for the start frame)
    ImVec4   color         = BaseWindow::default_ImGuiCol_Button;
    ImVec2   arrangePos    = ImVec2(0.0f, 0.0f);
    bool     lightArranged = false;
    // uint64_t buffer; // for future stuff

    /**
     * @brief This is the default constructor of the struct leaving the default values
     */
    Light() {}

    /**
     * @brief This constructor copies the core data from one source to the light
     * while using a different instance parameters
     * @param source A reference to an existing light
     * @param rootAddr A new root address
     */
    Light(const Light &source, const uint16_t rootAddr)
    {
        channelCount = source.channelCount;
        std::copy(std::begin(source.channelFunction), std::end(source.channelFunction), channelFunction);
        // std::copy(std::begin(source.channelFunctionIdentifier), std::end(source.channelFunctionIdentifier),
        // channelFunctionIdentifier);
        std::strncpy(name, source.name, MAX_LIGHT_NAME_LENGTH);
        std::strncpy(manufacturer, source.manufacturer, MAX_LIGHT_MANUFACTURER_LENGTH);

        universe      = source.universe;
        rootAddress   = rootAddr;
        color         = source.color;
        arrangePos    = source.arrangePos;
        lightArranged = source.lightArranged;
    }
} __attribute__((packed));


#endif  // LIGHT_HPP
