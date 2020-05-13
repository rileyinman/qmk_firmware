SRC += muse.c

### Build Options ###
# NOTE: Disables legacy style macros/functions
LINK_TIME_OPTIMIZATION_ENABLE = yes

# Bootmagic lets you hold keys during startup to enable special behavior
BOOTMAGIC_ENABLE = no

# Disable "magic" commands such as toggling debugging or nkro
COMMAND_ENABLE = no

# Allows printing messages to hid_listen
CONSOLE_ENABLE = no

# Fancy interactive terminal - doesn't do much yet
TERMINAL_ENABLE = no

### Hardware Options ###
# Enable MIDI controls
MIDI_ENABLE = yes

# Enable underglow LEDs
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = WS2812

# Enables KC_LOCK modifier
KEY_LOCK_ENABLE = yes

# NOTE: Takes up 3 endpoints
STENO_ENABLE = yes

# "Space Cadet" is special casing MT mods -> brackets
SPACE_CADET_ENABLE = no

# Enable ~fancy~ unicode features
UNICODE_ENABLE = yes
