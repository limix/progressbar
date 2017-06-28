#include "progressbar.h"
#ifdef _WIN32
# include <windows.h>
#else /* ifdef _WIN32 */
# include <unistd.h>
#endif /* ifdef _WIN32 */

#define SLEEP_US 20000

/**
 * Example for progressbar usage
 **/
int main(void)
{
    int max             = 60;
    progressbar *smooth = progressbar_new("Smooth", max);

    for (int i = 0; i < max; i++) {
#ifdef _WIN32
        Sleep(SLEEP_US);
#else /* ifdef _WIN32 */
        usleep(SLEEP_US);
#endif /* ifdef _WIN32 */
        progressbar_inc(smooth);
    }
    progressbar_finish(smooth);

    progressbar *longlabel = progressbar_new(
        "Three Second Task with a long label",
        3);

    for (int i = 0; i < 3; i++) {
        progressbar_inc(longlabel);
#ifdef _WIN32
        Sleep(1000);
#else /* ifdef _WIN32 */
        sleep(1);
#endif /* ifdef _WIN32 */
    }
    progressbar_finish(longlabel);

    progressbar *fast = progressbar_new("Fast", 20);

    for (int i = 0; i < 20; i++) {
#ifdef _WIN32
        Sleep(SLEEP_US / 1000);
#else /* ifdef _WIN32 */
        usleep(SLEEP_US);
#endif /* ifdef _WIN32 */
        progressbar_inc(fast);
    }
    progressbar_finish(fast);

    progressbar *custom = progressbar_new_with_format("Custom", max, "<.>");

    for (int i = 0; i < max; i++) {
#ifdef _WIN32
        Sleep(SLEEP_US / 1000);
#else /* ifdef _WIN32 */
        usleep(SLEEP_US);
#endif /* ifdef _WIN32 */
        progressbar_inc(custom);
    }
    progressbar_finish(custom);
}
