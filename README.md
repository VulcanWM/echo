# Echo

This is my first hardware project, in which I made a Simon Says game by designing a PCB and writing the firmware for it.

The components involved are a XIAO RP2040 as the microcontroller, 3 switches which represent the possible options the player has to press, 3 different coloured LEDs that light up when introducing the sequence, resistors to stop the LEDs from receiving too much current, and a buzzer so the game is not just vision-based but also audio-based.

There is also a CAD-designed case, consisting only of a bottom section. I felt that a top cover was unnecessary, as the buttons and LEDs need to remain clearly visible and accessible. The bottom case mainly protects the PCB while making the device easier and more comfortable to hold.

How the game works is:
- You press any button to start.
- It gives you a sequence of length 1 (while playing a tone and lighting up the corresponding LED).
- You then have to press the button that corresponds to the LED that just lit up.
- If you get that right, you are given a sequence of length 2, with one extra note added to the previous sequence.
- The game keeps going until you either get the sequence wrong (and hear a losing tune I created), or reach 100 rounds (and hear a victory tune I created).

I made it because I spend a lot of time on devices, so whenever I've been using one continuously for around an hour, I can take a break by playing this game. Since it's a memory game, it also helps me improve my focus.

## Images

The KiCad source files (`.kicad_pro`, `.kicad_sch`, `.kicad_pcb`) and `gerbers.zip` used to manufacture the PCB are located in the [`pcb-files`](pcb-files) folder.

This is what the schematic looks like:

![schematic](https://github.com/VulcanWM/echo/blob/main/images/schematic-echo.png)

This is what the PCB looks like:

![pcb](https://github.com/VulcanWM/echo/blob/main/images/pcb-echo.png)

This is what the PCB looks like in the 3D renderer:

![pcb 3d](https://github.com/VulcanWM/echo/blob/main/images/pcb3d-echo.png)

The Fusion CAD source files (`.step`, `.stl`, `.f3d`) used to manufacture the case can be found in the [`case-files`](case-files) folder.

This is what the case looks like (with the PCB inside it):

![pcb with case](https://github.com/VulcanWM/echo/blob/main/images/pcb-with-case.png)

## Firmware

The firmware contains the code for exactly what I explained in the how the game works' section and it was written in the Arduino IDE in C++. It is in the [echo.ino](https://github.com/VulcanWM/echo/blob/main/echo.ino) file.

## BOM
(Also in the [BOM.csv](https://github.com/VulcanWM/echo/blob/main/BOM.csv) file)

| Name | Qty | Link | Cost |
|------|----:|------|-----:|
| Seeed Studio XIAO RP2040 | 1 | https://www.seeedstudio.com/XIAO-RP2040-v1-0-p-5026.html | $3.90 |
| Gateron Milky Pro Yellow Switches (30-pack) | 1 | https://www.aliexpress.com/item/1005005322416424.html?spm=a2g0o.productlist.main.4.6fd6AJhcAJhcRR&algo_pvid=621a244a-f2c9-426e-b6be-1a73efd2c8c3&algo_exp_id=621a244a-f2c9-426e-b6be-1a73efd2c8c3-21&pdp_ext_f=%7B%22order%22%3A%2217%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21GBP%217.95%217.94%21%21%2110.31%2110.30%21%402103849717854352321456107e0d1a%2112000032623796818%21sea%21UK%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3Acec8671b%3Bm03_new_user%3A-29895%3BpisId%3A5000000212851917&curPageLogUid=xlVrQmQ6seaW&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005005322416424%7C_p_origin_prod%3A | $10.71 |
| DSA PBT 1U Keycaps (10-pack) | 1 | https://www.aliexpress.com/item/1005012418077180.html?spm=a2g0o.productlist.main.44.2c60uVRtuVRtVY&algo_pvid=b6b50a2a-433e-464b-94e8-dcf3317d2a18&algo_exp_id=b6b50a2a-433e-464b-94e8-dcf3317d2a18-43&pdp_ext_f=%7B%22order%22%3A%227%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21GBP%215.35%212.56%21%21%2146.85%2122.40%21%402103849717854356457228356e0d1a%2112000058315981392%21sea%21UK%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3Acec8671b%3Bm03_new_user%3A-29895%3BpisId%3A5000000211438706&curPageLogUid=owTJvLrJ00ZO&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005012418077180%7C_p_origin_prod%3A | $7.21 |
| 5mm Red LED | 1 | https://www.lcsc.com/product-detail/C52034661.html?s_z=n_q_5A4RUD&spm=wm.fly.bg.0.xh&lcsc_vid=QFQKVFAHRFdWVwBXQQdeU1IFFFddUQJQRlNXBlRQT1IxVlNeQlVdUlBfQVJYVjsOAxUeFF5JWBYZEEoKFBINSQcJGk4dAgUUFAk%3D | $0.41 |
| 5mm Blue LED | 1 | https://www.lcsc.com/product-detail/C52034724.html?s_z=s_p_5A4BUD&spm=wm.fly.bg.0.xh&lcsc_vid=QFQKVFAHRFdWVwBXQQdeU1IFFFddUQJQRlNXBlRQT1IxVlNeQlVdUlFeQFhWUTsOAxUeFF5JWBYZEEoKFBINSQcJGk4dAgUUFAk%3D | $0.64 |
| 5mm Yellow LED | 1 | https://www.lcsc.com/product-detail/C52034720.html?s_z=s_p_5A4YUD&spm=wm.fly.bg.0.xh&lcsc_vid=QFQKVFAHRFdWVwBXQQdeU1IFFFddUQJQRlNXBlRQT1IxVlNeQlVdUlFSQ1ZZUTsOAxUeFF5JWBYZEEoKFBINSQcJGk4dAgUUFAk%3D | $0.57 |
| 220Ω 1/4W Through-Hole Resistor (50-pack) | 1 | https://www.lcsc.com/product-detail/C127220.html?s_z=n_q_p_220%25CE%25A9%25201%252F4W%2520Through-Hole%2520Resistor&spm=wm.ssy.bg.2.xh&lcsc_vid=QFQKVFAHRFdWVwBXQQdeU1IFFFddUQJQRlNXBlRQT1IxVlNeQlVdU1xVT1hZVjsOAxUeFF5JWBYZEEoKFBINSQcJGk4dAgUUFAk%3D | $0.57 |
| TDK PS1240P02BT Piezo Transducer | 1 | https://www.lcsc.com/product-detail/C76871.html?s_z=n_q_p_TDK%2520PS1240P02BT%2520Piezo%2520Transducer&spm=wm.ssy.bg.0.xh&lcsc_vid=QFQKVFAHRFdWVwBXQQdeU1IFFFddUQJQRlNXBlRQT1IxVlNeQlVdU1JfQVBcXjsOAxUeFF5JWBYZEEoKFBINSQcJGk4dAgUUFAk%3D | $0.22 |
| Custom PCB (5 boards) | 1 | https://jlcpcb.com | $4.00 |
| Shipping | 1 | https://jlcpcb.com | ~$3.50 |
| **Estimated Total** |  |  | **~$31.73** |
