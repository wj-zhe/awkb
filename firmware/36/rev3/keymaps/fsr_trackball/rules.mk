# Pointing device
POINTING_DEVICE_ENABLE = yes
ifeq ($(strip $(POINTING_DEVICE_ENABLE)), yes)
	POINTING_DEVICE_DRIVER = pmw3360
	MOUSEKEY_ENABLE = yes
endif

# FSR Sensor
ANALOG_DRIVER_REQUIRED = yes

# Encoder
ENCODER_ENABLE = yes

# RGBLIGHT
RGBLIGHT_ENABLE = yes       # keyboard RGB underglow

# Tap-Dance config
TAP_DANCE_ENABLE = yes      # Enable Tap-Dance feature

# Combo config
COMBO_ENABLE = yes          # Enable COMBO feature

# Auto Shift
AUTO_SHIFT_ENABLE = yes

# Key Override
KEY_OVERRIDE_ENABLE = yes

# Send string
SEND_STRING_ENABLE = yes

# Console debug
CONSOLE_ENABLE = yes
