# Divide & Conquer: Maximum Consecutive-Character Substring

A divide-and-conquer algorithm, its theoretical complexity analysis, and an experimental
time study — for the Algorithms and Data Structures course at the University of Murcia.

## The problem

> Given a string `A` of length `n`, a natural number `m ≤ n`, and a character `C`, find the
> substring `B` of size `m` within `A` with the most **consecutive** occurrences of `C`.
> Return the starting index of `B` and how many times `C` appears consecutively in it.

Example: `A = "cddabcdacc"`, `n=10`, `m=5`, `C='c'` → `B` starts at index 6, with 2
consecutive occurrences.

Full assignment statement in [`PROBLEMA.md`](PROBLEMA.md).

## Approach

The algorithm follows the classic divide-and-conquer scheme:
1. **Divide**: split the window into two halves.
2. **Conquer**: recursively solve each half independently.
3. **Combine**: merge the two partial solutions, additionally checking every length-`m`
   window that straddles the midpoint (the case a purely recursive split would miss).

The full design, pseudocode, and justification for the data structures used are in
[`memoria.pdf`](memoria.pdf) / [`memoria.tex`](memoria.tex), along with:
- A theoretical worst/best-case time complexity analysis.
- A correctness validation process against a brute-force reference implementation.
- An experimental time study across problem sizes from 10² to 10⁸, using a purpose-built
  test case generator (favorable, unfavorable, and average cases).
- A comparison between the theoretical and measured results, with the resulting
  time-vs-size plot ([`Figure_1.png`](Figure_1.png)).

## Structure

```
subcadena.cpp         The divide-and-conquer algorithm
generador.cpp          Test case generator (favorable / unfavorable / average cases)
grafica.py             Plots measured execution times (matplotlib)
casos/                 Generated test inputs
resultados_tiempos/    Raw timing measurements per case size
resultados.csv         Consolidated timing results
compilar.sh, run_test.sh   Build and benchmark scripts
memoria.pdf / .tex     Full write-up (design, complexity analysis, experimental study)
```

## Building

```sh
./compilar.sh
./subcadena < input.txt
```
