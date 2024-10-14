static int divisor = 2;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {

// #ifdef CONSOLE_ENABLE
//
//     pinnacle_data_t   touchData = cirque_pinnacle_read_data();
//
//     pd_dprintf(
//             "> mouse_report > %d, %d: cirque_pinnacle touchData x=%4d y=%4d z=%2d, touchDown=%d\n",
//             mouse_report.x,
//             mouse_report.y,
//             touchData.xValue, touchData.yValue, touchData.zValue,
//             touchData.touchDown
//             );
//
// #endif

    mouse_report.x = (int8_t) (mouse_report.x / divisor );
    mouse_report.y = (int8_t) (mouse_report.y / divisor );

    return mouse_report;
}

