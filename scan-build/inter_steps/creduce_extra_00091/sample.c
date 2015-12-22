main() {
  int *p = malloc(10);
  int r = rand() % 10;
  if (r > 10)
    0;
  free(p);
  printf("Done!\n");
}
