/*
  user_config_override.h - user configuration overrides user_config.h for Sonoff-Tasmota

  Copyright (C) 2018  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// force the compiler to show a warning to confirm that this file is inlcuded
#warning **** user_config_override.h: Using Settings from this File ****

/*****************************************************************************************************\
 * ATTENTION: - Changes to most PARAMETER defines will only override flash settings if you change
 *              define CFG_HOLDER.
 *            - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *            - You still need to update user_config.h for major defines MODULE and USE_MQTT_TLS.
 *            - Changing MODULE defines are not being tested for validity as they are in user_config.h.
 *            - Most parameters can be changed online using commands via MQTT, WebConsole or serial.
 *            - So I see no use in this but anyway, your on your own.
\*****************************************************************************************************/

/*
Examples :

// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4617                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "YourSSID"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "YourWifiPassword"     // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "your-mqtt-server.com" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "YourMqttUser"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "YourMqttPass"         // [MqttPassword] Optional password


// You might even pass some parameters from the command line ----------------------------
// Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

#ifdef MY_IP
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS   MY_IP                  // Set to 0.0.0.0 for using DHCP or IP address
#endif

#ifdef MY_GW
#undef  WIFI_GATEWAY
#define WIFI_GATEWAY      MY_GW                  // if not using DHCP set Gateway IP address
#endif

#ifdef MY_DNS
#undef  WIFI_DNS
#define WIFI_DNS          MY_DNS                 // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

*/



/*********************************************************************************************\
 *  CUSTOM PRARMS
\*********************************************************************************************/

// *******************    Enable Burning Man *************************//
// #define USE_BURNING_MAN       
//// Disable BM/RPI Setup
// #ifdef USE_BURNING_MAN 
// #undef USE_BURNING_MAN 
// #endif
// *******************  END Enable Burning Man *************************//

#define MQTT_PREFIX                 "tasmota"
#define TASMOTA_VERSION                "6.2.1"          // used in OTA URL
#define FIREWALL_IP                "192.168.200.107"          // EMH, IP address of firewall.local

#ifdef USE_BURNING_MAN
#undef  FIREWALL_IP 
#define FIREWALL_IP            "192.168.100.1"

#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS        "192.168.100.10"                  // [IpAddress1] Set to 0.0.0.0 for using DHCP or IP address

#undef  WIFI_GATEWAY
#define WIFI_GATEWAY           "192.168.100.1"   // [IpAddress2] If not using DHCP set Gateway IP address

#undef  WIFI_SUBNETMASK 
#define WIFI_SUBNETMASK        "255.255.255.0"   // [IpAddress3] If not using DHCP set Network mask

#undef  WIFI_DNS 
#define WIFI_DNS               "192.168.100.1"    // [IpAddress4] If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

// -- Device  -------------------------------------
// DEVICE is the generic type of hardware/device, ie. 
//   Sonoff Basic -> sonoff-basic 
//   Sonoff Slampher -> sonoff-slampher
// #define DEVICE_TYPE  "sonoff-basic"   
// #define DEVICE_TYPE  "sonoff-slampher"   
// #define DEVICE_TYPE  "sonoff-b1"   
// #define DEVICE_TYPE  "sonoff-pro"   
// #define DEVICE_TYPE  "sonoff-basic"   
// #define DEVICE_TYPE  "sonoff-dev"   
// #define DEVICE_TYPE  "sonoff-sv"   
// #define DEVICE_TYPE  "node-mcu"   

// #define DEVICE_TYPE  "wemos-d1-mini"   
// #define DEVICE_TYPE  "wemos-d1-pro"
// #define DEVICE_TYPE  "sonoff-sc"   
// #define DEVICE_TYPE  "sonoff-rf-bridge"   
// #define DEVICE_TYPE  "sonoff-rf"   
// #define DEVICE_TYPE  "sonoff-s31"   
// #define DEVICE_TYPE  "sonoff-12v1ch"   


