# Custom switch matrix
CUSTOM_MATRIX = lite
SRC += matrix.c

# POINTING DEVICE config
ifeq ($(strip $(POINTING_DEVICE_ENABLE)), yes)
	POINTING_DEVICE_DRIVER = cirque_pinnacle_spi
endif

# OLED config
ifeq ($(strip $(OLED_ENABLE)), yes)
	OLED_DRIVER = SSD1306
endif
