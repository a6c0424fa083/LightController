//
//  USB.cpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2025-03-30.
//

#include "USB.hpp"

uint8_t USB::tryOpenDevice()
{
    handle = libusb_open_device_with_vid_pid(context, vendorId, productId);
    if (!handle)
    {
        fprintf(stderr, "Could not open device\n");
        return 1;
    }

    libusb_claim_interface(handle, interfaceNumber);

    return 0;
}
void USB::closeDevice()
{
    libusb_release_interface(handle, interfaceNumber);
    libusb_close(handle);
    libusb_exit(context);
}
uint8_t USB::tryRead()
{
    return libusb_bulk_transfer(handle, endpointIn, rxBuffer, static_cast<int>(rxBufferSize), &transferred, timeout_ms);
}
uint8_t USB::tryWrite()
{
    return libusb_bulk_transfer(handle, endpointOut, txBuffer, static_cast<int>(txBufferSize), &transferred, timeout_ms);
}