// #define IS_WEMOS_D1_MINI  "04"  
// #define IS_SONOFF_SV      "02"  
// #define IS_SONOFF_DEV      "01"  
// #define IS_SONOFF_SC      "01"  
#define IS_SONOFF_SLAMPHER   "01"
// #define IS_SONOFF_B1      "01"  
// #define IS_SONOFF_RF      "01"  
// #define IS_SONOFF_S31      "03"  
// #define IS_SONOFF_RF_BRIDGE      "01"  

// -- Device Number  -------------------------------------
// DEVICE_NUM identifies the particular device
// #define DEVICE_NUM  "01"
// #define DEVICE_NUM  "02"
// #define DEVICE_NUM  "03"
// #define DEVICE_NUM  "04"
// #define DEVICE_NUM  "05"
// #define DEVICE_NUM  "06"

/*********************************************************************************************\
 *  Disable Tasmota Features
\*********************************************************************************************/ 
//  ####################       RULES  ####################
#define USE_RULES                                // Add support for rules (+4k4 code)
// #undef USE_RULES                                // Remove support for rules

//  ####################          Enable ADC/Analog Read, ususally disabled ####################
//// -- Internal Analog input -----------------------
//// #define USE_ADC_VCC                              // Display Vcc in Power status. Disable for use as Analog input on selected devices
//// 	1. recompile the program after you enable ADC input in file user_config.h by adding two slashes in front of line 159:
//// //#define USE_ADC_VCC
//// 	1. Once the program is loaded you need to select another module as the Sonoff Basic does not support ADC input.
////   Open de confiuration web page and select module Wemos D1 mini. This enables ADC by default. You will have to add all 
////   standard Sonoff Basic IO as defined in file sonoff_template.h near line 240/247.
//// Example with yet to release new version:
#define USE_ADC_VCC                              // Display Vcc in Power status. Disable for use as Analog input on selected devices
// #undef USE_ADC_VCC                                 // Enable ADC/Analog read on A0
/*********************************************************************************************\
 *  END Disable Tasmota Features
\*********************************************************************************************/


// #define MY_WIFI_CONFIG_TOOL       WIFI_MANAGER    // [WifiConfig] Default tool if wifi fails to connect
// #define WIFI_CONFIG_TOOL       WIFI_WAIT  // [WifiConfig] Default tool if wifi fails to connect
                                                 //   (WIFI_RESTART, WIFI_SMARTCONFIG, WIFI_MANAGER, WIFI_WPSCONFIG, WIFI_RETRY, WIFI_WAIT)


#ifdef IS_WEMOS_D1_MINI
#define DEVICE_TYPE  "wemos-d1-mini"   
#define DEVICE_NUM  IS_WEMOS_D1_MINI
#define MY_WIFI_CONFIG_TOOL       WIFI_WAIT
#define MY_USE_DISPLAY 
#endif

#ifdef IS_SONOFF_SV
#define DEVICE_TYPE  "sonoff-sv"
#define DEVICE_NUM  IS_SONOFF_SV
#define MY_WIFI_CONFIG_TOOL       WIFI_WAIT
#define MY_MQTT_USER        DEVICE_TYPE "-" DEVICE_NUM       
#endif

#ifdef IS_SONOFF_SC
#define DEVICE_TYPE  "sonoff-sc"
#define DEVICE_NUM  IS_SONOFF_SC
#define MY_WIFI_CONFIG_TOOL       WIFI_MANAGER  
#endif

#ifdef IS_SONOFF_SLAMPHER   
#define DEVICE_TYPE  "sonoff-slampher"
#define DEVICE_NUM  IS_SONOFF_SLAMPHER 
#define MY_WIFI_CONFIG_TOOL       WIFI_MANAGER  
#endif

#ifdef IS_SONOFF_B1
#define DEVICE_TYPE  "sonoff-b1"
#define DEVICE_NUM  IS_SONOFF_B1
#define MY_WIFI_CONFIG_TOOL       WIFI_MANAGER  
#endif

#ifdef IS_SONOFF_RF
#define DEVICE_TYPE  "sonoff-rf"
#define DEVICE_NUM  IS_SONOFF_RF
#define MY_WIFI_CONFIG_TOOL       WIFI_MANAGER  
#endif

