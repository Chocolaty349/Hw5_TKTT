import numpy as np

def split(matrix):
	row, col = matrix.shape
	row2 = row // 2
	col2 = col // 2
	return matrix[:row2, :col2], matrix[:row2, col2:], matrix[row2:, :col2], matrix[row2:, col2:]

def strassen(x, y):
	# Base case 
	if len(x) == 1 & len(y) == 1:
		return x * y

	a11, a12, a21, a22 = split(x)
	b11, b12, b21, b22 = split(y)

	p1 = strassen(a11, b12 - b22) 
	p2 = strassen(a11 + a12, b22)	 
	p3 = strassen(a21 + a22, b11)	 
	p4 = strassen(a22, b21 - b11)	 
	p5 = strassen(a11 + a22, b11 + b22)	 
	p6 = strassen(a12 - a22, b21 + b22) 
	p7 = strassen(a11 - a21, b11 + b12) 

	# Computing 4 quadrants of matrix C
	c11 = p5 + p4 - p2 + p6 
	c12 = p1 + p2		 
	c21 = p3 + p4		 
	c22 = p1 + p5 - p3 - p7 

	c = np.vstack((np.hstack((c11, c12)), np.hstack((c21, c22)))) 

	return c

matrix_A = np.matrix([ [1, 1, 1, 1], 
            [2, 2, 2, 2], 
            [3, 3, 3, 3], 
            [2, 2, 2, 2] ] )

matrix_B = np.matrix([ [1, 1, 1, 1], 
            [2, 2, 2, 2], 
            [3, 3, 3, 3], 
            [2, 2, 2, 2] ] )
 
result = strassen(matrix_A, matrix_B)
print(result)