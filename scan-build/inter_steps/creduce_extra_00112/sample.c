main() {
  int *p = malloc(10);
  int r = rand(p);
  free(p);
  printf("Done!\n");
}
