cc = g++
sdir = src
out = lib/libVNGin.a

$(out): $(sdir)/*.cpp $(sdir)/*.h
	@$(cc) -c $(sdir)/*.cpp -lSDL2 -lSDL2_image 
	@ar rcs $(out) *.o 
	@rm *.o

install: $(out) 
	@mkdir /usr/include/VNGin -p
	@cp $(sdir)/*.h /usr/include/VNGin
	@cp $(out) /usr/lib

uninstall: 
	@rm /usr/include/VNGin/*.h
	@rmdir /usr/include/VNGin
	@rm /usr/$(out) 
