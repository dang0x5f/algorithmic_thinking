# algorithmic_thinking

### 00-food_lines

* https://dmoj.ca/problem/lkp18c2p1

```sh
cc food.c -o prog

./prog < food.txt
```

### 01-unique_snowflakes

* https://dmoj.ca/problem/cco07p2

```sh
cc unique_snowflakes.c -o prog

./prog < snowflakes.txt
```

### 01-hash_function

* one-at-a-time (oaat) hash function implementation[^1].

```sh
cc oaat.c -o prog

./prog 
```

### 01-compound_words

* https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1332

```sh
cc compound_words.c -o prog

./prog < words.txt
```

### 01-spelling_check

* https://codeforces.com/problemset/problem/39/J

```sh
cc spelling_check.c -o prog

./prog < words.txt
```

### 02-halloween_haul

* https://dmoj.ca/problem/dwite12c1p4

```sh
cc halloween_haul.c -o prog

./prog 
```

```sh
cc halloween_haul2.c -o prog

./prog < tree.txt
```

### 02-descendant_distance

* https://dmoj.ca/problem/ecna05b

```sh
cc descendant_distance.c -o prog

./prog < family_trees.txt
```

### 03-burger_fervor

* https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1406

###### recursive
```sh
cc burger_fervor1.c -o prog

./prog < burger_input.txt
```

###### recursive
```sh
cc burger_fervor2.c -o prog

./prog < burger_input.txt
```

###### memoization
```sh
cc burger_fervor3.c -o prog

./prog < burger_input.txt
```

###### dynamic programming
```sh
cc burger_fervor4.c -o prog

./prog < burger_input.txt
```

### 03-moneygrubbers

* https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1921

---

### notes

* Stdin gdb redirect[^999].

---

[^1]: https://burtleburtle.net/bob/hash/doobs.html
[^999]: https://stackoverflow.com/questions/4758175/how-to-use-gdb-with-input-redirection
