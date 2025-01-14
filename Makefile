# makefile for scheduling program
#
# make rr - for round-robin scheduling
# make fcfs - for FCFS scheduling
# make sjf - for SJF scheduling
# make priority - for priority scheduling
# make priority_rr - for priority with round robin scheduling

CC = gcc
CFLAGS = -Wall -g

clean:
	rm -rf *.o
	rm -rf fcfs
	rm -rf sjf
	rm -rf rr
	rm -rf priority
	rm -rf priority_rr

fcfs: driver.o schedulers.o list.o cpu.o schedule_fcfs.o
	$(CC) $(CFLAGS) -DFCFS -o fcfs driver.o schedulers.o schedule_fcfs.o list.o cpu.o

rr: driver.o schedulers.o list.o cpu.o schedule_rr.o
	$(CC) $(CFLAGS) -o rr driver.o schedulers.o schedule_rr.o list.o cpu.o 

sjf: driver.o schedulers.o list.o cpu.o schedule_sjf.o
	$(CC) $(CFLAGS) -o sjf driver.o schedulers.o schedule_sjf.o list.o cpu.o

priority: driver.o schedulers.o list.o cpu.o schedule_priority.o
	$(CC) $(CFLAGS) -o priority driver.o schedulers.o schedule_priority.o list.o cpu.o

schedule_fcfs.o: schedule_fcfs.c
	$(CC) $(CFLAGS) -c schedule_fcfs.c

priority_rr: driver.o list.o cpu.o schedule_priority_rr.o
	$(CC) $(CFLAGS) -o priority_rr driver.o schedule_priority_rr.o list.o cpu.o

driver.o: driver.c
	$(CC) $(CFLAGS) -c driver.c

schedulers.o: schedulers.c
	$(CC) $(CFLAGS) -c schedulers.c

schedule_sjf.o: schedule_sjf.c
	$(CC) $(CFLAGS) -c schedule_sjf.c

schedule_priority.o: schedule_priority.c
	$(CC) $(CFLAGS) -c schedule_priority.c

schedule_rr.o: schedule_rr.c
	$(CC) $(CFLAGS) -c schedule_rr.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

cpu.o: cpu.c cpu.h
	$(CC) $(CFLAGS) -c cpu.c
