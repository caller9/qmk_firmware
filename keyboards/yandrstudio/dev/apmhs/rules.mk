ALLOW_WARNINGS = yes

RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
SRC += analog.c
# DEBUG_MATRIX_SCAN_RATE_ENABLE = yes

CUSTOM_MATRIX = lite    # for using the A9 pin as matrix io
QUANTUM_SRC += matrix.c

KEYBOARD_SHARED_EP = yes   # Free up some extra endpoints - needed if console+mouse+extra
