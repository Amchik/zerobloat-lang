# ZeroBloat-Lang

`zerobloat-lang` is a blazing fast language written
in pure zero-bloat C (using `loslib`).

For now, its support only clang and 1 architecture:

* `x86_64`

## Building

ZeroBloat lang has ZERO BLOAT BUILD SYSTEM WRITTEN
IN ZERO-BLOAT SH SCRIPTS WITH ZERO BLOAT CONFIGURATION.

Edit `target` (and if you need, `cflags` and `ldflags`)
variables in `mk.conf` and type `./make`:

```console
$ ./make
```

## Hello world

ZeroBloat language has zero-bloat syntax: there no syntax.

```console
$ touch hello-world.zb
$ bin/zb-minimal.out hello-world.zb
Hello, world!
```

Also, there is professional version of `zb`:

```console
$ echo 'hello, world!' > hello-world.zb
$ zb hello-world.zb
hello, world!
```

## Safety

ZeroBloat is fully memory-safe language without
undefined behaviours (unlike C).

## To-Do List

- [x] ZeroBloat minimal version (`zb-minimal`)
- [x] True ZeroBloat (`zb`)

## Special thanks to

* Fucking C community
* Fucking Rust `#![no_std]` community

