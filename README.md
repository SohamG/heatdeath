# Heat death of the universe

My maths prof gave us a problem and said if it were run on a computer, it would take longer than
the heat death of the universe. 

So naturally, I ran it on a computer.

# Problem

Define operation `*` as follows:
```
1 * n = n + 1
1 = (m-1) * 2
m * n = (m - 1) * (m * (n - 1))
```
Compute `5 * 5`

# Findings

I ran this on [Argonne National Labs' Supercomputer "Polaris"](https://docs.alcf.anl.gov/polaris/hardware-overview/machine-overview/)
with a max wall time of 30 minutes. The compute nodes have 512 GiB of RAM.

I ran the program twice. Both times, the file produced after 30 minutes was ~325GB in size (from the log output)
and the function for the `*` operator was invoked ~1.4 billion times.

The files ending in `.tail.X` are the last 10 lines of output of each of the two runs.

# License

[MIT](https://opensource.org/license/mit/)
