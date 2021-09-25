# Word-Counts
Returns most frequent occuring words in a text file


usage: ./wordcounts MAX_N_OUT MIN_WORD_LEN MAX_WORD_LEN FILE...

MAX_N_OUT: Maximum number of words you want returned
MIN_WORD_LEN: Minimum length of each word you want returned
MAX_WORD_LEN: Maximum length of each word you want returned
FILE: File name, no quotations

Example:

./wordcounts 5 3 8 test_file.txt


Returns 5 words, with lengths between 3 and 8, from file called "test_file.txt"
