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

I haven't found any cases where it doesn't format code as I would expect, so I there aren't any known bugs to fix. But this WAS built in an afternoon so it has big issues regarding tidyness of the code.

Something else that I would change is that group sizes are hard-coded in the implementation, when it would make more sense if they were command line parameters instead.

Regarding overall structure, this just loops through a string in a rather careless way, which makes extending it rather difficult. It also reads entire files in a single go disregarding the posibility of very large files (which wasn't in my original use case, but it would be nice if we dealt with that properly).

If it wasn't clear from me listing issues in a section called 'Contributing', contributions are very much welcome, and I would appreciate them a lot.
