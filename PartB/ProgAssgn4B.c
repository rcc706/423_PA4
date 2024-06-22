#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <pthread.h>

void* Parent(void *param); 

double random_double(); 

int globalVar = 0; 	// Global Variable
int counter = 0; 	// Global Counter Variable
int totalPoints = 50000000; 	// Total points generated (50M is the least acceptable)
pthread_mutex_t mutex; // mutex for sync

int main(int argc, char* argv[]) {

	pthread_mutex_init(&mutex, NULL); 

	// Checks if argument count is 2
	if (argc != 2) {
		printf("Usage: %s <number of threads>\n", argv[0]); 
		return 1; 
	}

	// Setting numeric argument to an integer
	int threadNum = atoi(argv[1]);

	// Checks if the numeric argument is greater than 1
	if (threadNum < 1) {
		printf("<number of threads> should be a positive integer\n"); 
		return 1; 
	}

	// Array to hold threads
	pthread_t workers[threadNum]; 

	// Thread attributes for threads
	pthread_attr_t attr; 

	int i; // Counter

	// Initialize default thread attributes
	pthread_attr_init(&attr); 

	// for-loop to create threads
	for (i = 0; i < threadNum; i++) {
		pthread_create(&workers[i], &attr, Parent, NULL); 
	}

	// for-loop to wait for all threads to exit
	for (i = 0; i < threadNum; i++) {
		pthread_join(workers[i], NULL); 
	}

	//pthread_mutex_destory(&mutex); 

	double pi; 
	pi = (double)(4*globalVar)/(totalPoints); 
	printf("Estimate of pi is %f \n", pi); 
}

double random_double() {
	return random() / ((double)RAND_MAX + 1); 
}

void* Parent(void *param) {
	pthread_mutex_lock(&mutex); 
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
	pthread_mutex_unlock(&mutex); 
}