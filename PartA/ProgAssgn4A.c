#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <pthread.h>

void CountingPoints(void);

void* Parent(void *param); 

double random_double(); 

int globalVar = 0; 	// Global Variable
int counter = 0; 	// Global Counter Variable
int totalPoints = 0; 	// Total points generated

int main(int argc, char* argv[]) {
	// Checks if argument count is 2
	if (argc != 2) {
		printf("Usage: %s <number of points (No less than 50000000)>\n", argv[0]); 
		return 1; 
	}

	// Setting numeric argument to an integer
	totalPoints = atoi(argv[1]);

	// Checks if the numeric argument is greater than 1
	if (totalPoints < 1) {
		printf("<number of points (No less than 50000000)> should be a positive integer\n"); 
		return 1; 
	}
	
	pthread_t parent; // Parent thread

	pthread_create(&parent, NULL, Parent, NULL); // Create parent thread

	pthread_join(parent, NULL); // Wait until parent thread completion

	pthread_exit(NULL); // exit thread
}

// Checks for valid points inside circle
void CountingPoints(void) {
	int i, count = 0;
	double x = 0.0, y = 0.0; 
	int hit = 0.0; // Valid points in circle
	
	for (i = 0; i < totalPoints; i++) {
		x = random_double(); // * 2.0 - 1.0 
		y = random_double(); 
		if (sqrt(x*x + y*y) < 1.0) {
			hit++; 
		}
	}
	globalVar = hit; 
}

double random_double() {
	return random() / ((double)RAND_MAX + 1); 
}

void* Parent(void *param) {
	CountingPoints(); 
	double pi; 
	pi = (double)(4*globalVar)/(totalPoints); 
	printf("Estimate of pi is %f \n", pi); 

}