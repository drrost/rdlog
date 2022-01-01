//
// Created by Rostyslav Druzhchenko 24.12.20
//

#include <rdlog.h>

static void init_logs() {
    rd_get_app_name();
    rd_set_app_name("LOGSRV");
    rd_get_logfile_name(LOG_ALL);
    rd_set_logfile_name("/tmp/rdlog.log", LOG_ALL);
    rd_set_logfile_name("/tmp/rdlog_error.log", LOG_ERROR);
    rd_log_i(rd_get_app_name(), "Logs initialized");
}

int main(int argc, char *argv[]) {
    init_logs();
    rd_validate(argc, argv);
    rd_run(argv[1]);
    return 0;
}
