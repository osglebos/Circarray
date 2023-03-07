#pragma once
#include <stdio.h>
class CircArray
{
	private:
		struct Element
		{
			int *value;
		};
		Element *buffer;
		int indexIn;
		int indexOut;
		int buf_size;

	public:
		CircArray(void);
		CircArray(int n);
		void print(void);
		void put(int n);
		int *get(void);
};