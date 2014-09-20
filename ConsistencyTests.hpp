/*By Mark Keen
Consistency Testing*/

#include "Stream.hpp"
#include <iostream>
using namespace std;
using namespace CS422;

// Simply read sequentially through several bytes of data.
// Here I used ints because it was 4 bytes at a time.
int* testReadSequential(Stream &s, int location, int buff) {
	int returnValue[1024];
	for (int i = 0; i < buff/4; i++) {
		s.Read(&returnValue[i], 4);
	}
	return returnValue;
}

// Reading backwards was a bit trickier, but all it does is loop backwards
// from the end of the list based on buffer size.
int* testReadBackwards(Stream &s, int location, int buff) {
	int returnValue[1024];
	for (int i = buff/4; i > 0; i--) {
		s.Read(&returnValue[i], 4);
	}
	return returnValue;
}

// Build a random list of positions, then read from each one.
int* testReadRandom(Stream &s, int location, int buff) {
	int returnValue[1024];
	int randomValue[1024];
	// Initialize to -1
	for (int i = 0; i < 1024; i++) {
		randomValue[i] = -1;
	}
	// Then fill out the list of random positions.
	for (int i = 0; i < buff / 4; i++) {
		int r = rand() % (buff/4);
		if (randomValue[r] == -1) {
			randomValue[r] = i;
		}
		else i--;
	}
	// Finally, fill out the return values as randomly read bytes from the stream.
	for (int i = 0; i < buff / 4; i++) {
		int position = randomValue[i];
		s.Read(&returnValue[position], 4);
	}
	return returnValue;
}

// Test whether all three reads return the same thing.
void consistencyTesting(Stream &s) {
	if (s.GetLength() > 0) {
		int location = rand() % s.GetLength();
		int size = 128;

		// Run all three tests: Sequential, Backwards, and Random.
		int* seq = testReadSequential(s, location, size);
		int* back = testReadBackwards(s, location, size);
		int* random = testReadRandom(s, location, size);

		// Are they all the same?
		if (seq == back && back == random)
			printf("Data is consistent between all three read formats.\n");
		// Otherwise, error check.
		else {
			if (seq != back)
				printf("Error: Data is not consistent between sequential and backwards reading.\n");
			if (seq != random)
				printf("Error: Data is not consistent between sequential and random reading.\n");
			if (random != back)
				printf("Error: Data is not consistent between backwards and random reading.\n");
		}
	}
	else printf("Error: Cannot test consistency, attempting to read from empty stream.\n");
}
