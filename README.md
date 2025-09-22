# Safety Example for Infineon TRAVEO T2G Series

This repository contains examples for the [Infineon Kit T2G-B-H_Lite](https://www.keil.arm.com/packs/kit_t2g-b-h_lite_bsp-infineon).

The examples are configured for [Keil Studio for VS Code](https://www.keil.arm.com/).

## Quick Start

1. Install [Keil Studio for VS Code](https://marketplace.visualstudio.com/items?itemName=Arm.keil-studio-pack) from the VS Code marketplace.
2. Clone this Git repository into a VS Code workspace.
3. Open the CMSIS View in VS Code and use the ... menu *Select Active Solution from workspace* to choose a example.
4. The related tools and software packs are downloaded and installed. *View - Output - CMSIS Solution* shows the progress.
5. Using the [Action buttons in the CMSIS View](https://github.com/ARM-software/vscode-cmsis-csolution?tab=readme-ov-file#action-buttons) allows you to build, load and debug the example on the Infineon Kit.

## Examples

### App/T2G

The structure of the [App/T2G.csolution.yml](./App/T2G.csolution.yml) safety example is shown below. It contains:

- [App/CM0p_Boot/Boot.cproject.yml](./App/CM0p_Boot/Boot.cproject.yml) implements a simple setup for the various processors and runs on the Cortex-M0+ processor of the device.
- [App/CM7_0_TrafficLight/TrafficLight.cproject.yml](./App/CM7_0_TrafficLight/TrafficLight.cproject.yml) implements the safety-critical application part using [FuSa RTS](https://developer.arm.com/Tools%20and%20Software/Keil%20MDK/FuSa%20Run-Time%20System) and runs on the Cortex-M7 processor #0.
- [App/CM7_1_Blinky/Blinky.cproject.yml](./App/CM7_1_Blinky/Blinky.cproject.yml) blinks an LED and could be replaced with non-safety application part and runs on the Cortex-M7 processor #1.

![App_T2G Safety Example](./Doc/App_T2G.png "App_T2G Safety Example")

- The [CM7_0_TrafficLight](./App/CM7_0_TrafficLight/TrafficLight.cproject.yml) uses safety classes to project the critical safe-mode operation. It provides a web server that interacts with the user and allows to inject faults for testing the system recovery features. This part of the example is based on the application note [KAN336 - TrafficLight: Arm FuSa RTS process isolation example](https://developer.arm.com/documentation/kan336/latest).

### Test/Ethernet/DriverTest

The Infineon DFP/BSP software packs do not contain a [CMSIS-Driver Ethernet](https://arm-software.github.io/CMSIS_6/latest/Driver/group__eth__interface__gr.html) or [board software layers](https://open-cmsis-pack.github.io/cmsis-toolbox/ReferenceApplications/#board-layer). These components are therefore developed separately and provided in this repository.

The [Test/Ethernet/DriverTest.csolution.yml](./Test/Ethernet/DriverTest.csolution.yml) validates the CMSIS-Driver Ethernet with the [CMSIS-Driver_Validation](https://github.com/ARM-software/CMSIS-Driver_Validation) pack.

## File and Directory Structure

This is a list of the relevant files and directories.

File/Directory                            | Content
:-----------------------------------------|:---------------------------------------------------------
[vcpkg-configuration.json](./vcpkg-configuration.json) | Defines the tools that [Arm Tools Environment Manager](https://marketplace.visualstudio.com/items?itemName=Arm.environment-manager) installs in VS Code.
[App](./App)                              | [App/T2G](#appt2g) contains the safety example.
[Doc](./Doc)                              | Documentation files.
[Test/Ethernet](./Test/Ethernet)          | [Test/Ethernet/DriverTest](#testethernetdrivertest) contains the validation for the CMSIS-Driver Ethernet.

## Webinar

This example was explained in the following webinar:

*TODO*: Add link to webinar.

## Issues or Questions

Use the **Issues** tab to raise questions or issues.
