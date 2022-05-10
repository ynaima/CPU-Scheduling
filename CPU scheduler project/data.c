/*
 -------------------------------------
 Author:
 ID:
 Email:
 -------------------------------------
 */
#include<assert.h>
#include<stdlib.h>
#include "data.h"

void print_data(Data *d) {
	print_process(d);
	return;
}
void destroy_data(Data **d) {
	destroy_process(d);
	return;
}
Data* copy_data(Data *d) {
	return copy_process(d);
}
/**
 * ------------------------------------------------------------
 * Parameters: 	d1: A pointer to a data struct (Data*)
 * 				d2: A pointer to a data struct (Data*)
 * Returns: 	1: If d1 is greater than d2
 * 				2: If d2 is greater than d1
 * 				0: If d1 == d2
 * Description:	compares two data structs(processes);
 *
 * Assert:		d1 && d2 is not NULL
 * ------------------------------------------------------------
 */
int compare_data(Data *d1, Data *d2) {
	assert(d1 != NULL && d2 != NULL);
	if (d1->arrival > d2->arrival) {
		return 1;
	} else if (d1->arrival < d2->arrival) {
		return 2;
	} else {
		if (d1->time > d2->time) {
			return 1;
		} else if (d1->time < d2->time) {
			return 2;
		} else {
			if (d1->PID > d2->PID) {
				return 1;
			} else if (d1->PID < d2->PID) {
				return 2;
			}

			else
				return 0;
		}

	}
}

