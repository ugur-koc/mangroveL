main() {
  int *p = malloc(10);
  int r = rand();
  free(p);
  printf("Done!\n");
}
