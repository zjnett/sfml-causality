# Makefile for sfml-causality
# Zach Nett 9/28/19, last modified: 9/28/19

CXX = g++
OBJS = main.o
LDLIBS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

causality: $(OBJS)
		$(CXX) -o causality $(OBJS) $(LDLIBS) $(LDFLAGS)

$(OBJS): Game.hpp

clean:
	$(RM) causality $(OBJS)