*This project has been created as part of the 42 curriculum by takaraka, <login2>.*

# push_swap

## Description

`push_swap` sorts a stack of integers using only a fixed set of stack
operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`,
`rrr`) and prints the sequence of operations that sorts stack `a` in
ascending order.

This version follows the *new* push_swap subject (v1.1): the program embeds
**four sorting strategies**, measures the **disorder** of the input before
doing any move, and either uses the strategy forced by a command-line flag or
lets an **adaptive dispatcher** pick one according to the measured disorder.

Key idea of the subject: **complexity is measured in the number of push_swap
operations generated**, not in CPU time. All C-side analysis (computing the
disorder, assigning ranks, choosing which element is cheapest to move) is
free in this model; only the printed operations count.

## Instructions

### Build

```bash
make          # builds ./push_swap (and the bundled libft / ft_printf)
make clean    # removes object files
make fclean   # removes objects and the binary
make re       # fclean + all
```

### Usage

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <numbers...>
```

* Numbers can be given as separate arguments (`./push_swap 3 2 1`) and/or as
  one quoted string (`./push_swap "3 2 1"`). The first number is the top of
  stack `a`.
* Strategy selectors (at most one; `--adaptive` is the default):

  | flag         | strategy                        | class        |
  |--------------|---------------------------------|--------------|
  | `--simple`   | cost-based insertion ("Turk")   | O(n²)        |
  | `--medium`   | √n chunk sort                   | O(n√n)       |
  | `--complex`  | LSD radix sort                  | O(n log n)   |
  | `--adaptive` | picks one of the above by disorder | see below |

* `--bench` prints, **on stderr**, the disorder (in %), the strategy used and
  its class, the total number of operations and the count of every operation
  type. The operation stream stays on stdout, so both can be separated:

```bash
$ ./push_swap --bench $(shuf -i 0-9999 -n 500) 2>bench.txt | ./checker_linux $(...)
OK
$ cat bench.txt
[bench] disorder: 49.87%
[bench] strategy: medium (sqrt(n) chunk sort), O(n*sqrt(n)) [selected by adaptive]
[bench] total operations: 6062
[bench] sa: 0
...
```

* Errors (non-integer, out of `int` range, duplicates, empty argument,
  unknown or conflicting flags) print `Error` on **stderr** and exit with
  status 1. With no argument at all the program prints nothing and exits 0.

### Verify with the checker

```bash
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG   # OK
```

## Project layout

| file(s)                          | role                                                   |
|----------------------------------|--------------------------------------------------------|
| `push_swap.c`                    | `main`, argument loop, syntax pre-check                 |
| `argument_check_utils*.c`        | flag parsing, number validation, `error_exit`           |
| `stack_utils*.c`                 | doubly linked node/stack, creation, freeing              |
| `stack_operations.c`             | raw mechanics: `swap`, `push_to`, `rotate`, `reverse_rotate` (no output) |
| `operations*.c`                  | **operation layer**: `op_sa` … `op_rrr` — apply, print, count |
| `strategy.c`                     | `compute_disorder`, `set_ranks`, adaptive dispatcher     |
| `bench.c`                        | `--bench` report on stderr                                |
| `algorithm_sort.c`, `algorithm_utils*.c` | simple strategy (`sort_simple`, cost-based insertion) |
| `sort_medium.c`                  | medium strategy (√n chunks)                               |
| `sort_complex.c`                 | complex strategy (LSD radix)                              |

Every operation goes through exactly one function of the operation layer,
which executes it on the linked lists, prints its name and increments the
matching counter in a `t_counter` struct owned by `main` (both stacks hold a
pointer to it, so no global variable is needed).

## The complexity model

The subject defines the cost of a strategy as **the number of operations it
prints**. Consequences that drive the whole design:

* Computing the disorder is an O(n²) C loop but generates **zero**
  operations: it is measured once on the initial stack `a`, before any move,
  and is never re-measured.
* **Ranking** (replacing each value by its position 0..n-1 in sorted order)
  is done with an O(n²) scan in `set_ranks`. It generates no operation, so it
  does not enter the complexity budget of the chunk or radix strategies.
  Three remarks for the sceptic:
  1. the subject (VI.3.1) explicitly defines the cost as operations
     generated, so C-side work is outside the model by definition;
  2. the O(n²) strategy already performs an O(n·m) target search before
     *every* push — the same kind of free analysis;
  3. O(n²) is not intrinsic: copying the values into an array, sorting it in
     O(n log n) and binary-searching each value gives the same ranks in
     O(n log n) CPU time. We kept the simple scan because it is shorter and
     the model does not charge for it.
