static bool scrolling_mode = false;

#ifdef POINTING_DEVICE_GESTURES_CUSTOM_SCROLL_ENABLE
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

    if (scrolling_mode) {
// Custom scroll mode
#ifdef POINTING_DEVICE_GESTURES_CUSTOM_SCROLL_ENABLE
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / 32;
        scroll_accumulated_v += (float)mouse_report.y / 32;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h =  (int8_t)scroll_accumulated_h;
        mouse_report.v = -(int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= mouse_report.h;
        scroll_accumulated_v += mouse_report.v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
#endif
    } else {
        // Scale down x/y movements
        mouse_report.x = (int8_t) mouse_report.x / 2;
        mouse_report.y = (int8_t) mouse_report.y / 2;

    }

#ifdef CONSOLE_ENABLE
    pd_dprintf(
            "h/v %4d, %4d \n",
            mouse_report.h,
            mouse_report.v
            );

#endif

    return mouse_report;
}

