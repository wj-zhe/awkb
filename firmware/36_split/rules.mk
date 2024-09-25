SERIAL_DRIVER = vendor

CUSTOM_MATRIX = lite
SRC += matrix.c

ifeq ($(strip $(POINTING_DEVICE_ENABLE)), yes)
	# POINTING_DEVICE_DRIVER = cirque_pinnacle_spi
	POINTING_DEVICE_DRIVER = pmw3360
	MOUSEKEY_ENABLE = yes
endif
