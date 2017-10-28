import sys

def solve(change):
	return 0


def main():
	change = []
	set_to_solve = []

	with open(sys.argv[1]) as f:
		change = f.readlines()

	for string in change:
		set_to_solve.append(int(string))
	
	for problem in set_to_solve:
		val = solve(problem)
		print ("There are " + str(val) + " ways to produce " + str(problem) + " cents change.")

	return 0

main()