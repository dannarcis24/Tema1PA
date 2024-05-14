all:
	gcc main.c taskcodes.c lists.c data.c problems.c stack.c -I -l -o lanParty
clean:
	rm -f lanParty
