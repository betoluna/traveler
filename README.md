For this simple program, the user will type in a single string on a line by itself containing a set of state abbreviations separated by spaces. You are then to print out in order (one per line) each state that was visited; at the end, compute the total percentage of the US visited. You can assume that the same state does not appear in the input more than once, and that each abbreviation is two capital letters.
SAMPLE INPUT:
MA CT VT NY CA
SAMPLE OUTPUT:
CA
CT
MA
NY
VT
You have visited 10% of the United States.


The Rubric is based on two components: Code Quality and Performance
Code Quality Considerations
You must use a linked list implementation
Code must have cleanly separate Input - Process - Output parts
Must use NULL instead of 0 in code
Must include appropriate header files
Must have a typedef to describe data structure
Must use appropriate string functions (i.e., strcmp)
Performance
All percentages must be output in integers (like "10%" and "2%")
Must work on the sample example "MA CT VT NY CA"
Must work when given a single state as input "CT"
Must work when given two states as input "AK MA"
