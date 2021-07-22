# Divde and Conquer VS. Backtracking
# --------------------------------------------------------------------------------------
# (1) Often the case, the divide-and-conquer problem has a sole solution, while the 
# backtracking problem has unknown number of solutions. For example, when we 
# apply the merge sort algorithm to sort a list, we obtain a single sorted list, 
# while there are many solutions to place the queens for the N-queen problem.

# (2) Each step in the divide-and-conquer problem is indispensable to build the final 
# solution, while many steps in backtracking problem might not be useful to build the 
# solution, but serve as atttempts to search for the potential solutions. For example, 
# each step in the merge sort algorithm, i.e. divide, conquer and combine, are all 
# indispensable to build the final solution, while there are many trials and errors 
# during the process of building solutions for the N-queen problem.

# (3) When building the solution in the divide-and-conquer algorithm, we have a clear 
# and predefined path, though there might be several different manners to build the path. 
# While in the backtracking problems, one does not know in advance the exact path to the 
# solution. For example, in the top-down merge sort algorithm, we first recursively divide 
# the problems into two subproblems and then combine the solutions of these subproblems. 
# The steps are clearly defined and the number of steps is fixed as well. While in the 
# N-queen problem, if we know exactly where to place the queens, it would only take N steps 
# to do so. When applying the backtracking algorithm to the N-queen problem, we try 
# many candidates and many of them do not eventually lead to a solution but abandoned 
# at the end. As a result, we do not know beforehand how many steps exactly it would 
# take to build a valid solution.

def divide_and_conquer( S ):
    # (1). Divide the problem into a set of subproblems.
    [S1, S2, ... Sn] = divide(S)

    # (2). Solve the subproblem recursively,
    #   obtain the results of subproblems as [R1, R2... Rn].
    rets = [divide_and_conquer(Si) for Si in [S1, S2, ... Sn]]
    [R1, R2,... Rn] = rets

    # (3). combine the results from the subproblems.
    #   and return the combined result.
    return combine([R1, R2,... Rn])


# Or ...
def devide_conquer(problem, param1, param2, ...):

    # recursion terminator
    if problem is None:
        print_result
        return

    # prepare data
    data = prepare_data(problem)
    subproblems = split_problem(problem, data)

    # conquer subproblems
    subresult1 = self.devide_conquer(subproblem[0], p1, ...)
    subresult2 = self.devide_conquer(subproblem[1], p1, ...)
    subresult3 = self.devide_conquer(subproblem[2], p1, ...)
    ...

    # process and generate the final result
    result = process_result(subresult1, subresult2, subresult3, ...)
