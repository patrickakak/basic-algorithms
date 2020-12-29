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
   
