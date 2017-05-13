main: simulate_roomba.o floor.o randomroomba.o smartroomba1.o smartroomba2.o roomba.o
	 g++ simulate_roomba.o floor.o randomroomba.o smartroomba1.o smartroomba2.o roomba.o -o a.out

simulate_roomba.o: simulate_roomba.cpp cmdline.h
	g++ -c simulate_roomba.cpp
floor.o: floor.cpp floor.h
	g++ -c floor.cpp
randomroomba.o: randomroomba.cpp randomroomba.h
	g++ -c randomroomba.cpp

roomba.o: roomba.cpp roomba.h
	g++ -c roomba.cpp

smartroomba2.o: smartroomba2.cpp smartroomba2.h
	g++ -c smartroomba2.cpp

smartroomba1.o: smartroomba1.cpp smartroomba1.h
	g++ -c smartroomba1.cpp

clean:
	rm *.o
