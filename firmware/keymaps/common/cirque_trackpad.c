static int divisor = 2;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {

#ifdef CONSOLE_ENABLE

    pd_dprintf(
            "mouse_report before %4d, %4d, %4d, %4d, %4d, %4d",
            mouse_report.x,
            mouse_report.y,
            (int8_t) (mouse_report.x / divisor ),
            (int8_t) (mouse_report.y / divisor ),
            mouse_report.v,
            mouse_report.h
            );

    // pinnacle_data_t   touchData = cirque_pinnacle_read_data();
    //
    // pd_dprintf(
    //         "cirque_pinnacle touchData x=%4d y=%4d z=%2d, touchDown=%d",
    //         touchData.xValue, touchData.yValue, touchData.zValue,
    //         touchData.touchDown
    //         );

    pd_dprintf("\n");

#endif

    mouse_report.x = (int8_t) (mouse_report.x / divisor );
    mouse_report.y = (int8_t) (mouse_report.y / divisor );

    return mouse_report;
}

