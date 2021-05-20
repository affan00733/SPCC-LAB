"""
Afaan Ansari
Roll no 16


table -> SLR parsing table
buf -> array of input string
SLR parser Stack is divided into two parts -->
    - state_stack - it has states of the stack
    - symbol_stack - it has the symbols of the stack
action_string -> it is the operation that is performed 
index -> pointer to traverse the buf
"""

def slr(G):

    # taking the input of the parsing table 
    table = [{'F': ['goto', 1], 'T': ['goto', 2], 'a': ['shift', 3], 'b': ['shift', 4], 'E': ['goto', 5]}, {'*': ['shift', 6], '$': ['reduce', 3], 'a': ['reduce', 3], '+': ['reduce', 3], 'b': ['reduce', 3]}, {'F': ['goto', 7], 'a': ['shift', 3], 'b': ['shift', 4], '$': ['reduce', 1], '+': ['reduce', 1]}, {'+': ['reduce', 5], '*': ['reduce', 5], '$': ['reduce', 5], 'a': ['reduce', 5], 'b': ['reduce', 5]}, {'+': ['reduce', 6], '*': ['reduce', 6],'$': ['reduce', 6], 'a': ['reduce', 6], 'b': ['reduce', 6]}, {'+': ['shift', 8]}, {'+': ['reduce', 4], '*': ['reduce', 4], '$': ['reduce', 4], 'a': ['reduce', 4], 'b': ['reduce', 4]}, {'*': ['shift', 6], '$': ['reduce', 2], 'a': ['reduce', 2], '+': ['reduce', 2], 'b': ['reduce', 2]}, {'F': ['goto', 1], 'T': ['goto', 9], 'a': ['shift', 3], 'b': ['shift', 4]}, {'F': ['goto', 7], 'a': ['shift', 3], 'b': ['shift', 4], '$': ['accept', 9]}]
    # print(table)
    for x in table:
        print(x)

    def parser(input_string):
        buf = list(input_string)
        buf.append('$')
        state_stack = [0]
        symbol_stack = []
        action_string = ""
        index = 0

        while True:
            symbol = buf[index]
            # symbol -> in this we storing the symbol of input string
            s = state_stack[-1]
            #s-> taking the last value of state from state_stack
            if symbol not in table[s]:
                #checking if symbol is present in table or not if not return error
                action_string = "Parsing error at " + \
                    str(index) + " symbol " + symbol
                print(action_string)
                break
            (action, value) = table[s][symbol]
            # from the table getting the action value like (S6) by corresponding state and symbol
            if action == 'shift':
                action_string = "Shift " + symbol
                symbol_stack.append(symbol)
                state_stack.append(value)
                # from the table adding the symbol and state to their corresponding stack
                index += 1
                #incrementing the index which is the pointer to traverse the buf

            if action == 'reduce':
                (lhsp, rhsp) = G[value]
                # the data we retrived from table action and value . then from the value getting the productions 
                # and spliting the production in left hand side (lhsp) and right hand side (rhsp)
                for i in range(len(rhsp)):
                    state_stack.pop()
                    symbol_stack.pop()
                #now here in reduce first we need to remove the elements from stack i.e state and symbol
                s = state_stack[-1]
                # as stacks are updated we need to take the updated value of s 
                #s-> taking the last value of state from state_stack
                state_stack.append(table[s][lhsp][1])
                #now we are taking the state value from the table and add it in state stack
                #the state value is take by table corresponding state and production non-terminal
                #programitacally it is the lhsp of the production which we have taken
                symbol_stack.append(lhsp)
                #now we are adding that production non-terminal to the symbol_stack which is lhsp
                action_string = "Reduce " + lhsp + " -> " + rhsp

            if action == 'accept':
                action_string = "Accepted :)"
                print(action_string)
                break

            print(''.join(symbol_stack),'\t', action_string)

    return parser

#the grammar production that we are using for SLR parsing
grammar = [
    ["E", "E+T"],
    ["E", "T"],
    ["T", "TF"],
    ["T", "F"],
    ["F", "F*"],
    ["F", "a"],
    ["F", "b"]
]


# passing the input string 
slr = slr(grammar)
slr("*a*")