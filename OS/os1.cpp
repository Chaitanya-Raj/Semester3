#include<stdio.h>
#include<sys/vfs.h>
#include<sys/sysinfo.h>
#include<sys/utsname.h>

int main()
{
	int MB,GB,p,q,r;
	struct sysinfo s1;
	struct utsname s2;
	struct statfs s3;

	r=sysinfo(&s1);
	q=uname(&s2);
	p=statfs("./",&s3);
	MB=(1024*1024);
	GB=(MB*1024);
	
	if(r==0&&q==0&p==0)
	{
		printf("\nSystem name:%s",s2.sysname);
		printf("\nRelease: %s",s2.version);
		printf("\nKernel Version : %s",s2.release);
		printf("\nMachine : %s",s2.machine);
		printf("\nTotal ram: %ldmb",(s1.totalram/MB));
		printf("\nFree ram : %ldmb",(s1.freeram/MB));
		printf("\nUsed ram: %ldmb",(s1.totalram-s1.freeram)/MB);
		printf("\nTotalsize of partition: %ldGB",(s3.f_bsize*s3.f_blocks)/GB);
		printf("\n");
	} 
	else
		printf("error");
	
	return 0;
}

