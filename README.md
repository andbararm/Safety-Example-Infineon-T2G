# Safety Example for Infineon TRAVEO T2G Series

This repository contains examples for [Keil Studio](https://www.keil.arm.com/) that run on the [Infineon Kit T2G-B-H_Lite](https://www.keil.arm.com/packs/kit_t2g-b-h_lite_bsp-infineon).

## Quick Start

1. Install [Keil Studio for VS Code](https://marketplace.visualstudio.com/items?itemName=Arm.keil-studio-pack) from the VS Code marketplace.
2. Clone this Git repository into a VS Code workspace.
3. Open the CMSIS View in VS Code and use the ... menu *Select Active Solution from workspace* to choose a example.
4. The related tools and software packs are downloaded and installed. Review progress with *View - Output - CMSIS Solution*.
5. Using the [Action buttons in the CMSIS View](https://github.com/ARM-software/vscode-cmsis-csolution?tab=readme-ov-file#action-buttons) allows you to build, load and debug the example on the Infineon Kit.

## Examples

The examples can be explored using the [Keil MDK Community edition](https://www.keil.arm.com/keil-mdk/#mdk-v6-editions) that is free to use for training and evaluation. Instead of the commercial [FuSa RTS](https://developer.arm.com/Tools%20and%20Software/Keil%20MDK/FuSa%20Run-Time%20System) with is part of the [Keil MDK Professional edition](https://www.keil.arm.com/keil-mdk/#mdk-v6-editions) the open-source variant [Keil RTX](https://developer.arm.com/Tools%20and%20Software/Keil%20MDK/RTX5%20RTOS) is used for evaluation purposes.

### App/T2G

The [App/T2G.csolution.yml](./App/T2G.csolution.yml) safety example uses three processor cores and contains:

- [App/CM0p_Boot/Boot.cproject.yml](./App/CM0p_Boot/Boot.cproject.yml) implements a simple setup for the various processors and runs on the Cortex-M0+ processor of the device.
- [App/CM7_0_TrafficLight/TrafficLight.cproject.yml](./App/CM7_0_TrafficLight/TrafficLight.cproject.yml) implements the safety-critical application part using [FuSa RTS](https://developer.arm.com/Tools%20and%20Software/Keil%20MDK/FuSa%20Run-Time%20System) and runs on the Cortex-M7 processor #0.
- [App/CM7_1_Blinky/Blinky.cproject.yml](./App/CM7_1_Blinky/Blinky.cproject.yml) blinks an LED and could be replaced with non-safety application part and runs on the Cortex-M7 processor #1.

![App_T2G Safety Example](./Doc/App_T2G.png "App_T2G Safety Example")

The safety-critical application part [CM7_0_TrafficLight](./App/CM7_0_TrafficLight/TrafficLight.cproject.yml) uses safety classes to protect safe-mode operation. A web server that interacts with the user allows you to inject faults for testing the system recovery features. This part of the example is based on the application note [KAN336 - TrafficLight: Arm FuSa RTS process isolation example](https://developer.arm.com/documentation/kan336/latest).

### Test/Ethernet/DriverTest

The Infineon DFP/BSP software packs do not contain a [CMSIS-Driver Ethernet](https://arm-software.github.io/CMSIS_6/latest/Driver/group__eth__interface__gr.html) or [board software layers](https://open-cmsis-pack.github.io/cmsis-toolbox/ReferenceApplications/#board-layer). These components are therefore developed separately and provided in this repository.

The [Test/Ethernet/DriverTest.csolution.yml](./Test/Ethernet/DriverTest.csolution.yml) validates the CMSIS-Driver Ethernet with the [CMSIS-Driver_Validation](https://github.com/ARM-software/CMSIS-Driver_Validation) pack.

## Files and Directories

This is a list of the relevant files and directories.

File/Directory                            | Content
:-----------------------------------------|:---------------------------------------------------------
[vcpkg-configuration.json](./vcpkg-configuration.json) | Defines the tools that the [Arm Tools Environment Manager](https://marketplace.visualstudio.com/items?itemName=Arm.environment-manager) installs in VS Code.
[App](./App)                              | [App/T2G](#appt2g) contains the safety example.
[Doc](./Doc)                              | Documentation files.
[Test/Ethernet](./Test/Ethernet)          | [Test/Ethernet/DriverTest](#testethernetdrivertest) contains the validation for the CMSIS-Driver Ethernet.
[.ci](./.ci)                              | Contains setup for the CI test workflows.

## Git Workflow

This repository contains multiple *csolution projects* and is configured as a single Git workspace for VS Code. It can be therefore effectively used with the [VS Code Git integration](https://code.visualstudio.com/docs/sourcecontrol/overview). The following files achieve this:

- [vcpkg-configuration.json](./vcpkg-configuration.json) is in the workspace root directory and installs the tools for all *csolution projects*.
- [.gitignore](./.gitignore) excludes files that contain user specific setup, for example `.vscode` and `*.cbuild*.yml`.

## Continuous Integration (CI) Tests

The underlying build system of [Keil Studio](https://www.keil.arm.com/) uses the CMSIS-Toolbox and CMake. [CI](https://en.wikipedia.org/wiki/Continuous_integration) is effectively supported with:

- Tool installation based on a single [vcpkg-configuration.json](./vcpkg-configuration.json) file for desktop and CI environments.
- Project files (`*.csolution.yml`) that integrate in IDE and CI environments. Projects build seamless in CI, for example using GitHub actions.
- [Run and Debug Configuration](https://open-cmsis-pack.github.io/cmsis-toolbox/build-overview/#run-and-debug-configuration) for pyOCD that uses a single configuration file `*.cbuild-run.yml`. Using self-hosted GitHub runners, projects can be tested with [HIL systems](https://en.wikipedia.org/wiki/Hardware-in-the-loop_simulation).

## Webinar

This example will be explained in the [Keil Studio Webinar #5: Multicore and FuSa Development with TRAVEO™ T2G](https://www.arm.com/resources/webinar/keil-studio-session-5) with live Q&A on Tuesday, September 30, 2025.

## Issues or Questions

Use the [**Issues**](./issues) tab to raise questions or issues.