#ifdef IS_SONOFF_RF_BRIDGE
#define DEVICE_TYPE  "sonoff-rf-bridge"
#define DEVICE_NUM  IS_SONOFF_RF_BRIDGE
#define MY_WIFI_CONFIG_TOOL       WIFI_MANAGER  
#endif

#ifdef IS_SONOFF_S31
#define DEVICE_TYPE  "sonoff-s31"
#define DEVICE_NUM  IS_SONOFF_S31
#define MY_WIFI_CONFIG_TOOL       WIFI_MANAGER  
#endif

#ifdef IS_SONOFF_DEV
#define DEVICE_TYPE  "sonoff-dev"
#define DEVICE_NUM  IS_SONOFF_DEV
#define MY_WIFI_CONFIG_TOOL       WIFI_MANAGER  
#endif

/*********************************************************************************************\
 *  END CUSTOM PRARMS
\*********************************************************************************************/




//  ####################  PROJECT  ####################
#undef PROJECT
//  PROJECT used in MQTT Topic
//#define PROJECT                "sonoff_basic_01"          // PROJECT is used as the default topic delimiter and OTA file name
//#define PROJECT                "wemos_mini_d1_01"          // PROJECT is used as the default topic delimiter and OTA file name
//#define PROJECT                "sonoff_slampher_01"          // PROJECT is used as the default topic delimiter and OTA file name
#define PROJECT          DEVICE_TYPE "-" DEVICE_NUM            //  sonoff_slampher_01
//  #################### END  PROJECT  ####################

// #define FRIENDLY_NAME          "Sonoff"          // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa
#undef  FRIENDLY_NAME
#define FRIENDLY_NAME         DEVICE_TYPE "-" DEVICE_NUM            //  sonoff-slampher-01

#undef  WIFI_HOSTNAME
#define WIFI_HOSTNAME         DEVICE_TYPE "-" DEVICE_NUM            //  sonoff-slampher-01

// -- Location ------------------------------------
// #define LATITUDE               48.858360         // [Latitude] Your location to be used with sunrise and sunset
// #define LONGITUDE              2.294442          // [Longitude] Your location to be used with sunrise and sunset
#undef  LATITUDE
#define LATITUDE                 45.5155037        // [Latitude] Your location to be used with sunrise and sunset
#undef  LONGITUDE
#define LONGITUDE                -122.6412267        // [Longitude] Your location to be used with sunrise and sunset

// -- Application ---------------------------------
// #define APP_TIMEZONE           1                 // [Timezone] +1 hour (Amsterdam) (-13 .. 14 = hours from UTC, 99 = use TIME_DST/TIME_STD)
#undef  APP_TIMEZONE
#define APP_TIMEZONE           -8                 // [Timezone] +1 hour (Amsterdam) (-13 .. 14 = hours from UTC, 99 = use TIME_DST/TIME_STD)
// #define TEMP_CONVERSION        0                 // [SetOption8] Return temperature in (0 = Celsius or 1 = Fahrenheit)
#undef  TEMP_CONVERSION
#define TEMP_CONVERSION        1                 // [SetOption8] Return temperature in (0 = Celsius or 1 = Fahrenheit)




//  ####################  WIFI ####################
#undef WIFI_GATEWAY
#define WIFI_GATEWAY           FIREWALL_IP 

#undef WIFI_DNS
#define WIFI_DNS               FIREWALL_IP

#undef STA_SSID1
#define STA_SSID1              "TrumpForPrez"      // [Ssid1] Wifi SSID

#undef STA_PASS1
#define STA_PASS1              "Palladium1"  // [Password1] Wifi password

#undef  STA_SSID2
#define STA_SSID2              "iPhone6"                // [Ssid2] Optional alternate AP Wifi SSID

#undef  STA_PASS2
#define STA_PASS2              "999999999"                // [Password2] Optional alternate AP Wifi password



#undef WIFI_CONFIG_TOOL
#define WIFI_CONFIG_TOOL       MY_WIFI_CONFIG_TOOL  // [WifiConfig] Default tool if wifi fails to connect
// #define WIFI_CONFIG_TOOL       WIFI_MANAGER    // [WifiConfig] Default tool if wifi fails to connect
// #define WIFI_CONFIG_TOOL       WIFI_WAIT  // [WifiConfig] Default tool if wifi fails to connect
                                                 //   (WIFI_RESTART, WIFI_SMARTCONFIG, WIFI_MANAGER, WIFI_WPSCONFIG, WIFI_RETRY, WIFI_WAIT)
