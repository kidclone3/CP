# source: https://www.geeksforgeeks.org/converting-epsilon-nfa-to-dfa-using-python-and-graphviz/

import json
from typing import KeysView, List, Dict

from graphviz import Digraph


class NFA:
    def __init__(self, json_file):
        states = json_file["states"]
        alphabets = json_file["alphabets"]
        start = json_file["start"]
        finals = json_file["finals"]
        transitions = json_file["transitions"]
        self.setup(states = states, alphabets=alphabets, start=start, finals=finals, transitions=transitions)

    def setup(
        self, states: List, alphabets: List, start: int, finals: List, transitions: List
    ) -> None:
        self.states = states
        self.no_state = len(states)

        self.alphabets = alphabets
        # Add epsilon as alphabet.
        self.alphabets.append("e")
        self.no_alphabet = len(alphabets)

        self.start = start

        self.finals = finals
        self.no_final = len(finals)

        self.transitions = transitions
        self.no_transition = len(transitions)

        self.graph = Digraph()

        # Use dict to get index of states
        self.states_dict = dict()
        # Indexing for each state
        for i, state in enumerate(self.states):
            self.states_dict[state] = i

        # Use dict to get index of alphabets
        self.alphabets_dict = dict()
        # Indexing for each alphabet
        for i, alphabet in enumerate(self.alphabets):
            self.alphabets_dict[alphabet] = i

        # transition table is of the form:
        # [From state + Alphabet] -> [Set of To States]
        self.transition_table: dict = dict()
        for i in range(self.no_state):
            for j in range(self.no_alphabet):
                self.transition_table[str(i) + str(j)] = list()
                
        # Just combine state with alphabet -> new state (instead of using 2d table)
        for i in range(self.no_transition):
            self.transition_table[
                str(self.states_dict[self.transitions[i][0]])
                + str(self.alphabets_dict[self.transitions[i][1]])
            ].append(self.states_dict[self.transitions[i][2]])

    # Method to represent quintuple
    def __repr__(self):
        return (
            "S : "
            + str(self.states)
            + "\nΣ : "
            + str(self.alphabets)
            + "\nS0 : "
            + str(self.start)
            + "\nδ : \n"
            + str(self.transition_table)
            + "\nF : "
            + str(self.finals)
        )

    def get_epsilon_closure(self, state) -> KeysView:
        '''
            Method to get Epsilon Closure of a state of NFA.
            Make a dictionary to track if state is visited or not
            And an array as stack to get the state to visit next
            Return:
                List of closure state indexes 
        '''
        # closure = defaultdict(int) # default every state is not visited ~ 0
        closure = dict()
        closure[self.states_dict[state]] = 0
        closure_stack = [self.states_dict[state]]

        while len(closure_stack) > 0:

            # Get the top of stack.
            current = closure_stack.pop(0)

            # For the epsilon transition of that state,
            # if not present in closure array then add to dict
            # and add to stack
            for x in self.transition_table[str(current) + str(self.alphabets_dict['e'])]:
                if x not in closure.keys(): # if not visited
                    closure[x] = 0
                    closure_stack.append(x)
            closure[current] = 1 # Mark as visited
        return closure.keys()

    def get_state_name(self, state_list) -> str:
        '''
            Get name from set of states to display in graph
        '''

        name = ''
        for x in state_list:
            name += self.states[x]
        return name

    def is_final_DFA(self, state_list):
        '''
            Check if the set of state is final state in DFA
            just by checking if any of the set is final state in NFA
        '''
        for x in state_list:
            for y in self.finals:
                if x == self.states_dict[y]:
                    return True
        return False

