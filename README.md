# BFAF - BrainFuck Auto Formatter

Tiny command line utility that gives reasonable formatting for brainfuck files.

    -- BrainFuck Auto Formatter --
    -- by Sebastian Mestre --
    -- usage: bfaf [-o <name>] <file>
    -- default out is <file>.formatted


Converts:

```bf
[-]+++++++hello there!+[>+++>++>++++>+++++<<<<-]
```

To:


```bf
[-]
++++ +++
hello there!
+
[
	>
	+++
	>
	++
	>
	++++
	>
	++++ +
	<<<<
	-
]
```

Most of what it does is just indentation and separating different operators to different lines, but it does pack a few more tricks that make formatting a bit nicer:

 - Idiomatic interpretation of `[-]` and `[+]` as a single unit
 - Grouping of strings of the same operator into groups of 4, space separated
 - Grouping of strings of the same operator into groups of 16, new line separated
 - Mantaining of whitespace on strings of non-brainfuck characters

## Building

At the moment it's a single .cpp file, so you can compile it directly using your favorite compiler. I like GCC so, in my case, it looks like this:

```sh
g++ src/main.cpp -o bin/bfaf
```

## Contributing

Contributions are very much welcome, and I would appreciate them a lot.

You can look at the issues on github.
