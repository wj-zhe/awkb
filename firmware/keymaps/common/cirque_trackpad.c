static int divisor = 2;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    mouse_report.x = (int8_t) (mouse_report.x / divisor);
    mouse_report.y = (int8_t) (mouse_report.y / divisor);
    // mouse_report.h = (int8_t) (mouse_report.h / divisor);
    // mouse_report.v = (int8_t) (mouse_report.v / divisor);

    return mouse_report;
}

