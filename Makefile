.PHONY: all clean myTerm myBigChars  mySimpleComputer console myReadKey

SUBDIRS = myTerm myBigChars mySimpleComputer console myReadKey

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

console: myTerm myBigChars mySimpleComputer myReadKey

clean:
	for dir in $(SUBDIRS); do $(MAKE) -C $$dir clean; done
