build/greeting: main.c build/greeting.c
	$(CC) -Ibuild -I/usr/include/python3.8 $^ -lpython3.8 -o $@

build/greeting.c: greeting.pyx
	mkdir -p $(@D)
	cython $< -o $@

clean:
	rm -rf build