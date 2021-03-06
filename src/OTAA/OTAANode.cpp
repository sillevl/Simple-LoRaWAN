/* The MIT License (MIT)
 *
 * Copyright (c) 2016 Sille Van Landschoot
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include "OTAANode.h"

uint8_t* simple_lorawan_dev_eui;
uint8_t* simple_lorawan_app_eui;
uint8_t* simple_lorawan_app_key;

void os_getArtEui(uint8_t *buf)
{
    memcpy(buf, (const void*) simple_lorawan_app_eui, 8);
}

void os_getDevEui(uint8_t *buf)
{
    memcpy(buf, (const void*) simple_lorawan_dev_eui, 8);
}

void os_getDevKey(uint8_t *buf)
{
    memcpy(buf, (const void*) simple_lorawan_app_key, 16);
}

namespace SimpleLoRaWAN
{
    
namespace OTAA
{
    
Node::Node(uint8_t _app_eui[], uint8_t _dev_eui[], uint8_t _app_key[]) : SimpleLoRaWAN::Node()
{
    simple_lorawan_dev_eui = _dev_eui;
    simple_lorawan_app_eui = _app_eui;
    simple_lorawan_app_key = _app_key;

    LMIC_startJoining();
    while(LMIC.devaddr == 0){
        process();
    };
}

Node::~Node()
{

}

}

}