#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/prctl.h>

int main(int argc, char *argv[])
{
    printf("%d\n", getpid());

    //调用prctl修改进程名
    char buf[20] = "wangwei";
	//调用prctl
    prctl(PR_SET_NAME, buf);
    int p = fork();
    if(p == 0){
		char buf1[20] = "tiantian";
        printf("child!\n");
        printf("%d\n", getpid());
		prctl(PR_SET_NAME, buf1);
        getchar();
    }
    getchar();

    return 0;
}
