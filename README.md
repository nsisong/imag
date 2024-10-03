# imag


Imag ESPx WiFi  manager with fallback web configuration portal



**This works with the ESP8266 Arduino platform**



**This works with the ESP32 Arduino platform** 



### Known Issues
* Documentation needs to be updated, see 
-------

## Contents
 - [How it works](#how-it-works)
 - [Wishlist](#wishlist)
 - [Quick start](#quick-start)
   - Installing
     - [Arduino - Through Library Manager](#install-through-library-manager)
     - [Arduino - From Github](#checkout-from-github)
   - [Using](#using)
 - [Imag Documentation](https://docs.google.com/document/d/15MYyEy_XMKgHgfcuLzsKZoK8uSbzEaIy_ABtCRZvOrs/edit?usp=sharing)
   


## How It Works
- When your ESP starts up, it sets it up in Station mode and tries to connect to a previously saved Access Point
- if this is unsuccessful (or no previous network saved) it moves the ESP into Access Point mode and spins up a DNS and WebServer 
- using any wifi enabled device with a browser (computer, phone, tablet) connect to the newly created Access Point
- because of the Captive Portal and the DNS server you will either get a 'Join to network' type of popup or get any domain you try to access redirected to the configuration portal
- choose one of the access points scanned, enter password, click save
- ESP will try to connect. If successful, it relinquishes control back to your app. If not, reconnect to AP and reconfigure.
- There are options to change this behavior or manually start the configportal and webportal independantly as well as run them in non blocking mode.

## How It Looks
[ESP8266 WiFi Captive Portal Homepage]

## TODO
- [x] remove dependency on EEPROM library
- [x] move HTML Strings to PROGMEM
- [x] cleanup and streamline code (although this is ongoing)
- [x] if timeout is set, extend it when a page is fetched in AP mode
- [x] add ability to configure more parameters than ssid/password
- [x] maybe allow setting ip of ESP after reboot
- [x] add to Arduino Library Manager
- [x] add to PlatformIO
- [x] add multiple sets of network credentials
- [x] allow users to customize CSS
- [x] rewrite documentation for simplicity, based on scenarios/goals
- [x] ESP32 support
- [x] rely on the SDK's built in auto connect more than forcing a connect
- [x] add non blocking mode
- [x] easy customization of strings
- [x] hostname support
- [x] fix various bugs and workarounds for esp SDK issues
- [x] additional info page items
- [x] last status display / faiilure reason
- [x] customizeable menu
- [x] seperate custom params page
- [x] ondemand webportal
- [x] complete refactor of code to segment functions
- [x] wiif scan icons or percentage display
- [x] invert class for dark mode
- [x] more template tokens
- [x] progmem for all strings
- [x] new callbacks
- [x] new callouts / filters
- [x] shared web server instance
- [x] latest esp idf/sdk support
- [x] wm is now non persistent, will not erase or change stored esp config on esp8266
- [x] tons of debugging output / levels
- [x] disable captiveportal
- [x] preload wiifscans, faster page loads
- [x] softap stability fixes when sta is not connected


## Quick Start

### Installing
