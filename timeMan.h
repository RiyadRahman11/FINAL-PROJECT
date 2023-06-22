/* time example */
#include <stdio.h> /* printf */
#include <time.h>  /* time_t, struct tm, difftime, time, mktime */

long long int duR()
{
    time_t timer;
    struct tm y2k = {0};
  long long  int secs;

    y2k.tm_hour = 0;
    y2k.tm_min = 0;
    y2k.tm_sec = 0;
    y2k.tm_year = 100;
    y2k.tm_mon = 0;
    y2k.tm_mday = 1;

    time(&timer); /* get current time; same as: timer = time(NULL)  */

    secs = difftime(timer, mktime(&y2k));

   // printf("%d seconds since January 1, 2000 in the current timezone", seconds);

    return secs;
}