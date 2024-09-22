static bool precise_move = false;

static bool scrolling_mode = false;
uint8_t x_sum = 0;
uint8_t y_sum = 0;

uint16_t default_cpi;

void pointing_device_init_user(void) {
    default_cpi = pointing_device_get_cpi();
}

static void pointing_device_task_layer(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 1: case 3:  // Enable scrolling mode
            scrolling_mode = true;
            pointing_device_set_cpi(100);
            break;

        case 2:  // Enable precise movement
            precise_move = true;
            pointing_device_set_cpi(200);
            break;

        default:
            if (scrolling_mode) {  // Disable scrolling mode
                scrolling_mode = false;
            };
            if (precise_move) {  // Disable scrolling mode
                precise_move = false;
            };
            pointing_device_set_cpi(default_cpi);
            break;
    }

}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scrolling_mode) {
        // sum x and y movements
        x_sum += mouse_report.x;
        y_sum += mouse_report.y;

        // set h/v movements only on consecutive x/y movements
        if (abs(x_sum) >=5 || abs(y_sum) >=5) {

            if ( abs(x_sum) / abs(y_sum) >2 ) {
                mouse_report.h = mouse_report.x;
                mouse_report.v = 0;
            } else if ( abs(y_sum) / abs(x_sum) >2 ) {
                mouse_report.v = mouse_report.y;
                mouse_report.h = 0;
            } else {
                // set h/v to zero to avoid simultaneous scroll movements
                mouse_report.h = 0;
                mouse_report.v = 0;
            };

            // reset x_sum and y_sum
            x_sum = 0;
            y_sum = 0;
        }

        // set x/y to zero to avoid mouse movements
        mouse_report.x = 0;
        mouse_report.y = 0;

    }
    return mouse_report;
}

