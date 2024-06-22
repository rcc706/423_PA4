# Programming Assignment 4

2022-2023 Spring Semester

This program caculates pi be using the Monte Carlo technique to randomly generate a set amount of points (Minimum of 50000000). All the points that land within the incscibed circle in the square will be used in the following equation to calculate pi: 
* pi = 4 * (number of points in circle) / (total number of points)

---------------------------------------------------------

## Part A
This part of the programming assignment uses a thread to count the number of points that occur within the cirlce and stores it into a global variable. When the thread exits, the parent thread caculates pi and outputs the value of pi. 

### Compilation
```
    gcc ProgAssgn4A.c -lpthread -lm
```

The user will then be prompted to enter the amount of points to be generated (Assuming the executable file is a.out): 
```
    ./a.out 50000000
    Estimate of pi is 3.141446

```

Invalid compiling: 
```
    ./a.out
    Usage: ./a.out <number of points (No less than 50000000)>

```

```
    ./a.out 10 20
    Usage: ./a.out <number of points (No less than 50000000)>

```

```
    ./a.out -3
    <number of points (No less than 50000000)> should be a positive integer

```

---------------------------------------------------------

## Part B
This part of the programming assignment uses multiple threads to count the number of points that occur within the circle and to caculate the value of pi. Mutex locks are used to protect against race conditions. 

### Compilation
```
    gcc ProgAssgn4B.c -lpthread -lm
```

The user will then be prompted to enter the amount of threads to use (Assuming the executable file is a.out): 
```
    ./a.out 10
    Estimate of pi is 3.141466
```

Invalid compiling: 
```
    ./a.out
    Usage: ./a.out <number of threads>

```

```
    ./a.out 10 20
    Usage: ./a.out <number of threads>

```

```
    ./a.out -3
    <number of threads> should be a positive integer
```

---------------------------------------------------------