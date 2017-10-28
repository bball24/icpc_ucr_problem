lines = input()

encypted_results = []

for i in range(0,lines):
	curr_result = input()
	encypted_results.append(str(curr_result))

# positive result
for result in encypted_results:
	if result == "1" or result == "4" or result == "78":
		print("+")