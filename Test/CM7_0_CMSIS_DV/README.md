# CMSIS-Driver Validation for Ethernet Driver on Infineon KIT_T2G-B-H_LITE

This project provides a configured setup for the **Ethernet driver** validation on the **Infineon KIT_T2G-B-H_LITE** board.

---

## Configuration

- Validation tests are configured in the **`DV_ETH_Config.h`** file.

---

## Documentation

For detailed information on Ethernet driver validation, refer to the official documentation:
- [CMSIS Ethernet Driver Validation Guide](https://arm-software.github.io/CMSIS-Driver_Validation/latest/group__dv__eth.html)

---

## Usage Instructions

Follow these steps to run the validation tests:

1. Open the **CMSIS_DV solution** in the Visual Studio Code.
2. Connect a [loopback plug](https://arm-software.github.io/CMSIS-Driver_Validation/latest/group__dv__eth.html) to the Ethernet connector on the board.
3. Connect the board to your PC via the on-board debugger.
4. Build and run the validation tests.
5. Review the verification results in the **STDIO console**, **Virtual COM Port** on this board.
