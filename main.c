
#include "push_swap.h"

int main(int argc, char *argv[])
{
  t_stack *a = NULL;
  t_stack *b = NULL;
  //printf("Entered main\n");
  char  **splitted;
  int   flags_s_b_sset[3] = {0, 0, 0};
  if (argc == 1 || argv[1][0] == '\0')
    return(1);
  splitted = read_args(argc, argv, flags_s_b_sset);
}
