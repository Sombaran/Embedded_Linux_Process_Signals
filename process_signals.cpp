//============================================================================
// Name        : process_signals.cpp
// Author      : Som Gupta
// Version     :
// Copyright   : Embedded_linux_tutorial
// Description : Hello World in C++, Ansi-style
//============================================================================


#include "process_signals.hpp"

void process_variation_1(void) {
	pid_t pid;
	printf("The base pid = %d \n",getpid());
	pid = fork();
	if(pid != NULL)
	{
	printf("This is parent process = %d \n",getpid());
	printf("This is the child created from the parent process = %d \n",pid);
	}
	else
	{
	printf("This is child process = %d \n",getpid());
	}
}

void process_variation_2(void ) {
	pid_t my_pid,parent_pid,child_pid;
	my_pid = getpid();
	parent_pid = getppid();
	child_pid = fork();
	printf("Parent: my parent's pid = %d \n", parent_pid);
	printf("Parent: my pid = %d \n", my_pid);
	printf("Parent: my child's pid = %d \n", child_pid);
}

void myhandle(int mysig) {
	printf("Thats my handle: %d\n", mysig);
}

void signals_variations_3(void) {
	int i=0;
	signal(SIGTERM,myhandle);
	while(1)
	{
		printf("i=%d\n", i);
		i++;
		sleep(1);
        }
}

int main(void) {
	std::cout << "PID inside main: " << getpid() << std::endl;
	std::thread var_1(process_variation_1);
	var_1.join();
	std::thread var_2(process_variation_2);
	var_2.join();
	std::cout << "Signals Begins HERE....." << std::endl;
	std::thread var_3(signals_variations_3);
	var_3.join();
	return (0);
}
