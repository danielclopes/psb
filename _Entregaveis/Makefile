MAIN      = main
CXX_SRCS  = Clube.cpp JogadorContrato.cpp Jogador.cpp JogadorLivre.cpp

CXX       = g++ 
CXX_OBJS  = ${CXX_SRCS:.cpp=.o}
MAIN_SRCS = $(wildcard *.cpp)
MAIN_OBJS = ${MAIN_SRCS:.cpp=.o}

all: $(MAIN) clean_obj

$(MAIN): $(MAIN_OBJS) $(CXX_OBJS)
	$(CXX) $(MAIN).o $(CXX_OBJS) -o $(MAIN)
	
clean: clean_obj
	@- $(RM) $(MAIN)
	
clean_obj:
	@- $(RM) $(MAIN_OBJS) $(CXX_OBJS)
