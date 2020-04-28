# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

It is a word invented by the president of the National Puzzlers' League as a synonym for the disease known as silicosis.
It is the longest word in the English language published in a dictionary

## According to its man page, what does `getrusage` do?

returns resource usage measures for who(first arg in the function), in speller.c we use only RUSAGE_SELF which:
Return resource usage statistics for the calling process, which is the sum of resources used by all threads in the process.

## Per that same man page, how many members are in a variable of type `struct rusage`?

16 variables

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

becuse they are structs not a default data type like int

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

it read words char by char check if char is alphabitical char or apostrophe then save is to  string
if word is longer than 45 chars it continue reading it chars and ignore it
if word contain numbers it also continue reading it then ignore it

when it end igniring it set index to be 0

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

it will read words with numbers and long words

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

I think because data in word and in dictionary are constant and we dont want to change the data
