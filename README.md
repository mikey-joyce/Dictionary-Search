# Dictionary Search
 This algorithm will take input of the size of a word and known letters with certain indices and outputs each word in the dictionary that matches it.
 This algorithm was designed to be used to solve crosswords that were partially filled out. The dictionary (words.txt) in question is a text file with a new set of words on each line roughly 450k+ lines long.
 
 Ex)
   Input)
   
     Size of Word: 5
     
     Amount of Letters to Input: 3
     
     Index 0: a
     
     Index 1: p
     
     Index 4: e
   
   Output)
   
     0: a
     
     1: p
     
     4: e
     
     apace
     
     Apple
     
     Apure
 
# Running Algorithm
To run this algorithm you must download 'searcher.c' and 'words.txt'. After you download these you can run the command: 
 
```gcc -w -o proj searcher.c```

And after this the command:

```./proj```

# Filling out data correctly
The algorithm will ask you if you want to make an entry. If you say no it will terminate the algorithm, otherwise it will continue to the user input portion. It will ask you how large of a word you are looking for, you will want to input an integer. Then it will ask you how many letters you want to input, you will want to enter an integer smaller than the one before. Then using this number it will prompt you that many times to enter in an index with a 'target' letter. Then it will search the dictionary with an array of these indices and will return all of the words in the dictionary that matched this criteria.
