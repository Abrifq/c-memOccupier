# Memory Occupier

Occupies memory!
Really, that's the only use.

## Compiling

I use `gcc`, I don't know how you compile in `clang` or another C compiler, you might want to read their guides.

```bash
gcc -o main main.c -lm
```

## Usage

Just start without arguments. Occupies as many times as you want.

```bash
./main
```

or start with an argument for size to occupy &ndash;like 512M&ndash; in bytes. Occupies one time and then exits.

```bash
./main $(( 512 * (1024 ** 2) ))
```
