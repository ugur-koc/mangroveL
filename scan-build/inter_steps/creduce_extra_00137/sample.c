main() {
  int *p = malloc(10);
  int r = 10;
  if (r > 10)
    free(p);
  free(p);
  printf("Done!\n");
}
