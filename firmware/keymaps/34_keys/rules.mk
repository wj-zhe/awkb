# Pointing device
POINTING_DEVICE_ENABLE = no
ifeq ($(strip $(POINTING_DEVICE_ENABLE)), yes)
	MOUSEKEY_ENABLE = yes
endif

# OLED
OLED_ENABLE = no

# RGBLIGHT
RGBLIGHT_ENABLE = no       # keyboard RGB underglow

# Tap-Dance config
TAP_DANCE_ENABLE = yes      # Enable Tap-Dance feature

# Combo config
COMBO_ENABLE = yes          # Enable COMBO feature
VPATH += keyboards/gboards

# Auto Shift
AUTO_SHIFT_ENABLE = no

