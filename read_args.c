
#include "push_swap.h"

void  read_flag(int *flags, char *str)
{
  char *allowed_flags[] = {"adaptive", "simple", "medium", "complex", "bench"};
  int   i;
  int   flag_set;

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
size_t  merged_size(char **new, char **old)
{
  size_t size;

  size = 0;
  while (*new++)
    size++;
  while (*old++)
    size++;
  return (size);
}

void  merge(char **new,char ***splitted_nums)
{
  char  **tmp;
  int i;

  i = 0;
  tmp = malloc(sizeof(char *) * (merged_size(new, *splitted_nums) + 1));
  while (**splitted_nums)
  {
    *tmp = malloc(ft_strlen(**splitted_nums) + 1);
    while (**splitted_nums[i])
    {
      *tmp[i] = **splitted_nums[i];
      i++;
    }
    *tmp[i] = '\0';
    *tmp++;
    **splitted_nums++;
  }
  while (*new)
  {
    *tmp = malloc(ft_strlen(*new) + 1);
    while (*new[i])
    {
      *tmp[i] = *new[i];
      i++;
    }
    *tmp[i] = '\0';
    *tmp++;
    *new++;
  }
  *tmp = NULL;
  *splitted_nums = tmp;
}

void  read_nums(char *str, char ***splitted_nums)
{
  char  **new_splitted_nums;

  new_splitted_nums = ft_split(str, '-');
  merge(new_splitted_nums, splitted_nums);
}

char  **read_args(int argc, char *argv[], int *flags)
{
  char  **splitted_nums;
  int   i;
  int   stack_flag;

  splitted_nums = NULL;
  i = 1;
  stack_flag = 0;
  while (i < argc)
  {
    if (argv[i][0] == '-' && argv[i][1] == '-')
    {  
      read_flag(flags, argv[i]);
      if (stack_flag || flags[1] > 1 || flags[2] > 1)
      {
        // handle error , free everything
        printf("Error\n");
        exit(1);
      } 
    }
    else
    {
      read_nums(argv[i], &splitted_nums);
      stack_flag = 1;
    }
    i++;
  }
  printf("strategy: %d, bench: %d, strategy_set: %d\n", flags[0],flags[1],flags[2]);
  return (NULL);
} 