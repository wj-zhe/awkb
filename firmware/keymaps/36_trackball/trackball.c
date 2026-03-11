uint16_t default_cpi;
uint16_t slow_cpi;

void pointing_device_init_user(void) {
    default_cpi = pointing_device_get_cpi();
    set_auto_mouse_layer(4);
    set_auto_mouse_enable(true);
}

static bool scrolling_mode = false;
static float scroll_accumulated_h = 0;
static float scroll_accumulated_v = 0;

uint8_t mod_state;
static void pointing_device_task_layer(layer_state_t state) {
    mod_state = get_mods();
    switch(get_highest_layer(remove_auto_mouse_layer(state, true))) {
        case 1: // Enable scrolling mode
            scrolling_mode = true;
            pointing_device_set_cpi(slow_cpi);
            break;

        case 2: // Fast moving mode
#ifdef PMW33XX_CPI_FAST
            if (mod_state & MOD_MASK_GUI) {
                pointing_device_set_cpi(PMW33XX_CPI_FAST);
            }
#endif // #ifdef PMW33XX_CPI_FAST
            break;

        case 3:
            scrolling_mode = true;
            pointing_device_set_cpi(slow_cpi);
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
            // remove_auto_mouse_target must be called to adjust state *before* setting enable
            state = remove_auto_mouse_layer(state, false);
            set_auto_mouse_enable(false);
            break;
#endif

        default:
            if (scrolling_mode) {  // Disable scrolling mode
                scrolling_mode = false;
            };
            pointing_device_set_cpi(default_cpi);
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
            set_auto_mouse_enable(true);
#endif
            break;
    }

}

static uint16_t mouse_timer = 0xFFFF;
static uint16_t mouse_timeElapsed;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scrolling_mode) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / 8;
        scroll_accumulated_v += (float)mouse_report.y / 8;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h =  (int8_t)scroll_accumulated_h;
        if (mouse_report.h>2 || mouse_report.h <-2)
            mouse_report.h = 2 * ( (mouse_report.h >0) ? 1: -1 );

        mouse_report.v = -(int8_t)scroll_accumulated_v;
        if (mouse_report.v>2 || mouse_report.v <-2)
            mouse_report.v = 2 * ( (mouse_report.v >0) ? 1: -1 );

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= mouse_report.h;
        scroll_accumulated_v += mouse_report.v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;

    }

    return mouse_report;
}

