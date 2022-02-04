NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	./pipex.c						\
		./utils/ft_pathjoin.c			\
		./utils/ft_split.c				\
		./utils/ft_strjoin.c			\
		./utils/ft_strlen.c				\
		./utils/get_args.c				\
		./utils/get_filename.c			\
		./utils/get_paths.c				\
		./utils/process.c				\
		./utils/process2.c				\
		./utils/check_save_cmd_utils.c	\
		./utils/check_save_cmd.c		\
		./utils/check_cmds_is_valid.c	\
		./utils/ft_isalpha.c

OBJS =	$(SRCS:.c=.o)

%.o : %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all