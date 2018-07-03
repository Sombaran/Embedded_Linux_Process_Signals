#ifndef _PROCESS_SIGNALS_
#define _PROCESS_SIGNALS_
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <thread>
#include <unistd.h>


void process_variation_1(void);
void process_variation_2(void);
void myhandle(int);
void signals_variations_3(void);

#endif
