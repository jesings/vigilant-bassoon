#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
int main(){
    int myfile = open("testreadwrite.c",O_RDONLY);
    char* mine = malloc(sizeof(char)*1000);
    fread(myfile,mine,500);
    close(myfile);
    puts(mine);
   // char* nice = "file .c"
   // for(char i = 0;i<256;i++){
   //     char filename[10];
   //     strcpy(nice, filename);
   //     filename[4] = i;
   //     FILE* copy = fopen(filename,"w");
   //     fwrite(
   // }
    return 0;
}
