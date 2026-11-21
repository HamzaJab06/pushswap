
#include "push_swap.h"

void  read_flag(int *flags, char *str)
{
  char *allowed_flags[] = {"adaptive", "simple", "medium", "complex", "bench"};
  int   i;
  int   flag_set;
printf("Entered read_flag: %s\n", str);
  i = 0;
  flag_set = 0;
  while (i < 4)
  {
    if (!ft_strncmp(str + 2, allowed_flags[i], 8))
    {
      flags[0] = i;
      flags[2]++;
      flag_set = 1;
    }
    i++;
  }
  if (!ft_strncmp(str + 2, allowed_flags[4], 8) && !flag_set)
  {
    flags[1]++;
    flag_set = 1;
  }
  if (!flag_set)
  {
    printf("Error\n");
    exit(1);
  }
}

char  **read_args(int argc, char *argv[], int *flags)
{
  char  **splitted_nums;
  int   i;
  int   stack_flag;
  int   size_ptrs;
  int   ind;
  //printf("Entered read_args\n");
  ind = 1;
  size_ptrs = 0;
  i = 1;
  stack_flag = 0;
  while (i < argc)
  {
    //printf("i = %d, argument = %s\n", i, argv[i]);
    if (argv[i][0] == '-' && argv[i][1] == '-')
    {  
      read_flag(flags, argv[i]);
      if (stack_flag || flags[1] > 1 || flags[2] > 1)
      {
        // handle error , free everything
        printf("Error\n");
        exit(1);
      }
      ind++;
    }
    else
    {
      size_ptrs += arg_size(argv[i]);
      stack_flag = 1;
    }
    i++;
  }
  splitted_nums = malloc((size_ptrs + 1) * sizeof(char *));
  ft_splitadd(splitted_nums, argc, ind, (argv + ind));
  while (*splitted_nums)
  {
    printf("splitted num: %s\n", *splitted_nums);
    splitted_nums++;
  }
  printf("strategy: %d, bench: %d, strategy_set: %d\n", flags[0],flags[1],flags[2]);
  return (NULL);
}