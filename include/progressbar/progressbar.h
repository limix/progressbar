/**
 * progressbar -- a C library for displaying progress
 * on the command line.
 */

#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#ifdef __cplusplus
extern "C" {
#endif /* ifdef __cplusplus */

typedef struct _progressbar_t progressbar;

/// Create a new progressbar with the specified label and number of steps.
///
/// @param label The label that will prefix the progressbar.
/// @param max The number of times the progressbar must be incremented before it
// is considered complete,
///            or, in other words, the number of tasks that this progressbar is
// tracking.
///
/// @return A progressbar configured with the provided arguments. Note that the
// user is responsible for disposing
///         of the progressbar via progressbar_finish when finished with the
// object.
progressbar *progressbar_new(const char *label, unsigned long max);

/// Create a new progressbar with the specified label, number of steps, and
// format string.
///
/// @param label The label that will prefix the progressbar.
/// @param max The number of times the progressbar must be incremented before it
// is considered complete,
///            or, in other words, the number of tasks that this progressbar is
// tracking.
/// @param format The format of the progressbar. The string provided must be
// three characters, and it will
///               be interpretted with the first character as the left border of
// the bar, the second
///               character of the bar and the third character as the right
// border of the bar. For example,
///               "<->" would result in a bar formatted like "<------     >".
///
/// @return A progressbar configured with the provided arguments. Note that the
// user is responsible for disposing
///         of the progressbar via progressbar_finish when finished with the
// object.
progressbar *progressbar_new_with_format(const char *label, unsigned long max,
                                         const char *format);

/// Increment the given progressbar. Don't increment past the initialized # of
// steps, though.
void progressbar_inc(progressbar *bar);

/// Finalize (and free!) a progressbar. Call this when you're done, or if you
// break out partway through.
void progressbar_finish(progressbar *bar);

#ifdef __cplusplus
}
#endif /* ifdef __cplusplus */

#endif /* ifndef PROGRESSBAR_H */
