#include "../includes/auth.hpp"


/*
auth.cpp
Date: 11/01/21
Author: 0x1CA3
*/


bool Authentication::network_authentication(char *net_ssid, char *n_adapter) {
    FILE *pcommand;
    
    char data[5000];
    char command[1024] = "netsh wlan connect name=";
    
    strcat(command, net_ssid);
    strcat(command, " interface=");
    strcat(command, n_adapter);
    
    pcommand = popen(command, "r");
    if (pcommand == NULL) {
        return false;
    } else {
        while (fgets(data, sizeof(data), pcommand) != NULL) {
            if (strcmp(data, "There is no such wireless interface on the system.") == 0) {
                return false;
            }
        }
    }
    return true;
}