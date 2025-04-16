//
//  USB.hpp
//  LightController
//  https://github.com/a6c0424fa083/LightController
//
//  Created by Jannis Sauer on 2025-03-30.
//

#ifndef USB_HPP
#define USB_HPP

#include <cstdio>
#include <libusb.h>

class USB
{
public:
    inline USB(size_t   txBufferSize,
               size_t   rxBufferSize,
               uint16_t vendorId,
               uint16_t productId,
               uint8_t  endpointIn,
               uint8_t  endpointOut,
               uint8_t  interfaceNumber,
               uint8_t  timeout_ms) :
        txBufferSize(txBufferSize),
        rxBufferSize(rxBufferSize),
        vendorId(vendorId),
        productId(productId),
        endpointIn(endpointIn),
        endpointOut(endpointOut),
        interfaceNumber(interfaceNumber),
        timeout_ms(timeout_ms)
    {
        txBuffer = new uint8_t[txBufferSize];
        rxBuffer = new uint8_t[rxBufferSize];
    }
    ~USB();

    uint8_t  tryOpenDevice();
    void  closeDevice();
    uint8_t  tryRead();
    uint8_t  tryWrite();
    uint8_t *getTxBufferBPtr() { return txBuffer; }
    uint8_t *getRxBufferBPtr() { return rxBuffer; }

private:
    libusb_context       *context;
    libusb_device_handle *handle;
    size_t                txBufferSize;
    size_t                rxBufferSize;
    uint8_t              *txBuffer;
    uint8_t              *rxBuffer;
    uint16_t              vendorId;
    uint16_t              productId;
    uint8_t               endpointIn;
    uint8_t               endpointOut;
    uint8_t               interfaceNumber;
    uint16_t              timeout_ms;
    int                   transferred;
    int                   status;
};



#endif  // USB_HPP
