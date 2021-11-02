#include "../includes/scan.hpp"


/*
scan.cpp
Date: 11/01/21
Author: 0x1CA3
*/


bool NetworkScanning::network_scanning(char *net_ssid) {
    char buf[1024];

    DWORD lpi;
    HANDLE hold;
    DOT11_SSID name;

    PWLAN_INTERFACE_INFO list;
    PWLAN_AVAILABLE_NETWORK n_list;
    PWLAN_INTERFACE_INFO_LIST info_list;
    PWLAN_AVAILABLE_NETWORK_LIST net_list;

    WlanOpenHandle(2, NULL, &lpi, &hold);
    WlanEnumInterfaces(hold, NULL, &info_list);
    
    list = &info_list->InterfaceInfo[info_list->dwIndex];
    WlanGetAvailableNetworkList(hold, &list->InterfaceGuid, 0, NULL, &net_list);

    for (int i = 0; i < net_list->dwNumberOfItems; i++) {
        n_list = &net_list->Network[i];
        name = n_list->dot11Ssid;
        sprintf(buf, "%s", name.ucSSID);
        if (strstr(buf, net_ssid) != NULL) {
            std::cout << "Alert: Network " << net_ssid << " was found!\n" << std::endl;
            return true;
        }
    }
    return false;
}