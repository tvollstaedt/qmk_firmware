# Quantum Mechanical Keyboard Firmware

This is repository contains my modified keyboard layout for the ErgoDox EZ.  Since the USB HID design does not allow remapping of the second (ie shift) layer, I'm using a standard QWERTZ in conjunction with my modified version of the NeoVars windows driver. See [here](https://github.com/tvollstaedt/neovars_but) for more details.

My current layout is [PUQ](http://adnw.de/index.php?n=Main.OptimierungF%C3%BCrDieGeradeTastaturMitDaumen-Shift), which is an experimental branch of the [ADNW](http://adnw.de), uses 30 keys and is optimized for german and english.

![PUQ](http://adnw.de/uploads/Main/OptimierungF%c3%bcrDieGeradeTastaturMitDaumen-Shift/puqd640.png "PUQ")

See `keyboards/ergodox/keymaps/tvollstaedt` for details.

## Prerequisites

* [Docker](https://www.docker.com/)


## Build

```{r, engine='bash', count_lines}
$ docker-compose up
```

See the [original QMK repository](https://github.com/jackhumbert/qmk_firmware) for more information and native build instructions.

