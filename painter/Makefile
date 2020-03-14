OUT += -o ../painter/bin/Painter.out 	

CFLAGS += -std=c11 
LDFLAGS += `pkg-config --cflags --libs allegro-5 allegro_primitives-5 allegro_image-5 allegro_color-5 allegro_dialog-5` -lm
	
GCC += gcc
	
Source += ../painter/src/prog.c

build:
	$(GCC) $(Source) $(CFLAGS) $(LDFLAGS) $(OUT)
	@echo "BUILD SUCCESSFULLY"

run:
	@./bin/Painter.out
