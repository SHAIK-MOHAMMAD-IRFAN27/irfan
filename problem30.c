/*
name: problem30.c
author: SHAIK  MOHAMMAD IRFAN 
description:Write a program to run a script at a specific time using a Daemon process.
date:30th august 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <signal.h>

void run_script(const char *script_path) {
    int status = system(script_path);
    if (status == -1) {
        perror("Error executing script");
    }
}

void create_daemon(const char *script_path, int hour, int minute) {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }
    umask(0);
    if (setsid() < 0) {
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }
    if (chdir("/") < 0) {
        exit(EXIT_FAILURE);
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    while (1) {
        time_t now = time(NULL);
        struct tm *timeinfo = localtime(&now);
        if (timeinfo->tm_hour == hour && timeinfo->tm_min == minute) {
            run_script(script_path);
            sleep(60);
        }

        sleep(1);
    }
}

int main() {
    
    const char *script_path = "/home/irfan_shaik/ssy/irfan/irfan.sh";

    int hour = 10;   
    int minute = 42; 
    create_daemon(script_path, hour, minute);
    return 0;
}
