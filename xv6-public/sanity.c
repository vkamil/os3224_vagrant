#include "types.h"
#include "user.h"

void sanity(void){
	int i,j,pid;
	double count;
	int total_turn = 0;
	int total_run = 0;
	int total_ready = 0;

	for (i=0;i<20;i++){
		pid=fork();

		if (pid==0){
			for (j=0; j<1000000;j++){
				count *= j+(j * 39 / (count+50)) *14;
			}
			exit();

		}

	}



	for(i=0;i<20;i++){
		int status = 0;
		int rtime = 0;
		int wtime = 0;
		int iotime = 0;

		wait_stat(&wtime,&rtime,&iotime,&status);
		int turnaround_time;
		turnaround_time = (wtime+rtime+iotime);
		printf(1, "process: %d \n", i);
		printf(1, "waitime : %d runtime : %d status : %d\n", wtime,rtime,status);
		printf(1, "turnaround time : %d\n \n", turnaround_time);
		total_turn += turnaround_time;
		total_run += rtime;
		total_ready += wtime;

	}
	printf(1, "turnaround time (avg) : %d\n", total_turn/20);
	printf(1, "ready time (avg) : %d\n", total_ready/20);
	printf(1, "run time (avg) : %d\n", total_run/20);

	exit();
}

int main(int argc, char const *argv[])
{
	sanity();
	return 0;
}