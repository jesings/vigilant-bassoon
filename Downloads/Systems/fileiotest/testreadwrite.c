#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
    int myfile = open("testreadwrite.c",O_RDONLY);
    char* mine = malloc(sizeof(char)*1000);
    read(myfile,mine,1000);
    close(myfile);
    puts(mine);
    for(unsigned char i = 0;i<255;i++){
        char filename[10];
        strcpy(filename,"file .c");
        filename[4] = i;
        int copy = open(filename,O_WRONLY | O_CREAT,0644);
        write(copy,mine,1000);
        close(copy);
    }
    return 0;
}
