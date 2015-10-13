CC = g++
CFLAGS = `pkg-config --cflags opencv` `pkg-config --libs opencv`

rotate : main.cpp
	PKG_CONFIG_PATH=/usr/local/lib/pkgconfig && \
	export PKG_CONFIG_PATH && \
	$(CC) $(CFLAGS) main.cpp -o rotate

