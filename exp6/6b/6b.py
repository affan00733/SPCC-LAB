import sys
import csv


def main():
	prod={'E|E':'E','i':'E','E&E':'E'}
	non_terminals=['E']
	
	
	order_table = []
	with open('fandg.csv', 'r') as file2:
		order = csv.reader(file2)
		for row in order:
			order_table.append(row)
	
	operators = order_table[0] 

	print("\nNon-terminal : ",non_terminals,"\n")
	print("Terminal : ",operators,"\n")
	print("Production :- ")
	for key, value in prod.items(): 
		print(value,key)
	print("\n Operator presedence function table :- ")
	with open('fandg.csv', 'r') as file2:
		order = csv.reader(file2)
		for row in order:
			print(row)
	print("\n")
	# input_string = "i|i&i"
	input_string = input("Enter the input string : ")
	print("\n")
	input_ind = list(input_string)
	input_ind.append('$')


	# print( "order_table",order_table)
	stack = []

	stack.append('$') 
	
	
	print( "Stack", "\t\t\t\t", "Input", "\t\t\t\t","\t\t", "Action")
	
	flag = 1
	while flag:
		if input_ind[0] == '$' and len(stack)==2: #to check if string is accepted
			"""
				here string is accepted only when input string has only $ 
				and stack has only 2 element which is [$,"non-terminal"]
			"""
			flag = 0

		length = len(input_ind)
		# print(input_ind)
		buffer_inp = input_ind[0] #each time take first character of input string and stored in buffer input
		temp1 = operators.index(str(buffer_inp))  #taken index of buffer input for position of the function table in temp1
		# print ("stack",stack, stack[-1])
		if stack[-1] in non_terminals: 
			""" to check in our stack last element in stack is a non terminal or not if it 
				then taking previous element of stack which is operator and storing it in a buffer stack
			"""
			buffer_stack = stack[-2]
		else:
			buffer_stack = stack[-1]
			"""
				if last element in stack is not a non terminal then it ia operator 
				and storing it in a buffer stack
			"""
		temp2 = operators.index(str(buffer_stack)) #taken index of buffer stack for position of the function table in temp2
		# print ("buffer_stack",buffer_stack,"temp2",temp2,"temp1",temp1)
		# print(temp1,temp2)
		# print("buffer_stack",buffer_stack)
		f=order_table[1][temp2]
		"""
		from csv function table ,F column - with the corresponding operators index from stack's operator 
		- which is in the buffer stack
		"""
		g=order_table[2][temp1]
		"""
		from csv function table ,G column - with the corresponding operators index from input string 
		- which is in the buffer input string
		"""
		# precedence = order_table[temp2][temp1]
		# print(f,g) 
		action=""
		if f < g: #if f is less than g then shift operation
			action = 'shift'
		elif  f > g: #if f is greater than g then reduce operation
			action = 'reduce'
				
		print (stack, "\t\t", input_ind, "\t\t", "\t\t", action, "\n")
		
		if action == 'shift': 
			"""
				in shift operation from input string store it in stack 
				and remove it from input string buffer
			"""
			stack.append(buffer_inp)
			input_ind.remove(buffer_inp)
		elif action == 'reduce':
			"""
			In the reduce operation first we are itreating the prod which has the production of our grammar
			"""
			for key, value in prod.items():
				var1 = ''.join(stack[-1:])
				var2 = ''.join(stack[-3:])
				"""
				IN THE OPERATOR PRECEDENCE PASING IN THE PRODUCTION THERE CAN BE A SINLE OR LENGTH OF 3 PRODUCTION
				3 - NON-TERMINAL OPERATOR NON-TERMINAL

				so, var1 can stores the single production 
				and var2 can stores thr set of 3 production
				"""
				if str(key) == str(buffer_stack):
					stack[-1] = value
					break
				elif key == var1 or stack[-3:]==list(var1):
					stack[-3:] = value
					break
					"""
				To check if var1 that is the single production is in the prod which is the production list
				Then replace it with its production value -> non-terminal
					"""
				elif key == var2:
					stack[-3:] = value	
					"""
				To check if var2 that is the 3 production is in the prod which is the production list
				Then replace it with its production value -> non-terminal
					"""
		del buffer_inp, temp1, buffer_stack, temp2
		"""
		Emptying the buffer stack and input string and temp1 and temp2 which is the position
		for the function table -> so we can use in the next iteration of the input string
		"""
		
		if flag == 0: # flag is set to 0 means string accepted 
			print( "Accepted!!")
		
	return 2
	
if __name__ == "__main__":
	main()
