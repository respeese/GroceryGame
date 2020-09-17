CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

all: game

OBJS = main.o inputVal.o Aisle.o CoffeeStation.o Space.o Store.o Family.o Player.o SalesPerson.o Simulation.o GroceryList.o

SRCS = main.cpp inputVal.cpp Aisle.cpp CoffeeStation.cpp Space.cpp Store.cpp Family.cpp Player.cpp SalesPerson.cpp Simulation.cpp GroceryList.cpp

HEADERS = foodItemType.hpp inputVal.hpp Aisle.hpp CoffeeStation.hpp Space.hpp Store.hpp Family.hpp Player.hpp SalesPerson.hpp Simulation.hpp GroceryList.hpp 

game: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o game

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *o game
