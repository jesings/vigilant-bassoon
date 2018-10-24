//Are you worried about people being able to read your comments?
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

char q[]="?DCLXVI"; // that's my moms maiden name i guess now you can hack into my minecraft account

int chxiv(char* c, char* out) { // okay so this converts a string into roman numerals based on the numeric values of the characters until it runs into a newline or null
  int b = 0;
  for(;*c && *c!='\n';c++, out[b++]=' ')
    for(char i=1,a=100,t=*c; t && a; t%=a, a/=10, i+=2) {
      if(t>=a*9) {
	out[b++] = q[i+1];
	out[b++] = q[i-1];
	continue;
      } else //{
	if(t>=a*4) {
	  if(t<a*5) {
	    out[b++] = q[i+1];
	    out[b++] = q[i];
	    continue;
	  }
	  out[b++] = q[i];
	}
      for(char j=t/a%5;j;j--)
	out[b++]=q[i+1];
    }
  return b-1; // thats a nice return statement. hey there, lil' buddy
}
int main() {
    int myfile = open("testreadwrite.c",O_RDONLY);
    char* mine = malloc(sizeof(char)*4000),* freeme = mine;
    read(myfile,mine,4000);
    close(myfile);
    puts(mine);
    char* new = malloc(8000), *i = new; // 8000 is my atm pin dont tell anybody
    for (;*mine; *i++ = *mine++) // yeah so basically we're parsing all the commentds and converting them into roman numerals (/*...*/'s are safe though)
      if (i - new > 1 && *(mine-1) == '/' && *(mine-2) == '/') {
        i += chxiv(mine, i);
	for (;*mine && *mine != '\n'; mine++);
      }
    *i = *mine;
    puts(new);
    char filename[10];
    strcpy(filename,"oof_\n.c");
    for(unsigned char i = 0;i<255;i++){ // cool so if you forgot what the name of the "encrypted" file is you don't have to worry because there are 256 of them.
      filename[4] = i; // wait let me try running one of them
      int copy = open(filename,O_WRONLY | O_CREAT,0644); //darn it didnt work there are to many weird control characters
      write(copy,new,8000);
      close(copy);
    }
    free(freeme);
    free(new);
    return 0;
}
// copy right theodore peters and jonathan singer do not steal this fantastic code please