* Space is also counted in the model: two stacks of at most n nodes in total
  (an element is never duplicated, `push_to` relinks the node), plus O(1)
  integers per node (`rank`, `index`, cost fields). Total space **O(n)** for
  every strategy; no recursion, no auxiliary arrays.

## Disorder metric

```
disorder = (number of pairs (i<j) with a[i] > a[j]) / (number of pairs)
```

Implemented in `compute_disorder` with a double loop over the linked list.
0 = sorted, 1 = strictly decreasing. For a uniformly random permutation the
expected value is exactly 0.5 (each pair is inverted with probability ½) with
a very small spread (standard deviation ≈ 0.015 for n = 500), so random test
inputs land on **both sides of the 0.5 threshold**.

## The four strategies

### 1. Simple — cost-based insertion ("Turk" algorithm), O(n²)

`sort_simple` (`algorithm_sort.c`): push two elements to `b`, then repeat:
for every element of `a` compute its target in `b` (largest smaller value)
and the number of rotations needed to bring both to the top, choose the
cheapest, rotate (using `rr`/`rrr` when both go the same way) and `pb`.
When three elements remain, sort them in ≤ 2 moves, then push everything back
inserting each element of `b` above its target in `a`; finally rotate the
minimum to the top.

*Upper bound.* When `a` holds k and `b` holds m elements (k + m = n), bringing
the chosen element to the top costs at most ⌊k/2⌋ rotations (the shorter
direction is always taken) and its target at most ⌊m/2⌋, so one push costs at
most n/2 + 1. With n pushes the first phase is ≤ n²/2 + n; the second phase
(n times "rotate target to top, `pa`") is again ≤ n²/2 + n. Total
**O(n²)**. This is an insertion sort in the operation model: inserting an
element costs O(n), and there are n insertions. The cost analysis only lowers
the constant; it does not change the bound.

### 2. Medium — √n chunk sort, O(n√n)

`sort_medium` (`sort_medium.c`), on ranks 0..n-1 with s = ⌈√n⌉:

* **Phase 1 (a → b).** Scan `a` in one direction only (`ra`). The set of
  pushable ranks is a *sliding window* `[0, pushed + s)`. If the top of `a`
  is in the window, `pb`; if its rank is in the lower half of the window,
  `rb` as well (so `b` keeps its largest elements near its top and its
  bottom). Otherwise `ra`.
* **Phase 2 (b → a).** While `b` is not empty: find the maximum of `b`
  (C-side scan), rotate it to the top by the shorter direction
  (`rb` or `rrb`), `pa`.

*Upper bound.* At the start of any full rotation of `a`, exactly
min(s, remaining) not-yet-pushed elements have a rank inside the window, and
all of them are pushed during that rotation (the window only grows). Hence
at most ⌈n/s⌉ = O(√n) full rotations, each ≤ n `ra`: phase 1 ≤ n√n + n `pb`
+ n `rb`. For phase 2: when element M of rank R is pushed, fewer than s
unpushed elements have a rank below R (window property); therefore at pull
time at most s−1 elements lie between M and the insertion point on M's side
of `b`, and the current top of `b` (the position of the previous maximum) is
also within s−1 of that point, so each `pa` is preceded by at most 2s
rotations: phase 2 ≤ n(2s + 1). Total **O(n√n)** (≈ 6 000 operations for
n = 500, ≈ 680 for n = 100 in practice).

### 3. Complex — LSD radix sort, O(n log n)

`sort_complex` (`sort_complex.c`), on ranks, bit by bit from the least
significant: for each of the ⌈log₂ n⌉ bits, walk through `a` once — element
with bit = 0 → `pb`, bit = 1 → `ra` — then `pa` everything back. Each pass is
stable (pushing to `b` and back preserves the relative order), so after bit i
the stack is sorted by its i+1 low bits. A pass is skipped as soon as `a` is
sorted.

*Upper bound.* One pass costs n (`pb` or `ra`) + #zeros (`pa`) ≤ 2n, and
there are ⌈log₂ n⌉ passes: ≤ 2n⌈log₂ n⌉ = **O(n log n)**. The cost is
independent of the input order (6784 operations for any 500 distinct values,
1084 for 100).

### 4. Adaptive — disorder-driven dispatcher

`run_strategy` (`strategy.c`) measures the disorder once, then:

| disorder d       | strategy used | guaranteed class |
|------------------|---------------|------------------|
| d < 0.2          | simple        | O(n²)            |
| 0.2 ≤ d < 0.5    | medium        | O(n√n)           |
| d ≥ 0.5          | complex       | O(n log n)       |

