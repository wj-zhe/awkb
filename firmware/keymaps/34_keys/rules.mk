# POINTING DEVICE config
POINTING_DEVICE_ENABLE = yes
ifeq ($(strip $(POINTING_DEVICE_ENABLE)), yes)
	POINTING_DEVICE_DRIVER = cirque_pinnacle_spi
	MOUSEKEY_ENABLE = yes
endif

# OLED
OLED_ENABLE = no
ifeq ($(strip $(OLED_ENABLE)), yes)
	OLED_DRIVER = SSD1306
endif

# RGBLIGHT
RGBLIGHT_ENABLE = no

# Tap-Dance config
TAP_DANCE_ENABLE = yes

# Combo config
COMBO_ENABLE = yes

# Auto Shift
AUTO_SHIFT_ENABLE = no

