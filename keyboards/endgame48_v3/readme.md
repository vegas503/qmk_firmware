# endgame48

```
                 ┌────────┐
          ╭──────┤        ├──────╮
     RGB> ┿ D3   │        │  RAW ┿
          │      │        │      │
    PS2D> ┿ D2   └────────┘  GND ┿
          │                      │
          ┿ GND              RST ┿
          │      []      []      │
          ┿ GND              VCC ┿
          │                      │
     I2C> ┿ D1   ||| ||  ||   F4 ┿ <ROW5
          │                      │
     I2C> ┿ D0                F5 ┿ <COL1
          │          ╱╲          │
    ROW1> ┿ D4      ╱  ╲      F6 ┿ <COL2
          │        ╱    ╲        │
    ROW3> ┿ C6     ╲    ╱     F7 ┿ <COL3
          │         ╲  ╱         │
    COL7> ┿ D7       ╲╱       B1 ┿ <COL4
          │                      │
    ENCA> ┿ E6                B3 ┿ <COL5
          │                      │
    ENCB> ┿ B4                B2 ┿ <COL6
          │                      │
    ROW2> │ B5 B7 D5 C7 F1 F0 B6 ┿ <ROW6
          ╰────╂──╂──╂──╂──╂─────╯
               ┃  ┃     ┃  ┃
          ROW4 ┛  ┃     ┃  ┗ ROW8
                  ┃     ┃
             PS2C ┛     ┗ ROW7
```
