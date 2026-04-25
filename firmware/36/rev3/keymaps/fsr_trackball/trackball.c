
uint16_t default_cpi;

void pointing_device_init_user(void) {
    default_cpi = pointing_device_get_cpi();
}

bool kb_scroll = false;

void pointing_device_task_layer(void) {
    if (kb_scroll){
        pointing_device_set_cpi(SLOW_CPI);
    }
    else {
        pointing_device_set_cpi(default_cpi);
    }
}

static struct scroll_acc_t {
    float h;
    float v;
} scroll_acc = {0,0};

#ifdef FSR_ENABLE
    #ifndef TRACKBALL_MC_THRES
    #   define TRACKBALL_MC_THRES 50 /* Trackball movements counter threshold */
    #endif
    uint8_t trackball_mc = 0; // Counter
#endif // #ifdef FSR_ENABLE

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {

#ifdef FSR_ENABLE
    if ( mouse_report.x != 0 || mouse_report.y !=0 ) {
        if (trackball_mc < TRACKBALL_MC_THRES) trackball_mc ++ ;
    } 
    else {
        if (trackball_mc > 0) trackball_mc -- ;
    }

    // dprintf("mc %d \n", trackball_mc);

#endif

    if (kb_scroll) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_acc.h += (float)mouse_report.x / 8;
        scroll_acc.v += (float)mouse_report.y / 8;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h =  (int8_t)scroll_acc.h;
        if (mouse_report.h > 2 || mouse_report.h < -2)
            mouse_report.h = 2 * ( (mouse_report.h > 0) ? 1 : -1 );

        mouse_report.v = -(int8_t)scroll_acc.v;
        if (mouse_report.v > 2 || mouse_report.v < -2)
            mouse_report.v = 2 * ( (mouse_report.v > 0) ? 1 : -1 );

        // Update accumulated scroll values by subtracting the integer parts
        scroll_acc.h -= mouse_report.h;
        scroll_acc.v += mouse_report.v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;

    }

    return mouse_report;
}

// report_mouse_t self_scroll(report_mouse_t mouse_report) {
//     return mouse_report
// }
