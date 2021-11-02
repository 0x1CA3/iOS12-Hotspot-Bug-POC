<h1 align="center">
    iOS 12.1.2 b3 Hotspot Bug POC
</h1>
<p align="center">
	A pretty useless POC I had fun writing for a weird, but harmless bug that makes your screen shake rapidly. I found this while playing around with the hotspot settings in iOS 12.1.2 b3.
</p>

<p align="center">
	<a href="https://deno.land" target="_blank">
    	<img src="https://img.shields.io/badge/Version-1.0.0-7DCDE3?style=for-the-badge" alt="Version">
</p>
  
## Guide & Setup
```
Compile
---------------
g++ -o main main.cpp -lwlanapi
Usage: main.exe <network_ssid> <network_adapter>

Steps:
Authenticate with your iDevice hotspot
Disconnect from it, then change the password of the hotspot
Run the POC with valid arguments
```

## Credits
```
https://github.com/0x1CA3
```
### Contributions 🎉
###### All contributions are accepted, simply open an Issue / Pull request.
