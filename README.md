# Gruvw QMK keyboard

My custom QMK keyboard layout.

Checkout my layout cheatsheet: [keymap_help.txt](./keymap_help.txt)

<!-- TODO rebase main to before QMK fork -->

## Setup

1. Follow the QMK setup instructions: <https://docs.qmk.fm/newbs_getting_started>
2. Setup the QMK home to a given (absolute) path on your computer: `qmk setup -H <path>/qmk_firmware` (accept prompts)
3. Go to `qmk_firmware/keyboards/beekeeb` and empty the directory's content.
4. Clone this repository to `qmk_firmware/keyboards/beekeeb`: `git clone https://github.com/gruvw/keyboard.git .`
5. Compile or flash the keyboard firmware: `qmk compile -kb beekeeb/piantor_pro -km gruvw`

Optionally set the keyboard and keymap:

- `qmk config user.keyboard=beekeeb/piantor_pro`
- `qmk config user.keymap=gruvw`
