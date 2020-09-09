#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	pid_t pid;
	char *komunikat;
	printf("Program Fork zacznyna prace");
	pid = fork();

	switch(pid){
		case -1: break;
		case 0 : 
			execl("./randomtouch", "randomtouch", (char *)0);
		default : printf("To proces macierzysty\n");
	}
	return 0;
}