# ColorView

A tiny, single-file terminal tool to display colors from hex codes, rgb and bgr as colored blocks. True Color terminals supported.  

## Features

- Display colors from **hex codes**, **RGB and BGR decimal inputs**
- Minimal, single-file implementation.  
- Works on True Color compatible terminals (Kitty, GNOME Terminal, etc.).  

## Usage

```bash
./colorview 0xFF4500   # Shows a block with the color
./colorview FFA07A     # Also supported without 0x prefix
./colorview -rgb 255 244 143   # you can use "-rgb" flag for decimal input
./colorview -bgr 123 123 123     # you can use "-bgr" flag for bgr decimal input
