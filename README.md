# wio-e5-base-pio-proyect

This repository is intended to use as a base project to use the [Wio-E5 / LoRa-E5 module](https://wiki.seeedstudio.com/LoRa-E5_STM32WLE5JC_Module/) with platformio using the stm32cube 
framework.

## Framework Configuration

In order to add the wioE5 as a module compatible with STM32cube framework, the following procedure must be followed.

1.- Install PlatformIO IDE extension on Visual Studio Code.

2.- Clone this repository at your preferences path. A folder with the name "wio-e5-base-pio-proyect" should have been created.

3.- Using VSCode, open the cloned repository at ``File -> Open Folder...`` and select the folder of the repository recently cloned. A folder named "ststm32" should have been created in `/.platformio/platforms`.

4.- Create a file called wioe5.json in `/.platformio/platforms/ststm32/boards` with the following code:

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
        "openocd_target": "stm32wlx",
        "svd_path": "STM32WLE5_CM4.svd"
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

5.- Clone the [STM32CubeWL](https://github.com/STMicroelectronics/STM32CubeWL) repository at `/.platformio/packages`. To clone this repository, option ``--recursive`` has to be specified. Please refer to the "How to use" section of the repository for more details.


6.- At ``/.platformio/platforms/ststm32``, modify platform.json file adding the following entry in the packages section:

    "framework-stm32cubewl": {
        "type": "framework",
        "optional": true,
        "owner": "platformio",
        "version": "symlink://$PATH_TO_THE_STM3CubeWL_REPO"
        },

``$PATH_TO_THE_STM3CubeWL_REPO`` must be something like ``/home/user/.platformio/packages/STM32CubeWL``

7.- Add a file called package.json to the cloned STM32CubeWL folder (``/.platformio/packages/STM32CubeWL``) with the following contents:

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

8.- At this point, on VSCode compile to check. If everything is OK, continue with the next steps.

9.- Install [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html) software. A STMicroelectronics account must be created.

10.- Open ``STM32CubeProgrammer``, connect ST-LINK with the STM32 board to your PC, then click "Connect". The firt time you connect the devices it could give an error. Try again holding RESET Button of your device, then click "Connect" and release RESET Button.


![STM32CubeProgrammer Connection](https://files.seeedstudio.com/wiki/LoRa-E5_Development_Kit/wiki%20images/program1.png)
Image source: [seeed studio](https://wiki.seeedstudio.com/LoRa-E5_STM32WLE5JC_Module/)


11.- On Option Bytes (OB), make sure the Read Out Protection is ``AA``, if it is shown as ``BB``, select ``AA`` and click "Apply". This step disable Read Out Protection.


![AA Read Out Protection](https://files.seeedstudio.com/wiki/LoRa-E5_Development_Kit/wiki%20images/program2.png)
Image source: [seeed studio](https://wiki.seeedstudio.com/LoRa-E5_STM32WLE5JC_Module/)


12.- Finally, with ST-LINK and STM32 board connected to your PC, on VSCode select "upload". If everything is OK, LoRa-E5 module default firmware is erased and the code from this base project is uploaded, the device can now be programmed using platformio!.
