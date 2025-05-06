// TODO:
// 
// - define file / stdout
//   - if null , default file_output_name

#ifndef SBT_H_
#define SBT_H_

#include <stdio.h>
#include <sys/time.h>

struct timeval tvp1 , tvp2;
// struct timezone tzp1 , tzp2;

void start_sbt(void);
void end_sbt(void);
void start_sbt_v(char *, char *);
void end_sbt_v(char *);

#endif // SBT_H

#ifdef SBT_IMPLEMENTATION

void start_sbt(void)
{
    gettimeofday(&tvp1, NULL);
}

void end_sbt(void)
{
    gettimeofday(&tvp2, NULL);
    int diff_sec = tvp2.tv_sec - tvp1.tv_sec;
    int diff_ms  = tvp2.tv_usec - tvp1.tv_usec;
    printf(" > %ds %dms\n", diff_sec, diff_ms);
}

void start_sbt_v(char *sbt_id, char *sbt_msg)
{
    if(sbt_msg != NULL)
        printf(" [%s] %s\n", sbt_id, sbt_msg);
    // gettimeofday(&tvp1, &tzp1);
    gettimeofday(&tvp1, NULL);
}

void end_sbt_v(char *sbt_id)
{
    // gettimeofday(&tvp2, &tzp2);
    gettimeofday(&tvp2, NULL);

    int diff_sec = tvp2.tv_sec - tvp1.tv_sec;
    int diff_ms  = tvp2.tv_usec - tvp1.tv_usec;
    if(sbt_id != NULL)
        printf(" [%s] %ds %dms\n", sbt_id, diff_sec, diff_ms);
    else
        printf(" > %ds %dms\n", diff_sec, diff_ms);
}

#endif // SBT_IMPLEMENTATION
