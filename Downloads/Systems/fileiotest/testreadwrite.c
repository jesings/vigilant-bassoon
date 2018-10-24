//Are you worried about people being able to read your comments?
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

char q[]="MDCLXVI";

char* chxiv(char* c) {
  char* out = malloc(strlen(c)*9),* b = out;
  for(;*c && *c!='\n';c++, *b++=' ')
    for(char i=1,a=100,t=*c; t && a; t%=a, a/=10, i+=2) {
      if(t>=a*9) {
	*b++ = q[i+1];
	*b++ = q[i-1];
	continue;
      } else
	if(t>=a*4) {
	  if(t<a*5) {
	    *b++ = q[i+1];
	    *b++ = q[i];
	    continue;
	  }
	  *b++ = q[i];
	}
      for(char j=t/a%5;j;j--)
	*b++=q[i+1];
    }
  *(b-1)=0;
  return out;
}

int main() {
  char q[] = "Hello, World!";
  char* b = chxiv(q),* b2 = chxiv(b);
  printf("//%s\n//Hello, World! in roman numerals\n//%s\n//Hello, World! in roman numerals in roman numerals",b, b2);
    int myfile = open("testreadwrite.c",O_RDONLY);
    char* mine = malloc(sizeof(char)*1000);
    read(myfile,mine,1000);
    close(myfile);
    puts(mine);
    char filename[10];
        strcpy(filename,"file .c");
    for(unsigned char i = 0;i<255;i++){
        filename[4] = i;
        int copy = open(filename,O_WRONLY | O_CREAT,0644);
        write(copy,mine,1000);
        close(copy);
    }
    return 0;
}
