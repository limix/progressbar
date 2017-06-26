#include "progressbar.h"
#include <unistd.h>

#define SLEEP_US 100000

/**
 * Example for progressbar usage
 **/
int main(void)
{
    int max             = 60;
    progressbar *smooth = progressbar_new("Smooth", max);

    for (int i = 0; i < max; i++) {
        usleep(SLEEP_US);
        progressbar_inc(smooth);
    }
    progressbar_finish(smooth);

    progressbar *longlabel = progressbar_new(
        "Three Second Task with a long label",
        3);

    for (int i = 0; i < 3; i++) {
        progressbar_inc(longlabel);
        sleep(1);
    }
    progressbar_finish(longlabel);

    progressbar *fast = progressbar_new("Fast", 20);

    for (int i = 0; i < 20; i++) {
        usleep(SLEEP_US);
        progressbar_inc(fast);
    }
    progressbar_finish(fast);

    progressbar *custom = progressbar_new_with_format("Custom", max, "<.>");

    for (int i = 0; i < max; i++) {
        usleep(SLEEP_US);
        progressbar_inc(custom);
    }
    progressbar_finish(custom);
}
