# Top-level Makefile (recursive)
.PHONY: all build clean test

SUBDIRS := src

all: build

build:
	@for d in $(SUBDIRS); do $(MAKE) -C $$d; done

test:
	@for d in $(SUBDIRS); do $(MAKE) -C $$d test; done

clean:
	@for d in $(SUBDIRS); do $(MAKE) -C $$d clean; done

