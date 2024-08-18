/*Display the current Date & Time. [#include <time.h> for time and ctime function and time_t datatype.]*/
#include <stdio.h>
#include <time.h>

void main() {
    time_t current_time;
    char *date_time;

    current_time = time(NULL);

    date_time = ctime(&current_time);

    printf("Current date and time: %s", date_time);

}
