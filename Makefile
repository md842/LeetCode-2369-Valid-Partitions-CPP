CFLAGS = -std=gnu17 -Wall -O0 -pipe -fno-plt -fPIC
CPPFLAGS = -Wall -O0 -pipe -fno-plt -fPIC

default: valid_partitions_cpp

valid_partitions: valid_partitions.c
	$(CC) $(CFLAGS) valid_partitions.c -o valid_partitions

valid_partitions_cpp: valid_partitions.cpp
	g++ $(CPPFLAGS) valid_partitions.cpp -o valid_partitions

.PHONY: clean
clean:
	rm -f valid_partitions
