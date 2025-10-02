# Patch for T2G-B-H_DFP pack

**CMSIS Ethernet driver** needs the access to the variable `cy_ethif_privatedata`, defined in the `cy_ethif.c` file in the **T2G-B-H_DFP** pack.

To enable this, apply the `cy_ethif.c.patch` to the file `cy_ethif.c` in the folder `%CMSIS_PACK_ROOT%\Infineon\T2G-B-H_DFP\1.2.1\Libraries\mtb-pdl-cat1\drivers\source`. 


These steps are included in the github CI workflow `Build_T2G_Release.yaml`: 

1. Copy the file `cy_ethif.c.patch` to the folder `%CMSIS_PACK_ROOT%\Infineon\T2G-B-H_DFP\1.2.1\Libraries\mtb-pdl-cat1\drivers\source`.

2. Apply the patch with the GitBash command:

    ```bash
    git apply cy_ethif.c.patch
    ```

