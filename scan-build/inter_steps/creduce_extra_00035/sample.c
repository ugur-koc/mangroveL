 void main()             {
            int *p = malloc(10 );
            int r = rand() % 10;
            if (r > 10)       free(p);
            printf("Done!\n");
          }
