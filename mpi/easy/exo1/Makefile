all: run

para:
	mpic++ main.cpp -o run
	
run: para
	srun -n 6 ./run

clean:
	rm run