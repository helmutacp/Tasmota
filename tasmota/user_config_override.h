// tasmota/user_config_override.h~

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// force the compiler to show a warning to confirm that this file is included
#warning **** user_config_override.h: Using Settings from this File ****

// ***********************************************
// ** Global settings for all binaries ***********

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "IOT"				// [Ssid1] Wifi SSID
#undef  STA_PASS1

#undef  MY_LANGUAGE
#define MY_LANGUAGE            de_DE			// German in Germany

#undef  APP_TIMEZONE
#define APP_TIMEZONE           99			// [Timezone] +1 hour (Amsterdam) (-13 .. 14 = hours from UTC, 99 = use TIME_DST/TIME_STD)

#ifdef USE_DOMOTICZ
#undef USE_DOMOTICZ
#endif

#ifdef USE_EMULATION_HUE 
#undef USE_EMULATION_HUE 
#endif

#ifdef USE_EMULATION_WEMO
#undef USE_EMULATION_WEMO
#endif

#ifdef USE_DEVICE_GROUPS
#undef USE_DEVICE_GROUPS
#endif

#ifdef USE_SHELLY_DIMMER
#undef USE_SHELLY_DIMMER
#endif

#ifdef USE_LIGHT
#undef USE_LIGHT
#endif

#ifdef USE_SPI
#undef USE_SPI
#endif

#ifdef USE_ENERGY_SENSOR
#undef USE_ENERGY_SENSOR
#endif

#ifdef USE_IR_REMOTE
#undef USE_IR_REMOTE
#endif

#ifdef USE_AUTOCONF
#undef USE_AUTOCONF
#endif

#ifdef USE_BERRY 
#undef USE_BERRY
#endif

#define USER_BACKLOG "ntpserver1 192.168.254.250; FullTopic %topic%/%prefix%/"


#undef MQTT_HOST
#define MQTT_HOST              "192.168.254.250"	// [MqttHost]
#undef MQTT_USER
#define MQTT_USER              "mqtt"       		// [MqttUser] MQTT user
#undef MQTT_PASS 

// ***********************************************
// ** Firmware specific settings *****************

// -- Options for firmware tasmota-SERIAL and tasmota32-SERIAL ------
#ifdef FIRMWARE_SERIAL
    // This line will issue a warning during the build (yellow in 
    // VSCode) so you see which section is used
    #warning **** Build: SERIAL ****
    // -- CODE_IMAGE_STR is the name shown between brackets on the 
    //    Information page or in INFO MQTT messages
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "SERIAL"

    #undef MQTT_HOST
    #define MQTT_HOST              "192.168.254.251"	// [MqttHost]
    #undef MQTT_USER
    #define MQTT_USER              "mqtt"       		// [MqttUser] MQTT user
    #undef MQTT_PASS 
    

    // Put here your override for firmware tasmota-SERIAL
    #ifndef USE_TCP_BRIDGE
	#define USE_TCP_BRIDGE
    #endif

    #ifdef USE_I2C 
	#undef USE_I2C
    #endif


#endif

// -- Options for firmware tasmota-THERMO ------
#ifdef FIRMWARE_THERMO
    #warning **** Build: THERMO ****
    #undef CODE_IMAGE_STR
    #define CODE_IMAGE_STR "thermo"

    // Put here your override for firmware tasmota-THERMO

    #undef MQTT_HOST
    #define MQTT_HOST              "192.168.254.250"	// [MqttHost]
    #undef MQTT_USER
    #define MQTT_USER              "mqtt"       		// [MqttUser] MQTT user
    #undef MQTT_PASS 
    
    #ifndef USE_MCP9808
	#define USE_MCP9808      // [I2cDriver51] Enable MCP9808 temperature sensor (I2C addresses 0x18 - 0x1F) (+0k9 code)
    #endif

    #ifndef USE_HTU
	#define USE_HTU     // [I2cDriver51] Enable USE_HTU... temperature sensor (I2C addresses 0x18 - 0x1F) (+0k9 code)
    #endif

    #ifndef USE_HDC1080
	#define USE_HDC1080     // [I2cDriver51] Enable USE_HDC1080 temperature sensor (I2C addresses 0x18 - 0x1F) (+0k9 code)
    #endif

    /*Tasmota Settings:
	In the Configuration -> Configure Module page assign:
	GPIOx to I2C SDA  D2
	GPIOy to I2C SCL  D1*/
#endif

#endif  // _USER_CONFIG_OVERRIDE_H_
