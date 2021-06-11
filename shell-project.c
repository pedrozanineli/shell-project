#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>
#include <unistd.h>
#include <dirent.h>

#include "shell-lib.h"

#define CLEAR "CLS"

int main(){

    printf("Shell project - Pedro Zanineli\n\n");

    int converted, resultrps, cp, test = 1;
    char cwd[1024], ch, *filename;

    FILE *fp, *fp1;
    DIR *d;
    struct dirent *dir;

    while(test){

        printf("> ");
        converted = conversor();

        switch(converted) {

            case '0':   test = 0;
                        break;

            case '1':   printf("- rfile - read file\n");
                        printf("- lfile: list files\n");
                        printf("- tfile: file type\n");
                        printf("- dir: show directory's path\n");
                        printf("- cfile: clear file\n");
                        printf("- cpfile: copy file\n");
                        printf("- rps: play rock, paper and scissors\n");
                        printf("- clear: clear shell\n");
                        printf("- exit: end shell\n");

                        getchar();
                        break;

            case '2':   printf("Choose file to read: ");
                        scanf("%s",filename);
                        fp = fopen(filename,"r");

                        printf("\n");
                        while(1){
                            ch = fgetc(fp);
                            if (ch == EOF) break;
                            printf("%c",ch);
                        }

                        fclose(fp);
                        printf("\n\n");

                        getchar();
                        break;

            case '3':   d = opendir(".");
                        if (d)
                        {
                            while ((dir = readdir(d)) != NULL)
                            {
                                printf("%s\n", dir->d_name);
                            }
                            closedir(d);
                        }

                        getchar();
                        break;

            case '4':   d = opendir(".");
                        if (d)
                        {
                            while ((dir = readdir(d)) != NULL)
                            {
                                printf("%s", strchr(dir->d_name, '.'));
                                printf("\t%s\n", dir->d_name);
                            }
                            closedir(d);
                        }

                        getchar();
                        break;

            case '5':   chdir("/path/to/change/directory/to");
                        getcwd(cwd, sizeof(cwd));
                        printf("Current working directory: %s\n", cwd);

                        getchar();
                        break;

            case '6':   printf("Choose file to clear: ");
                        scanf("%s",filename);

                        fp = fopen(filename,"w");
                        fprintf(fp,"");
                        fclose(fp);

                        getchar();
                        break;

            case '7':   printf("Choose file to copy: ");
                        scanf("%s",filename);
			
			fp = fopen(filename,"r");

			printf("Choose file to copy: ");
                        scanf("%s",filename);
			
			fp1 = fopen(filename,"w");

			if(fp != NULL && fp1 != NULL){
				while((ch = fgetc(fp)) != EOF)
				fputc(ch, fp1);
				printf("Contents copied to %s.\n", filename);
			}else{
				printf("Cannot open file");
			}

			fclose(fp);
			fclose(fp1);

                        getchar();
                        break;

            case '8':   printf("Choose option: ");
                        playrps();

                        getchar();
                        break;

            case '9':   system(CLEAR);
                        printf("Shell project - Pedro Zanineli\n\n");
                        getchar();
                        break;

            default: 	printf("Invalid option.\n");
                        getchar();
						break;
        }
    }
    return 0;
}
