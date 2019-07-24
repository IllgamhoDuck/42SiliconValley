/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hypark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 19:07:10 by hypark            #+#    #+#             */
/*   Updated: 2018/06/02 19:25:07 by hypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

typedef struct		s_list
{
	char			op;
	int				nb;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putnbr(int nb);
int					ft_atoi(char **str);
int					ft_operator(char op, int first, int second);
int					ft_check_char(char *c);
t_list				*ft_create_elem(char op, int nb);
void				ft_copy(char *copy, char *first, int len);
char				*ft_parenthesis(char **str);
void				ft_cal_div_mod(t_list *node);
void				ft_cal_mul(t_list *node);
void				ft_cal_add_minus(t_list *node);
int					ft_cal_eval(t_list *node);
void				ft_free_memory(t_list *node);
void				ft_str_list(char *str, t_list *node);
int					eval_expr(char *str);

#endif
