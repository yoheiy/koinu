o := grep echo seq cat od printenv env true false ls wc head yes tee3 trunc
o += hello test caltab cmp primes more cut fold sed factor calcium lr pwd ncat
o += expand unexpand

vpath %.c src

.PHONY: all clean

all: $o

clean:
	$(RM) $o
