# BFAF - BrainFuck Auto Formatter

Tiny command line utility that gives reasonable formatting for brainfuck files.

    -- BrainFuck Auto Formatter --
    -- by Sebastian Mestre --
    -- usage: bfaf [-o <name>] <file>
    -- default out is <file>.formatted


Converts:

    [-]+++++++hello there!+[>+++>++>++++>+++++<<<<-]

To:


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

