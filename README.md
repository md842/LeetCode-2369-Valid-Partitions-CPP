# LeetCode #2369: Check if There is a Valid Partition For The Array (Daily Challenge 08/13/2023)
This repository contains a C++ solution to the LeetCode daily challenge #2369 for 08/13/2023. https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

This solution beats 99.8% of users in runtime (111 ms) and 84.31% of users in memory usage (84.17 MB). 

I discuss the solution here: https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/solutions/3905725/c-o-n-time-o-n-space-99-8-runtime-84-31-memory/

## Running
Navigate to the directory containing the extracted implementation, then simply run `make` with the included Makefile.
```
cd LeetCode-2369-Valid-Partition-CPP
make
```

The exact commands run by `make` are as follows:

```
g++ -Wall -O0 -pipe -fno-plt -fPIC valid_partitions.cpp -o valid_partitions
```

There are no arguments; the test cases are hard-coded into the C++ file.

## Cleaning up
Navigate to the directory containing the extracted implementation, then simply run `make clean` with the included Makefile.

```
cd LeetCode-2369-Valid-Partition-CPP
make clean
```

The exact commands run by make clean are as follows:

```
rm -f valid_partitions
```
