/*Add two times hh, mm and ss using structure.*/
#include <stdio.h>

struct Time {
    int hour;
    int minute;
    int second;
};

int main() {
    struct Time time1, time2, result;

    printf("Enter the first time (hh:mm:ss): ");
    scanf("%d:%d:%d", &time1.hour, &time1.minute, &time1.second);

    printf("Enter the second time (hh:mm:ss): ");
    scanf("%d:%d:%d", &time2.hour, &time2.minute, &time2.second);

    result.hour = time1.hour + time2.hour;
    result.minute = time1.minute + time2.minute;
    result.second = time1.second + time2.second;

    if (result.second >= 60) {
        result.second -= 60;
        result.minute++;
    }
    if (result.minute >= 60) {
        result.minute -= 60;
        result.hour++;
    }

    printf("The sum of the two times is: %02d:%02d:%02d\n", result.hour, result.minute, result.second);

    return 0;
}
