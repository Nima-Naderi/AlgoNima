g++ sol.cpp -std=c++17 -o main
g++ naive.cpp -std=c++17 -o naive
g++ gen.cpp -std=c++17 -o gen
for((i = 1; ; ++i)); do
	echo test case: $i
	./gen $i > input
	./naive < input > output1
	./main < input > output2
	diff -w output1 output2 || break
	echo passed!
done