If a selector flag is given, the dispatcher is bypassed and the flag decides,
whatever the size or disorder.

#### Why these thresholds

The regimes are the ones required by the subject; what we justify is why
each regime's method is the *right* one there.

* **d < 0.2 → insertion-type method.** An insertion-based sort pays for
  every inversion it has to undo; with few inversions most elements are
  already close to their final neighbour and the cost analysis finds a cheap
  move (rotating a few positions, often shared with `rr`/`rrr`). The
  quadratic bound is a worst case that nearly-sorted inputs stay far from:
  measured on n = 500, ≈ 1 200 – 1 900 operations for d ≤ 0.1, against a
  flat 6 784 for radix.
* **0.2 ≤ d < 0.5 → chunks.** Once the order is genuinely mixed, the
  insertion cost per element grows with the distance to its target, and the
  O(n²) bound becomes the real risk. The chunk strategy still profits from
  partial order (elements already roughly in place enter the window early
  and cost few rotations in phase 1), while its O(n√n) bound caps the
  damage.
* **d ≥ 0.5 → radix.** d = 0.5 is the expected disorder of a *random*
  permutation; larger values mean the input is closer to *reversed* than to
  sorted. Radix is the only one of the three whose cost does not depend on
  the input order at all, and the only one with an n log n bound, so it is
  the safe choice when no structure can be exploited.

Measured averages (5 seeds per row, inputs generated from a sorted array by
random swaps):

| n   | disorder | simple | medium | complex |
|-----|----------|--------|--------|---------|
| 100 | 3 %      | 252    | 404    | 1084    |
| 100 | 12 %     | 334    | 337    | 1084    |
| 100 | 29 %     | 509    | 580    | 1084    |
| 100 | 50 %     | 612    | 673    | 1084    |
| 500 | 2 %      | 1719   | 2127   | 6784    |
| 500 | 10 %     | 1887   | 2555   | 6784    |
| 500 | 28 %     | 3966   | 4805   | 6784    |
| 500 | 49 %     | 5832   | 6140   | 6784    |

The table also shows the honest limit of the design: on these sizes the
cost-based insertion has the best *average*, even at d ≈ 0.5. The adaptive
dispatcher nevertheless follows the subject's per-regime **upper-bound**
targets: at high disorder only the radix strategy guarantees O(n log n)
operations for every input, while the insertion strategy can degrade to
quadratic cost.

### Complexity summary (push_swap model)

| strategy | time (operations)              | space            |
|----------|--------------------------------|------------------|
| simple   | ≤ n² + 2n                      | O(n) nodes       |
| medium   | ≤ n√n + n(2√n + 1) + 2n        | O(n) nodes       |
| complex  | ≤ 2n⌈log₂ n⌉                   | O(n) nodes       |
| adaptive | bound of the selected strategy | O(n) nodes       |

Disorder measurement and ranking add O(n²) CPU work and O(1) per node, but
no operations.

## Contributions

| learner   | contribution |
|-----------|--------------|
| takaraka  | parsing and error handling, stack structure and operation layer, simple/medium/complex strategies, adaptive dispatcher, `--bench`, README |
| <login2>  | *(to be completed by the team: e.g. testing, review, defense preparation)* |

Both learners can explain every part of the code.

## Resources

* 42 push_swap subject v1.1 (`en.subject.pdf`).
* Inversion number / Kendall tau distance — the disorder metric:
  https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)
* Radix sort (LSD): https://en.wikipedia.org/wiki/Radix_sort
* "Push_swap: the Turk algorithm" — cost-based insertion widely documented in
  the 42 community (e.g. https://medium.com/@ayogun/push-swap-c1f5d2d41e97).
* Chunk-based push_swap strategies:
  https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

### How AI was used

An AI assistant (Claude, in Claude Code) was used as a *mentor* during the
migration from the old single-algorithm solution to the new subject:

* reading the subject and the existing code and mapping which parts could be
  reused (parsing, stack mechanics) and which had to be added;
* questioning the complexity reasoning (why the existing algorithm is O(n²)
  in the operation model, why ranking is "free") until the arguments above
  could be stated by the learner;
* refactoring the printing into a single operation layer with counters, and
  drafting the medium and complex strategies, the dispatcher, the bench
  output and this README, in the existing code style;
* generating test scripts (random inputs, error cases, valgrind, disorder
  sweeps) that produced the tables above.

All generated code was reviewed, traced by hand on small inputs and tested
with the official checker by the learners, who take responsibility for it.
