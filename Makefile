SRC1    = server.c
SRC2    = client.c
NAME1  = server
NAME2  = client
CC     = cc
CFLAGS = -Wall -Wextra -Werror
RM     = rm -f

all :${NAME1}  ${NAME2}
${NAME1}:
	$(CC) $(CFLAGS) ${SRC1} -o ${NAME1}
${NAME2}:
	$(CC) $(CFLAGS) ${SRC2} -o ${NAME2}
clean: 
	@$(RM)  ${NAME1}  ${NAME2}
fclean: clean
re:   fclean all