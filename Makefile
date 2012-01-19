TARGETS=stfu.exe testwin.exe

all: $(TARGETS)

%.exe: %.c
	$(CC) $< -o $@

clean:
	rm -f $(TARGETS)

.PHONY: clean all
