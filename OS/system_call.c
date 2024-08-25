#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void create_file(const char *filename)
{
    int fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if (fd == -1)
    {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    close(fd);
    printf("File '%s' created successfully.\n", filename);
}

void write_to_file(const char *filename, const char *data)
{
    int fd = open(filename, O_WRONLY | O_APPEND);
    if (fd == -1)
    {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    if (write(fd, data, strlen(data)) == -1)
    {
        perror("Error writing to file");
        exit(EXIT_FAILURE);
    }
    close(fd);
    printf("Data written to file '%s' successfully.\n", filename);
}

void read_file(const char *filename)
{
    char buffer[1024];
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
    {
        write(STDOUT_FILENO, buffer, bytes_read);
    }
    if (bytes_read == -1)
    {
        perror("Error reading from file");
        exit(EXIT_FAILURE);
    }
    close(fd);
    printf("\n");
}

void copy_file(const char *src_filename, const char *dest_filename)
{
    char buffer[1024];
    int src_fd = open(src_filename, O_RDONLY);
    if (src_fd == -1)
    {
        perror("Error opening source file for copying");
        exit(EXIT_FAILURE);
    }
    int dest_fd = open(dest_filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (dest_fd == -1)
    {
        perror("Error creating/opening destination file for copying");
        exit(EXIT_FAILURE);
    }
    ssize_t bytes_read;
    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0)
    {
        if (write(dest_fd, buffer, bytes_read) != bytes_read)
        {
            perror("Error writing to destination file");
            exit(EXIT_FAILURE);
        }
    }
    if (bytes_read == -1)
    {
        perror("Error reading from source file");
        exit(EXIT_FAILURE);
    }
    close(src_fd);
    close(dest_fd);
    printf("File '%s' copied to '%s' successfully.\n", src_filename, dest_filename);
}

int main()
{
    const char *filename = "test.txt";
    const char *data = "Hello, this is a test file.\n";
    const char *copy_filename = "copy.txt";

    create_file(filename);
    write_to_file(filename, data);
    printf("\nContents of file '%s':\n", filename);
    read_file(filename);
    copy_file(filename, copy_filename);

    return 0;
}
