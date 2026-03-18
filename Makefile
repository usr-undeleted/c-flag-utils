.SILENT:
msg:
	echo "Pick beetwen 'one' or 'two' for example code."

clean:
	rm -rf bin/*

one:
	gcc -o ./bin/one -I ./src ./src/example1.c

two:
	gcc -o ./bin/two -I ./src ./src/example2.c
