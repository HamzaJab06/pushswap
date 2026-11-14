#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

typedef struct   s_stack
{
    int num;
    struct s_stack *next;
    struct s_stack *back;
}   t_stack;


char  **read_args(int argc, char *argv[], int *flags);
void  read_flag(int *flags, char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);

#endif

