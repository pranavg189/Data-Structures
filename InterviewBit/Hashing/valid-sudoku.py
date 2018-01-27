'''
Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.

The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

 Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

'''

class Solution:
	# @param A : tuple of strings
	# @return an integer
	def isValidSudoku(self, A):
		
		# Set to store the location string for every number
		location_set = set()
		
		# Iterate over each number in the sudoku grid
		for r, row in enumerate(A):
			for c, num in enumerate(row):
				
				if num != '.':
				    
				    # Create location string for a number rowwise, columnwise
				    # and squarewise
					rowstr = str(num) + " in row " + str(r)
					columnstr = str(num) + " in column " + str(c)
					squarestr = str(num) + " in square " + str(r//3) + "-" + str(c//3)
					
					for locstring in [rowstr, columnstr, squarestr]:
					    
					    # We found a duplicate, if it was already present in the set
						if locstring in location_set:
							return 0
						else:
							location_set.add(locstring)
		
		# No duplicate found, return true		
		return 1
