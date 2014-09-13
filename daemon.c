#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>

int main(int argc, char** argv)
{
	int result = -1;
	int nochdir = 0;
	int noclose = 0;

	if(1 < argc) 
		nochdir = strtol(argv[1], NULL, 10);
	if(2 < argc)
		noclose = strtol(argv[2], NULL, 10);
	if(3 < argc)
	{
		int i, j;
		char* path;
		char* eargv[argc];

		path = argv[3];
		eargv[0] = basename(path);
		for(i = 1, j = 4; j < argc; i++, j++)
			eargv[i] = argv[j];
		eargv[i] = NULL;

		if(-1 != (result = daemon(nochdir, noclose)))
			result = execv(path, eargv);
	}
	else
		printf("daemon nochdir noclose command...\n");
	return result;
}

