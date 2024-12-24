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

#include "backend/Light/ChannelFunction/ChannelFunction.hpp"
#include "backend/defines.hpp"

struct Light
{
    uint16_t         channelCount                                = 0;
    uint16_t         rootAddress                                 = 1;
    CHANNEL_FUNCTION channelFunction[512]                        = { CHANNEL_FUNCTION::CHANNEL };
    uint8_t          channelFunctionIdentifier[512]              = { 0 };
    char             name[MAX_LIGHT_NAME_LENGTH]                 = { 0 };
    char             manufacturer[MAX_LIGHT_MANUFACTURER_LENGTH] = { 0 };

    Light() {}

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

inline void printLightStruct(const Light &light) {
    printf("\n#################################### LIGHT ####################################\n");
    printf("\nchannelCount:  %64d\n", light.channelCount);
    printf("\n rootAddress:  %64d\n", light.rootAddress);
    printf("\n        name:  %64.64s\n", light.name);
    printf("\nmanufacturer:  %64.64s\n\n\n", light.manufacturer);
}


#endif  // LIGHT_HPP
