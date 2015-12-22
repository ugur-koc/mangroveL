void main() {
  int *p = malloc(10);
  int r = (p);
  free(p);
  printf("Done!\n");
}
