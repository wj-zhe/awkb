
uint16_t default_cpi;

void pointing_device_init_user(void) {
    default_cpi = pointing_device_get_cpi();
}

bool scroll_mode = false;

void pointing_device_task_layer(void) {
    if (scroll_mode){
        pointing_device_set_cpi(SLOW_CPI);
    } else {
        pointing_device_set_cpi(default_cpi);
    }
}

static uint16_t mouse_timer = 0xFFFF;
static uint16_t mouse_idle = 0;

static float scroll_accumulated_h = 0;
static float scroll_accumulated_v = 0;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {

    if (scroll_mode) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / 8;
        scroll_accumulated_v += (float)mouse_report.y / 8;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h =  (int8_t)scroll_accumulated_h;
        if (mouse_report.h > 2 || mouse_report.h < -2)
            mouse_report.h = 2 * ( (mouse_report.h > 0) ? 1 : -1 );

        mouse_report.v = -(int8_t)scroll_accumulated_v;
        if (mouse_report.v > 2 || mouse_report.v < -2)
            mouse_report.v = 2 * ( (mouse_report.v > 0) ? 1 : -1 );

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= mouse_report.h;
        scroll_accumulated_v += mouse_report.v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;

    }

    if ( mouse_report.x == 0 || mouse_report.y == 0 || 
        mouse_report.h == 0 || mouse_report.v == 0 ) {
            mouse_timer = timer_read();
        }
    mouse_idle = timer_elapsed(mouse_timer);

    return mouse_report;
}