//  #################### END WIFI ####################


//  ####################  SYSLOG  ####################
#undef SYS_LOG_HOST
#define SYS_LOG_HOST           FIREWALL_IP          // [LogHost] (Linux) syslog host
//  #################### END SYSLOG  ####################


//  ####################  OTA  ####################
#undef OTA_URL
// #define OTA_URL                "http://domus1:80/api/arduino/" PROJECT ".ino.bin"  // [OtaUrl]
// #define OTA_URL                "http://" FIREWALL_IP ":8000/tasmota/api/sonoff_firmware/" PROJECT ".ino.bin"  // [OtaUrl]
// http://firewall.local:5000/tasmota/5.14.0/sonoff-s31-03.bin
#define OTA_URL                "http://" FIREWALL_IP ":5000/tasmota/" TASMOTA_VERSION "/" PROJECT ".bin"  // [OtaUrl]
//  #################### END OTA  ####################


//  ####################  MQTT  ####################
#undef MQTT_HOST
#define MQTT_HOST            FIREWALL_IP          // [MqttHost]

#undef MQTT_PORT
#define MQTT_PORT            1883              // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef MQTT_USER
#define MQTT_USER            "sonoff"       // [MqttUser] Optional user

#ifdef MY_MQTT_USER
#undef MQTT_USER
#define MQTT_USER           MY_MQTT_USER   
#endif

#undef MQTT_PASS
#define MQTT_PASS            "Iridium1"       // [MqttPassword] Optional password

#undef MQTT_FULLTOPIC
#define MQTT_FULLTOPIC       "tasmota/%prefix%/%topic%/" // [FullTopic] Subscribe and Publish full topic name - Legacy topic

#undef USE_HOME_ASSISTANT
#define USE_HOME_ASSISTANT                       // Enable Home Assistant Discovery Support (+1k4 code)

#undef HOME_ASSISTANT_DISCOVERY_PREFIX
#define HOME_ASSISTANT_DISCOVERY_PREFIX "homeassistant"  // Default Home Assistant discovery prefix is 'homeassistant'
//#define HOME_ASSISTANT_DISCOVERY_PREFIX "tasmota"      // Nope, switching this back to the default.
#undef  MQTT_BUTTON_RETAIN    
#define MQTT_BUTTON_RETAIN     1                 // [ButtonRetain] Button may send retain flag (0 = off, 1 = on)

#undef  MQTT_SWITCH_RETAIN
#define MQTT_SWITCH_RETAIN     1                 // [SwitchRetain] Switch may send retain flag (0 = off, 1 = on)

#undef MQTT_TELE_RETAIN    
#define MQTT_TELE_RETAIN     1                   // Tele messages may send retain flag (0 = off, 1 = on)

#ifdef MQTT_PREFIX
// #define MQTT_PREFIX  "tas"   
// #define MQTT_TOPIC   "w-mini-" DEVICE_NUM
#undef MQTT_FULLTOPIC
#define MQTT_FULLTOPIC       MQTT_PREFIX "/%prefix%/%topic%/" // [FullTopic] Subscribe and Publish full topic name - Legacy topic
#endif


//  #################### END MQTT  ####################

//  #################### BM WIFI ####################
#ifdef USE_BURNING_MAN 

#undef  STA_SSID1 
#define STA_SSID1              "TentAssistant"      // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1              "Iridium1"  // [Password1] Wifi password

#undef STA_SSID2
#define STA_SSID2              "TrumpForPrez"      // [Ssid1] Wifi SSID

#undef STA_PASS2
#define STA_PASS2              "Palladium1"  // [Password1] Wifi password

#undef WIFI_CONFIG_TOOL
#define WIFI_CONFIG_TOOL       WIFI_WAIT // [WifiConfig] Default tool if wifi fails to connect
                                                 //   (WIFI_RESTART, WIFI_SMARTCONFIG, WIFI_MANAGER, WIFI_WPSCONFIG, WIFI_RETRY, WIFI_WAIT)

