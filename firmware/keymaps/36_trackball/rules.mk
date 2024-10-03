# Pointing device
POINTING_DEVICE_ENABLE = yes
ifeq ($(strip $(POINTING_DEVICE_ENABLE)), yes)
	POINTING_DEVICE_DRIVER = pmw3360
	MOUSEKEY_ENABLE = yes
endif

# Encoder
ENCODER_ENABLE = yes
ifeq ($(strip $(ENCODER_ENABLE)), yes)
	ENCODER_MAP_ENABLE = no
endif

# RGBLIGHT
RGBLIGHT_ENABLE = yes       # keyboard RGB underglow

# Tap-Dance config
TAP_DANCE_ENABLE = yes      # Enable Tap-Dance feature

# Combo config
COMBO_ENABLE = yes          # Enable COMBO feature

# Auto Shift
AUTO_SHIFT_ENABLE = no
