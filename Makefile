NAME	=	rss_reader

SRCS	=	RssReader.cpp	\
		main.cpp

OBJS	=	$(SRCS:.cpp=.o)

CXXFLAGS=	-W -Wall -Werror -ansi -pedantic

CXX	=	g++ -o

LIBS	=	-ltinyxml

RM	=	rm -f

$(NAME)	:	$(OBJS)
		$(CXX) $(NAME) $(CXXFLAGS) $(OBJS) $(LIBS)

all	:	$(NAME)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all