if __name__ == '__main__':
    f = open("2.json", "r")
    nfa_data = json.load(f)
    nfa = NFA(nfa_data)
    print(nfa.__repr__)

    # Adding states/nodes in NFA diagram
    for x in nfa.states:
        # If state is not a final state, then border shape is single circle
        # Else it is double circle
        if (x not in nfa.finals):
            nfa.graph.attr('node', shape='circle')
            nfa.graph.node(x)
        else:
            nfa.graph.attr('node', shape='doublecircle')
            nfa.graph.node(x)

    # Adding start state arrow in NFA diagram
    nfa.graph.attr('node', shape='none')
    nfa.graph.node('')
    nfa.graph.edge('', nfa.start)

    # Adding edge between states in NFA from transitions
    for x in nfa.transitions:
        nfa.graph.edge(x[0], x[2], label=('ε', x[1])[x[1] != 'e'])
    # nfa.graph.render('nfa', view=True)

    dfa = Digraph()
    # dfa_transition = dict() # To save state to state value in dfa

    epsilon_closure = dict() # Same with nfa.epsilon_closure

    for x in nfa.states:
        epsilon_closure[x] = list(nfa.get_epsilon_closure(x))
    # print(epsilon_closure, "!") 
    # First state of DFA will be epsilon closure of start state of NFA
    # Using stack to maintain till when to evaluate the states
    dfa_stack = list()
    dfa_stack.append(epsilon_closure[nfa.start])

    # check if start state is the final state in dfa
    if nfa.is_final_DFA(dfa_stack[0]):
        dfa.attr('node', shape = 'doublecircle')
    else:
        dfa.attr('node', shape = 'circle')

    dfa.node(nfa.get_state_name(dfa_stack[0]))

    # Adding start state arrow to start state in DFA
    dfa.attr('node', shape='none')
    dfa.node('')
    dfa.edge('', nfa.get_state_name(dfa_stack[0]))
    
    # List to store the states of DFA
    dfa_states = list()
    dfa_states.append(epsilon_closure[nfa.start])
    # print(dfa_states, "!")
    while len(dfa_stack) > 0:
        # getting the top
        current_state = dfa_stack.pop(0)

        # Traversing through all the alphabets for evaluating transitions in DFA
        for idx_alphabet in range(nfa.no_alphabet - 1):
            # Set to see if the epsilon closure of the set is empty or not
            from_closure = set()

            for x in current_state:
                # Union update and adding all the new states in set
                from_closure.update(set(nfa.transition_table[str(x) + str(idx_alphabet)]))

            if len(from_closure) > 0:
                # Set the to state set in DFA
                to_state = set()
                for x in list(from_closure):
                    to_state.update(set(epsilon_closure[nfa.states[x]]))
                
                # Check if the state already exists in DFA and if not then add it
                if list(to_state) not in dfa_states:
                    dfa_stack.append(list(to_state))
                    dfa_states.append(list(to_state))

                    # Check if this set contains final state of NFA
                    # to get if this set will be final state in DFA
                if nfa.is_final_DFA(list(to_state)):
                    dfa.attr('node', shape='doublecircle')
                else:
                    dfa.attr('node', shape='circle')
                dfa.node(nfa.get_state_name(list(to_state)))

                # Adding edge between from state and to state
                dfa.edge(nfa.get_state_name(current_state),
                        nfa.get_state_name(list(to_state)),
                        label=nfa.alphabets[idx_alphabet])
            # Else case for empty epsilon closure
            # This is a dead state(ϕ) in DFA
            else:
                # Check if any dead state was present before this
                # if not then make a new dead state ϕ
                if (-1) not in dfa_states:
                    dfa.attr('node', shape='circle')
                    dfa.node('ϕ')

                    # For new dead state, add all transitions to itself,
                    # so that machine cannot leave the dead state
                    for alpha in range(nfa.no_alphabet - 1):
                        dfa.edge('ϕ', 'ϕ', nfa.alphabets[alpha])

                    # Adding -1 to list to mark that dead state is present
                    dfa_states.append(-1)
                # Adding transition to dead state
                dfa.edge(nfa.get_state_name(current_state,),
                     'ϕ', label = nfa.alphabets[idx_alphabet])
    print(dfa_states)
    for state in dfa_states:
        if isinstance(state, list):
            ans = nfa.get_state_name(state)
        print(ans)
    dfa.render('dfa', view=True)