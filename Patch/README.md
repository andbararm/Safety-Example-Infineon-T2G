# Patch for T2G-B-H_DFP pack

**CMSIS Ethernet driver** needs the access to the variable `cy_ethif_privatedata`, defined in the `cy_ethif.c` file in the **T2G-B-H_DFP** pack.

To enable this, copy the `cy_ethif.c.patch` file into `<packs root>/Infineon/T2G-B-H_DFP/1.2.1/Libraries/mtb-pdl-cat1/drivers/source` folder
and apply the patch to the `cy_ethif.c` file.

For example, with GitBash execute the command below in the folder where patch file was copied to:

```bash
git apply cy_ethif.c.patch
```

