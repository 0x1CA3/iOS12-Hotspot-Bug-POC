#include <iostream>
#include <wtypes.h>
#include <Windows.h>
#include <Wlanapi.h>

#pragma once


/*
scan.hpp
Date: 11/01/21
Author: 0x1CA3
*/


class NetworkScanning {
    public:
        bool network_scanning(char *net_ssid);
};