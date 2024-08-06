CUSTOM_MATRIX = lite
SRC += matrix.c

ifeq ($(strip $(OLED_ENABLE)), yes)
	OLED_DRIVER = SSD1306
endif