#undef MQTT_USER
#define MQTT_USER            "sonoff"       // [MqttUser] Optional user

#undef MQTT_PASS
#define MQTT_PASS            "Iridium1"       // [MqttPassword] Optional password

#endif
//  #################### END BM WIFI ####################






/*********************************************************************************************\
 * END OF SECTION 1
 *
 * SECTION 2
 * - Enable a feature by removing both // in front of it
 * - Disable a feature by preceding it with //
\*********************************************************************************************/

//#define USE_ARDUINO_OTA                          // Add optional support for Arduino OTA (+13k code)

// -- Localization --------------------------------
  // If non selected the default en-GB will be used
//#define MY_LANGUAGE            bg-BG           // Bulgarian in Bulgaria
//#define MY_LANGUAGE            cs-CZ           // Czech in Czech
//#define MY_LANGUAGE            de-DE           // German in Germany
//#define MY_LANGUAGE            el-GR           // Greek in Greece
//#define MY_LANGUAGE            en-GB           // English in Great Britain. Enabled by Default
//#define MY_LANGUAGE            es-AR           // Spanish in Argentina
//#define MY_LANGUAGE            fr-FR           // French in France
//#define MY_LANGUAGE            hu-HU           // Hungarian in Hungary
//#define MY_LANGUAGE            it-IT           // Italian in Italy
//#define MY_LANGUAGE            nl-NL           // Dutch in the Netherlands
//#define MY_LANGUAGE            pl-PL           // Polish in Poland
//#define MY_LANGUAGE            pt-BR           // Portuguese in Brazil
//#define MY_LANGUAGE            pt-PT           // Portuguese in Portugal
//#define MY_LANGUAGE            ru-RU           // Russian in Russia
//#define MY_LANGUAGE            uk-UK           // Ukrainian in Ukrain
//#define MY_LANGUAGE            zh-CN           // Chinese (Simplified) in China
//#define MY_LANGUAGE            zh-TW           // Chinese (Traditional) in Taiwan

/*-------------------------------------------------------------------------------------------*\
 * Select ONE of possible three MQTT library types below
\*-------------------------------------------------------------------------------------------*/
#undef MQTT_LIBRARY_TYPE
  // Default MQTT driver for both non-TLS and TLS connections. Blocks network if MQTT server is unavailable.
// #define MQTT_LIBRARY_TYPE      MQTT_PUBSUBCLIENT   // Use PubSubClient library

  // Alternative MQTT driver does not block network when MQTT server is unavailable. No TLS support
#define MQTT_LIBRARY_TYPE      MQTT_TASMOTAMQTT    // Use TasmotaMqtt library (+4k4 code, +4k mem) - non-TLS only
  // Alternative MQTT driver does not block network when MQTT server is unavailable. No TLS support
//#define MQTT_LIBRARY_TYPE      MQTT_ESPMQTTARDUINO // Use (patched) esp-mqtt-arduino library (+4k8 code, +4k mem) - non-TLS only

#define USE_SENSORS                              // Create sonoff-sensors with useful sensors enabled

#ifdef MY_USE_DISPLAY
#define USE_DISPLAY                            // Add I2C Display Support (+2k code)
#define USE_DISPLAY_SSD1306                  // [DisplayModel 2] Enable SSD1306 Oled 128x64 display (I2C addresses 0x3C and 0x3D) (+16k code)
#undef USE_DISPLAY_MODES1TO5
// -- SPI sensors ---------------------------------
// #define USE_SPI                                  // SPI using library TasmotaTFT
#endif  // MY_USE_DISPLAY

#ifdef USE_SPI
  #ifndef USE_DISPLAY
  #define USE_DISPLAY                            // Add SPI Display support for 320x240 and 480x320 TFT
  #endif
    #define USE_DISPLAY_ILI9341                  // [DisplayModel 4] Enable ILI9341 Tft 480x320 display (+19k code)
//    #define USE_DISPLAY_EPAPER                   // [DisplayModel 5] Enable e-paper display (+19k code)
#endif  // USE_SPI
#endif  // _USER_CONFIG_OVERRIDE_H_