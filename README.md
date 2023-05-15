# wio-e5-base-pio-proyect

This repository is intended to use as a base proyect to use the [Wio-E5 / LoRa-E5 module](https://wiki.seeedstudio.com/LoRa-E5_STM32WLE5JC_Module/) with platformio using the stm32cube 
framework.

## framework configuration

In order to add the wioE5 as a module compatible with STM32cube framework the following procedure must be followed

1.- Copy the ststm32 repo to the platforms folder inside platformio folder .platform in my case since i’m using ubuntu 22 (This is done automatycally when you create a proyect that uses the ststm32cube platform)

2.- Create a file called wioe5.json inside the boards folder with the following code:

        {
        "build": {
            "core": "stm32",
            "cpu": "cortex-m4",
            "extra_flags": "-DSTM32WLxx -DSTM32WLE5xx",
            "f_cpu": "32000000L",
            "mcu": "stm32wle5jc",
            "product_line": "STM32WLE5xx"
        },
        "debug": {
            "default_tools": [
            "stlink"
            ],
            "jlink_device": "STM32WLE5JC",
            "onboard_tools": [
            "stlink"
            ],
            "openocd_target": "stm32wlex",
            "svd_path": "STM32WLE5x_CM4.svd"
        },
        "frameworks": [
            "stm32cube"
        ],
        "name": "Wio E5",
        "upload": {
            "maximum_ram_size": 65536,
            "maximum_size": 262144,
            "protocol": "stlink",
            "protocols": [
            "stlink"
            ]
        },
        "url": "https://wiki.seeedstudio.com/LoRa-E5_STM32WLE5JC_Module",
        "vendor": "Seeedstudio"
        }

3.- Clone the [STM32CubeWL](https://github.com/STMicroelectronics/STM32CubeWL) repo inside my packages folder inside the platformio folder.


4.- Modify the ststm32’s platform.json file adding the following entry in the packages section:

    "framework-stm32cubewl": {
        "type": "framework",
        "optional": true,
        "owner": "platformio",
        "version": "symlink://$PATH_TO_THE_STM3CubeWL_REPO"
        },

5.- Add a file called package.json to the cloned STM32CubeWL folder with the following contents.

    {
    "description": "STM32Cube is a set of tools and embedded software bricks available free of charge to enable fast and easy development on the STM32 platform (STM32CubeWL MCU Firmware Package)",
    "keywords": [
        "framework",
        "hal",
        "stm32",
        "st"
    ],
    "name": "framework-stm32cubewl",
    "version": "1.26.2",
    "homepage": "https://github.com/STMicroelectronics/STM32CubeWL"
    }

6.- Clone this repositoy to wherever you like and compile