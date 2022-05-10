/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include "A8.h"

/*---------------------Task 1 -----------------------------*/
void schedule(char *type, Data *processes, const int size) {
	if (processes == NULL) {
		printf("Error(schedule): Unsupported scheduler type\n");
		return;
	}
	char *ptr = type;
	ptr = ptr + 2;
	int period;
	period = (unsigned int) strtol(ptr, &ptr, 10);
	int count = strlen(type) - 2;

	char period_str[count];
	sprintf(period_str, "%d", period);
	char new_str[strlen(type)];

	char RR[3] = "RR";

	strcat(new_str, RR);
	strcat(new_str, period_str);

	pQueue *q = create_pqueue((size + size / 2), 'L');
	for (int i = 0; i < size; i++) {
		insert_pqueue2(q, &processes[i]);
	}

	if (strcmp(type, "FIFO") == 0) {
		schedule_FIFO(q);
		return;
	}

	else if (strcmp(type, "SJF") == 0) {
		schedule_SJF(q);
		return;
	}

	else if (strcmp(type, new_str) == 0) {
		schedule_RR(q, period);
		return;

	} else
		printf("Error(schedule): Unsupported scheduler type\n");
	return;
}

/*---------------------Task 2 -----------------------------*/
void schedule_FIFO(pQueue *q) {
	int timer = 0;
	printf("[Timer:%d]: Starting FIFO Scheduler\n", timer);
	timer++;
	while (peek_pqueue2(q)->arrival > timer) {
		printf("[Timer:%d]: Idle\n", timer);
		timer++;
	}

	while (!is_empty_pqueue(q)) {
		if (peek_pqueue2(q)->arrival > timer) {
			printf("[Timer:%d]: Idle\n", timer);
			timer++;
			continue;
		}
		Data *d = remove_pqueue2(q);
		int rounds = d->time;

		printf("Fetching Process: ");
		print_data(d);
		printf("\n");
		for (int i = 0; i < rounds; i++) {
			printf("[Timer:%d]: ", timer);
			print_data(d);
			printf("\n");
			timer++;
		}

	}

	printf("[Timer:%d]: Closing FIFO Scheduler\n", timer);

	return;
}

/*---------------------Task 3 -----------------------------*/
void schedule_SJF(pQueue *q) {
	int timer = 0, arrived = 0;
	printf("[Timer:%d]: Starting FIFO Scheduler\n", timer);
	timer++;
	while (peek_pqueue2(q)->arrival > timer) {
		printf("[Timer:%d]: Idle\n", timer);
		timer++;

	}
	if (peek_pqueue2(q)->arrival > timer)
		arrived = 1;
	else
		arrived = 1;
	while (!is_empty_pqueue(q) && arrived) {
		if (peek_pqueue2(q)->arrival > timer) {
			printf("[Timer:%d]: Idle\n", timer);
			timer++;
			continue;
		}
		printf("I am here\n");
		Data *buffer = (Data*) malloc(sizeof(Data) * len_pqueue(q));
		Data *d = remove_pqueue2(q);
		buffer = d;
		buffer++;
		continue;
		buffer--;
		Data *shortest = buffer;
		int shortest_time = shortest->time;
		while (buffer) {
			if (buffer->time < shortest_time) {
				shortest_time = buffer->time;
				shortest = buffer;
				buffer--;
			}
		}

		buffer++;
		while (buffer) {
			insert_pqueue2(q, buffer);
			buffer++;
			destroy_data(&buffer);
		}
		free(buffer);
		buffer = NULL;
		int rounds = shortest->time;
		printf("I made it her\n");
		printf("Fetching Process: ");
		print_data(shortest);
		printf("\n");
		for (int i = 0; i < rounds; i++) {
			printf("[Timer:%d]: ", timer);
			print_data(d);
			printf("\n");
			timer++;
		}
	}

	printf("[Timer:%d]: Closing FIFO Scheduler\n", timer);
	return;
}

/*---------------------Task 4 -----------------------------*/
void schedule_RR(pQueue *q, int period) {
//your code
	return;
}
