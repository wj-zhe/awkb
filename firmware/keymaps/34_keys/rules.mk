# Pointing device
POINTING_DEVICE_ENABLE = no
ifeq ($(strip $(POINTING_DEVICE_ENABLE)), yes)
	MOUSEKEY_ENABLE = yes
endif

# RGBLIGHT
RGBLIGHT_ENABLE = yes       # keyboard RGB underglow

# Tap-Dance config
TAP_DANCE_ENABLE = yes      # Enable Tap-Dance feature

# Combo config
COMBO_ENABLE = yes          # Enable COMBO feature

# Auto Shift
AUTO_SHIFT_ENABLE = no

