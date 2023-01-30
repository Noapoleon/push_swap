# Project structure
NAME	=	push_swap
CHECKER	=	checker
INCDIR	=	incs
LIBDIR	=	libs
SRCDIR	=	srcs
OBJDIR	=	objs
LIBFT	=	libft

# Compiler options
CC		=	cc
CWARNS	=	-Wall -Wextra -Werror
CLIBS	=	-L./$(LIBDIR) -lft
CINCS	=	-I./$(INCDIR)

# Other
RM		=	rm -rf
DEBUG	=	-g3 -gdwarf-4

# Files
SRCS	:=	push_swap.c \
			parser1.c \
			parser2.c \
			utils.c \
			operations1.c \
			operations2.c \
			small_sorts.c \
			quick_sort.c \
			fraction_sort1.c \
			fraction_sort2.c \
			fraction_sort3.c \
			sorts_utils1.c \
			sorts_utils2.c
SRCS_B	:=	checker_bonus.c \
			checker_utils_bonus.c \
			get_operations_bonus.c \
			parser1.c \
			parser2.c \
			utils.c \
			operations1.c \
			operations2.c
OBJS	:=	$(SRCS:.c=.o)
OBJS_B	:=	$(SRCS_B:.c=.o)
SRCS	:=	$(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:=	$(addprefix $(OBJDIR)/, $(OBJS))
OBJS_B	:=	$(addprefix $(OBJDIR)/, $(OBJS_B))

all: $(NAME)

bonus: $(CHECKER)

test:
	$(CC) $(CWARNS) $(CINCS) unit_test/test.c srcs/parser1.c srcs/parser2.c srcs/utils.c $(CLIBS) -o test

$(CHECKER): $(LIBDIR)/libft.a $(OBJS_B)
	$(CC) $(CWARNS) $(OBJS_B) $(CLIBS) -o $(CHECKER)

$(NAME): $(LIBDIR)/libft.a $(OBJS)
	$(CC) $(DEBUG) $(CWARNS) $(OBJS) $(CLIBS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR) $(LIBDIR)
	$(CC) $(DEBUG) $(CWARNS) $(CINCS) -c $< -o $@

$(LIBDIR)/libft.a: | $(LIBDIR)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a $(LIBDIR)/

$(OBJDIR):
	mkdir -p $(OBJDIR)
$(LIBDIR):
	mkdir -p $(LIBDIR)

resrcs: cleansrcs $(OBJS)

cleansrcs:
	$(RM) $(OBJS)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(LIBFT)/libft.a
	$(RM) $(LIBDIR)/libft.a
	$(RM) $(NAME) $(CHECKER)

re: fclean all

rebonus: fclean bonus

norm:
	norminette $(SRCS) $(INCDIR) | awk '{if ($$NF == "OK!") { print "\033[0;92m"$$0"\033[0m" } else if ($$NF == "Error!") { print "\033[0;91m"$$0"\033[0m" } else { print }}'

.PHONY: all bonus rebonus resrcs cleansrcs clean fclean re norm test
