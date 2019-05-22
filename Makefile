NAME		= wolf3d

OBJDIR		= objs/
SRCDIR		= srcs/
LFTDIR		= libft/
SDLDIR		= $(HOME)/.brew/Cellar/sdl2/2.0.9_1/lib/
INCDIR		= ./includes/ ./libft/ /$(HOME)/.brew/Cellar/sdl2/2.0.9_1/include/SDL2

SRC			= main.c

LFT			= ./libft/libft.a

CSRC		= $(addprefix $(SRCDIR), $(SRC))
COBJ		= $(addprefix $(OBJDIR), $(OBJ))
INCLUDES	= $(foreach include, $(INCDIR), -I$(include))

CC			= gcc
OBJ			= $(SRC:.c=.o)
LIBS		= -L$(LFTDIR) -lft -L$(SDLDIR) -lSDL2
CFLAGS		= $(INCLUDES) -Wall -Wextra -Werror

YELLOW = \033[033m
GREEN = \033[032m
BLUE = \033[36m
RED = \033[031m
PURPLE = \033[35m
RESET = \033[0m

all: $(NAME)

$(NAME): $(LFT) $(OBJDIR) $(COBJ)
	@if !(brew ls --versions sdl2) > /dev/null; then\
		brew install sdl2;\
	fi
	@echo "$(YELLOW)Sources compilation $(RESET)[$(GREEN)OK$(RESET)]\n"
	@$(CC) $(CFLAGS) $(LIBS) -o $(NAME) $(COBJ)
	@echo "[$(BLUE)$(NAME) Compiled$(RESET)]"

$(OBJDIR):
	@mkdir -p $(OBJDIR)


$(OBJDIR)%.o: $(SRCDIR)%.c
	@echo "$(YELLOW)$(notdir $(basename $@))...$(RESET)[$(GREEN)OK$(RESET)]"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LFT):
	@make -sC $(LFTDIR) -j

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "\n$(RED)Obj directory...$(RESET)[$(PURPLE)deleted$(RESET)]\n"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(RED)Libft...$(RESET)[$(PURPLE)deleted$(RESET)]\n"
	@rm -f $(NAME)
	@echo "$(RED)$(NAME)...$(RESET)[$(PURPLE)deleted$(RESET)]\n"

re: fclean all

.PHONY: all clean fclean re
