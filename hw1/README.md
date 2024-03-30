flex version: 2.6.4

OS envirnoment: Linux 231 5.15.0-82-generic \#91~20.04.1-Ubuntu SMP Fri Aug 18 16:24:39 UTC 2023 x86\_64 x86\_64 x86\_64 GNU/Linux

How to execute: `./lex.elf < test.pas`

How to solve the problem: Use regular expression to match the tokens; start states and yymore() to match comments; std::unordered\_set (static link) to record the identities.

Problem that I confronted: How to use c++ std lib in c envirnoment? How to determine the comments? 
