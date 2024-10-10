# Makefile
CC = gcc
CFLAGS = -Wall -g

# Default rule to build all schedulers
all: fcfs sjf rr priority priority_rr

# FCFS scheduler
fcfs: driver.o schedulers.o list.o schedule_fcfs.o
	$(CC) $(CFLAGS) -DFCFS -o fcfs driver.o schedulers.o list.o schedule_fcfs.o

# SJF scheduler
sjf: driver.o schedulers.o list.o schedule_sjf.o
	$(CC) $(CFLAGS) -DSJF -o sjf driver.o schedulers.o list.o schedule_sjf.o

# Round Robin scheduler
rr: driver.o schedulers.o list.o schedule_rr.o
	$(CC) $(CFLAGS) -DRR -o rr driver.o schedulers.o list.o schedule_rr.o

# Priority scheduler
priority: driver.o schedulers.o list.o schedule_priority.o
	$(CC) $(CFLAGS) -DPRIORITY -o priority driver.o schedulers.o list.o schedule_priority.o

# Priority with Round Robin scheduler
priority_rr: driver.o schedulers.o list.o schedule_priority_rr.o
	$(CC) $(CFLAGS) -DPRIORITY_RR -o priority_rr driver.o schedulers.o list.o schedule_priority_rr.o

# Object files for driver and list
driver.o: driver.c
	$(CC) $(CFLAGS) -c driver.c

schedulers.o: schedulers.c
	$(CC) $(CFLAGS) -c schedulers.c

list.o: list.c
	$(CC) $(CFLAGS) -c list.c

# Object files for each scheduling algorithm
schedule_fcfs.o: schedule_fcfs.c
	$(CC) $(CFLAGS) -c schedule_fcfs.c

schedule_sjf.o: schedule_sjf.c
	$(CC) $(CFLAGS) -c schedule_sjf.c

schedule_rr.o: schedule_rr.c
	$(CC) $(CFLAGS) -c schedule_rr.c

schedule_priority.o: schedule_priority.c
	$(CC) $(CFLAGS) -c schedule_priority.c

schedule_priority_rr.o: schedule_priority_rr.c
	$(CC) $(CFLAGS) -c schedule_priority_rr.c

# Clean the build files
clean:
	rm -f *.o fcfs sjf rr priority priority_rr
