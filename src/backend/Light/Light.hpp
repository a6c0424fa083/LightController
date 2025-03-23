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


/**
 * @brief This struct defines a light
 *
 * <b>Featuring:</b>
 * - channelCount
 * - rootAddress
 * - channelFunction[]
 * - channelFunctionIdentifier[] (currently not used)
 * - name[]
 * - manufacturer[]
 */
struct Light
{
    uint16_t         channelCount                                = 0;
    uint16_t         rootAddress                                 = 1;
    CHANNEL_FUNCTION channelFunction[512]                        = { CHANNEL_FUNCTION::CHANNEL };
    uint8_t          channelFunctionIdentifier[512]              = { 0 };
    char             name[MAX_LIGHT_NAME_LENGTH]                 = { 0 };
    char             manufacturer[MAX_LIGHT_MANUFACTURER_LENGTH] = { 0 };
    uint8_t          universe                                    = 0;
    ImVec4           color                                       = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
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
    }
};


#endif  // LIGHT_HPP
