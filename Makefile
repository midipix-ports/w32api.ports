all: install

install:
	mkdir -p $(DESTDIR)/include
	cp -r include/w32api.ports $(DESTDIR)/include
	cp -r README               $(DESTDIR)/include/w32api.ports
