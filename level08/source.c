#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_FILENAME 100
#define BUFFER_SIZE 1

void log_wrapper(FILE *log_file, const char *message, const char *filename) {
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "%s%s", message, filename);
    buffer[strcspn(buffer, "\n")] = 0;
    fprintf(log_file, "LOG: %s\n", buffer);
}

int main(int argc, char **argv) {
    FILE *log_file, *source_file;
    char backup_path[MAX_FILENAME] = "./backups/";
    char buffer[BUFFER_SIZE];
    int dest_fd;

    // if (argc != 2) {
    //     printf("Usage: %s filename\n", argv[0]);
    //     return 1;
    // }

    log_file = fopen("./backups/.log", "a");
    // if (!log_file) {
    //     printf("ERROR: Failed to open %s\n", "./backups/.log");
    //     exit(1);
    // }

    log_wrapper(log_file, "Starting back up: ", argv[1]);

    source_file = fopen(argv[1], "r");
    // if (!source_file) {
    //     printf("ERROR: Failed to open %s\n", argv[1]);
    //     exit(1);
    // }

    // ./backups/ + argv[1]
    strncat(backup_path, argv[1], MAX_FILENAME - strlen(backup_path) - 1);
    dest_fd = open(backup_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
        exit(1);
    }

    while ((buffer[0] = fgetc(source_file)) != EOF) {
        write(dest_fd, buffer, 1);
    }

    log_wrapper(log_file, "Finished back up ", argv[1]);

    fclose(source_file);
    close(dest_fd);
    fclose(log_file);

    return 0;
}
