# Custom switch matrix
CUSTOM_MATRIX = lite
SRC += matrix.c

# OLED config
ifeq ($(strip $(OLED_ENABLE)), yes)
	OLED_DRIVER = SSD1306
endif
