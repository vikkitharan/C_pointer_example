make

valgrind \
  --leak-check=full \
  --show-leak-kinds=all \
  ./pointer
