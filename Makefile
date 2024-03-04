SRCS	= main.c\
	  ft_bash.c\
	  ft_strlen.c\
	  ft_command.c\
	  get_next_line_utils.c\
	  get_next_line.c\
	  ft_substr.c\
	  ft_strcmp.c\
	  ft_strjoin.c\

SRCS_B	= main_bonus.c\
	  ft_bash.c\
	  ft_strlen.c\
	  ft_command.c\
	  get_next_line_utils.c\
	  get_next_line.c\
	  ft_substr.c\
	  ft_strcmp.c\
	  ft_strjoin.c\

CFLAGS	= -Wall -Wextra -Werror

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

PROG_NAME= pipex

NAME	= $(PROG_NAME).a
NAME_B	= $(PROG_NAME)_bonus.a

HDR	= $(PROG_NAME).h

RM	= rm -f

all:   $(NAME)

bonus: $(NAME_B)

$(NAME): $(OBJS) $(HDR)
	$(RM) main_bonus.o
	ar -crs $(NAME) $(OBJS)
	$(RM) $(PROG_NAME)
	gcc $(NAME) -o $(PROG_NAME)

%.o: %.c $(HDR_DIR)$(HDR)
	gcc $(CFLAGS) -c $< -o $@

$(NAME_B): $(OBJS_B) $(HDR)
	$(RM) main.o
	ar -crs $(NAME_B) $(OBJS_B)
	$(RM) $(PROG_NAME)
	gcc $(NAME_B) -o $(PROG_NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)
	$(RM) $(PROG_NAME)

re: fclean all

.PHONY: clean fclean re all bonus
