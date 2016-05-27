/***
Разработать программу solution, которая по заданному pid осуществляет
поиск всех потомков процесса с этим идентификатором и выводит их количество
(включая процесс с заданным pid).
***/

#include <stdio.h>
#include <string.h>
#include <dirent.h>


int main(int argc, char *argv[])
{
    if (argc != 2)
        return -1;
    
    int target_pid = -1;
    sscanf(argv[1], "%i", &target_pid);
    
    struct dirent *dirent;
    DIR *dir;
    dir = opendir("/proc");
    int count = 1;    
    while ((dirent = readdir(dir)) != NULL)
    {
        if (dirent->d_type == DT_DIR)
        {
            int pid = -1;
            sscanf(dirent->d_name, "%i", &pid);
            if (pid > 0)
            {
                char fname[255];
                sprintf(fname, "/proc/%i/status", pid);
                FILE *f = fopen(fname, "r");
                char buf[255];
                while (fgets(buf, sizeof(buf), f))
                {
                    char tag[255];
                    int ppid = -1;
                    sscanf(buf, "%s\t%i", tag, &ppid);
                    if (strcmp(tag, "PPid:") == 0 && ppid == target_pid)
                        count++;
                }
                fclose(f);
            }                
        }            
    }
    closedir(dir);
    printf("%i\n", count);
    return 0;
    
    
    return 0;
}