 main() {
     int *p = malloc(0);
     int r = rand() % 10;
     if (r > 10)     free(p);
     free(p);
     printf("Done!\n");
   }
 