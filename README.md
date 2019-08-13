# node-dell-fan
A nodejs library to control fan speed of dell PCs.Windows only.

Licensed under GPLv3.

Signed driver file by [AaronKelley/DellFanCmd](https://github.com/AaronKelley/DellFanCmd "AaronKelley/DellFanCmd").

Dell SMM IO driver by [424778940z/bzh-windrv-dell-smm-io](https://github.com/424778940z/bzh-windrv-dell-smm-io "424778940z/bzh-windrv-dell-smm-io")

## Before using

The author of [AaronKelley/DellFanCmd](https://github.com/AaronKelley/DellFanCmd "AaronKelley/DellFanCmd") purchased a digital code-signing certificate to sign the Dell SMM I/O driver by 424778940z so that "test signing mode" or the "disable driver signature enforcement" option is not required. However, because the driver does not have an EV certificate from Microsoft, it will not load if UEFI secure boot is enabled so you must take additional steps. The easiest way is to import this registry file:

```
Windows Registry Editor Version 5.00

[HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\CI\Policy]
"UpgradedSystem"=dword:00000000
```

## API

to be continued...

## Examples

see the `examples` folder.