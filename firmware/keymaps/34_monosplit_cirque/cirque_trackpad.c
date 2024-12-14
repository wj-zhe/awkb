#ifdef POINTING_DEVICE_GESTURES_CUSTOM_SCROLL_ENABLE
static bool scrolling_mode = false;
static float scroll_accumulated_h = 0;
static float scroll_accumulated_v = 0;
#endif

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {

#ifdef CONSOLE_ENABLE
    pd_dprintf(
            "mouse_report x/y %4d, %4d ",
            mouse_report.x,
            mouse_report.y
            );

#endif

// Custom scroll mode
#ifdef POINTING_DEVICE_GESTURES_CUSTOM_SCROLL_ENABLE
    if (scrolling_mode) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / 50;
        scroll_accumulated_v += (float)mouse_report.y / 50;

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
    };
#endif

    // Scale down x/y movements
    mouse_report.x = (int8_t) mouse_report.x / 2;
    mouse_report.y = (int8_t) mouse_report.y / 2;

#ifdef CONSOLE_ENABLE
    pd_dprintf(
            "h/v %4d, %4d \n",
            mouse_report.h,
            mouse_report.v
            );

#endif

    return mouse_report;
}

