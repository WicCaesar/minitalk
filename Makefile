#MAKEFLAGS = --silent
NAME	= $(SERVER) $(CLIENT)
SERVER = server
CLIENT = client
SERVERSOURCE = server.c
CLIENTSOURCE = client.c
SERVEROBJECT = $(SERVERSOURCE:.c=.o)
CLIENTOBJECT = $(CLIENTSOURCE:.c=.o)
LIBFTPATH = libft/
#LIBFTOBJECTSPATH = $(LIBFTPATH)objects/
LIBFTA	= libft.a
LIBFT	= $(LIBFTPATH)$(LIBFTA)
COMPILE	= cc
FLAGS	= -Wall -Wextra -Werror
REMOVE	= rm -f

all:	$(NAME)

# In order to pass an argument to the compiler, use the -D flag and set a
# variable such as $(X) and when calling make, add X = 3, for instance.

# Compiles from open-source to binary, but doesn't link. Necessary to run flags.
.c.o:
	$(COMPILE) $(FLAGS) -c $< -o $(<:.c=.o)

# Calling its name acts as its own makefile. Will compile only if the object 
# dependencies are fulfilled. ar creates an archive (here, library) from the 
# files member (objects), replacing them as needed. ranlib simply indexes 
# every function in the library (equivalent to s in crs).
# '@' hides the clutter from the terminal.
# It searches for the libft library in its original location, avoiding relinks.
$(NAME):	$(SERVEROBJECT)	$(CLIENTOBJECT)

$(LIBFT):
	make $(LIBFTA) -C $(LIBFTPATH)

$(SERVER):	$(LIBFT) $(SERVEROBJECT)
	$(COMPILE) $(FLAGS) $(LIBFT) server.o -o $(SERVER)

$(CLIENT):	$(LIBFT) $(CLIENTOBJECT)
	$(COMPILE) $(FLAGS) $(LIBFT) client.o -o $(CLIENT)

clean:
	@$(REMOVE) $(SERVEROBJECT) $(CLIENTOBJECT)
	@$(REMOVE) $(BONUSSERVEROBJECT) $(BONUSCLIENTOBJECT)
	@make clean -C $(LIBFTPATH)
	@echo "\033[0;32mLimpíssimo!\033[0m"
#	@$(REMOVE)r $(OBJECTSPATH)

fclean:		clean
	@$(REMOVE) $(SERVER) $(CLIENT) $(NAME) $(LIBFT) server_bonus client_bonus
	@make fclean -C $(LIBFTPATH)

re:		fclean all

BONUS = $(BONUSSERVER) $(BONUSCLIENT)
BONUSSERVER = server_bonus
BONUSCLIENT = client_bonus
BONUSSERVERSOURCE = server_bonus.c
BONUSCLIENTSOURCE = client_bonus.c
BONUSSERVEROBJECT = $(BONUSSERVERSOURCE:.c=.o)
BONUSCLIENTOBJECT = $(BONUSCLIENTSOURCE:.c=.o)

bonus:	$(LIBFT) $(BONUSSERVEROBJECT) $(BONUSCLIENTOBJECT)
	$(COMPILE) $(FLAGS) $(LIBFT) server_bonus.o -o $(BONUSSERVER)
	$(COMPILE) $(FLAGS) $(LIBFT) client_bonus.o -o $(BONUSCLIENT)

# Ignores files that could eventually be named after any of these rules.
.PHONY:		all clean fclean re 