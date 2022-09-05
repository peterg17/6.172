
# Writeup for C primer


## pointer.c

line 18: d prints out the first char of c - "6"
line 19: pc prints out the address of the pointer to c[0], actually prints nothing unless you change %c -> %p
line 25: pcp is valid because argv is itself an array of char pointers, so this is a pointer to argv[0] which is itself a pointer
line 28: I think that pcc2 is a constant pointer to a char, so kind of the previous var but inverted order
  - actually based on description of cp, I think I was wrong. This is probably also a pointer to char constant like pcc.
line 31: invalid because pcc is a pointer to a constant char and we've modified the char
line 32: valid because we deference pcp so the final type is char *
line 33: valid because argv[0] is a char *
line 37/38: both are invalid because we are changing the pointer cp which is supposed to be constant
line 39: I guess it is valid because we are changing the char it is pointing to but not the pointer itself?
line 43/44: these are both invalid because we can't change where a const pointer points to as we saw with cp
line 45: invalid because the thing cpc is pointing to is a char const, and we can't change its value

 








