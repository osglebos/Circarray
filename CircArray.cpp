#include "CircArray.h"

CircArray::CircArray(void) {}

CircArray::CircArray(int n) {
	indexIn = -1;
	indexOut = -1;
	buf_size = n;
	buffer = new Element[5];
	for (int i = 0; i < n; i++) {
		buffer[i].value = NULL;
	}
}

void CircArray::print(void)
{
	for (int i = 0; i < buf_size; i++)
		printf("%i ", buffer[i].value == NULL ? -1 : *(buffer[i].value));
	printf("\n");
}

void CircArray::put(int n)
{
	if (indexIn < 0 && indexOut < 0)
	{
		indexIn = 1;
		indexOut = 0;
		buffer[indexOut].value = new int(n);
		return;
	}

	buffer[indexIn].value = new int(n);
	if (indexIn == indexOut)	indexOut = (indexOut + 1) % buf_size;
	indexIn = (indexIn + 1) % buf_size;
}

int *CircArray::get(void)
{
	int *res = NULL;
	if (indexOut == -1) return res;
	res = new int(*(buffer[indexOut].value));
	delete(buffer[indexOut].value);
	buffer[indexOut].value = NULL;
	indexOut = (indexOut + 1) % buf_size;
	return res;
}
