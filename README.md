# Checker

The program receives intergers, 
Programme qui reçoit sur l'entrée standards les nombres les placer dans la pile A. Va lire les commandes reçus sur la sortie standard puis les effectuer. A la fin aprés un CTRL + D va vérifier si la pile A est trier. Si c'est le cas checker écris sur la sortie standard "OK" sinon "Error".

# Push_swap

The aim of the project is to sort a set of integers using two stacks and the following instructions :

| Code | Instruction | Action |
| ------------- |:----------------| :-----|
| sa |	swap a |	swaps the 2 top elements of stack a |
| sb |	swap b |	swaps the 2 top elements of stack b |
| ss |	swap a + swap b |	both sa and sb |
| pa |	push a |	moves the top element of stack b at the top of stack a |
| pb |	push b |	moves the top element of stack a at the top of stack b |
| ra |	rotate a |	shifts all elements of stack a from bottom to top |
| rb |	rotate b |	shifts all elements of stack b from bottom to top |
| rr |	rotate a + rotate b |	both ra and rb |
| rra |	reverse rotate a |	shifts all elements of stack a from top to bottom |
| rrb |	reverse rotate b |	shifts all elements of stack b from top to bottom |
| rrr |	reverse rotate a + reverse rotate b |	both rra and rrb |

# Compiling and running ./checker

`make && ./checker -v 1 9 8 4 7`

Live visualisator, try it using the instructions. To check if the list is sorted ctrl + D.

# Compiling and running ./push_swap

`make && ./push_swap `ruby -e "print((1..20).to_a.shuffle.join(' '))";`

