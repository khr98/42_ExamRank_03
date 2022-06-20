gcc micro.c -o a.out -Wall -Wextra -Werror
gcc criteria.c -o original -Wall -Wextra -Werror
echo "-------------------------------------------------------"
echo "TEST - <ex_1>"
echo "NO original"
./a.out ./test/ex_1
echo "Original"
./original ./test/ex_1
echo "-------------------------------------------------------"
echo "TEST - <ex_2>"
echo "NO original"
./a.out ./test/ex_2
echo "Original"
./original ./test/ex_2
echo "-------------------------------------------------------"
echo "TEST - <ex_3>"
echo "NO original"
./a.out ./test/ex_3
echo "Original"
./original ./test/ex_3
echo "-------------------------------------------------------"
echo "TEST - <ex_4>"
echo "NO original"
./a.out ./test/ex_4
echo "Original"
./original ./test/ex_4
echo "-------------------------------------------------------"
echo "TEST - <NULL>"
echo "NO original"
./a.out
echo "Original"
./original
echo "-------------------------------------------------------"
echo "TEST - <Error file>"
echo "NO original"
./a.out ./test/ex
echo "Original"
./original ./test/ex
rm a.out
rm original