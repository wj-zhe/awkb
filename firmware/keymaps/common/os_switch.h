enum custom_keycodes {
    OS_TG = SAFE_RANGE,
};

#define OS_VARIANTS_NUM 3
enum os_variants {
    OS_WINDOWS,
    OS_MACOS,
    OS_LINUX,
};

static uint8_t os_variant = OS_WINDOWS;

